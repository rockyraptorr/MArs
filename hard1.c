#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 100 // Define the size of the grid
#define OBSTACLE_COUNT 100 // Adjust based on input file

// Struct to store obstacle positions
typedef struct {
    int north;
    int east;
    int south;
    int west;
} Obstacle;

Obstacle obstacles[OBSTACLE_COUNT]; // Array to store obstacles
int obstacleCount = 0; // Number of obstacles loaded

// Function to read obstacles from a file
void loadObstacles(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file!\n");
        exit(1);
    }

    while (fscanf(file, "%d %d %d %d",
                  &obstacles[obstacleCount].north,
                  &obstacles[obstacleCount].east,
                  &obstacles[obstacleCount].south,
                  &obstacles[obstacleCount].west) == 4) {
        obstacleCount++;
        if (obstacleCount >= OBSTACLE_COUNT) break;
    }

    fclose(file);
}

// Function to check if a position is an obstacle
int isObstacle(int x, int y) {
    for (int i = 0; i < obstacleCount; i++) {
        if ((obstacles[i].north == x && obstacles[i].east == y) ||
            (obstacles[i].south == x && obstacles[i].west == y)) {
            return 1; // Position is blocked
        }
    }
    return 0;
}

// Function to move the rover
void moveRover(int startX, int startY, int targetX, int targetY) {
    int x = startX, y = startY;

    printf("Starting position: (%d, %d)\n", x, y);

    while (x != targetX || y != targetY) {
        // Try moving East if possible
        if (x < targetX && !isObstacle(x + 1, y)) {
            x++;
        }
        // Try moving North if possible
        else if (y < targetY && !isObstacle(x, y + 1)) {
            y++;
        }
        // Try moving West if needed
        else if (x > targetX && !isObstacle(x - 1, y)) {
            x--;
        }
        // Try moving South if needed
        else if (y > targetY && !isObstacle(x, y - 1)) {
            y--;
        }
        // If no valid move is found, stop
        else {
            printf("Rover is stuck at (%d, %d)! Obstacle detected.\n", x, y);
            return;
        }

        printf("Rover moved to: (%d, %d)\n", x, y);
    }

    printf("Rover reached the destination: (%d, %d)\n", targetX, targetY);
}

// Main function
int main() {
    loadObstacles("obstacles.txt"); // Load obstacles from file
    int startX = 0, startY = 0;
    int targetX = 10, targetY = 10; // Define the target position

    moveRover(startX, startY, targetX, targetY); // Move the rover

    return 0;
}