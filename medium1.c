#include <stdio.h>
#include <math.h>

// Function to compute the new marker position
void adjust_marker_position(float x, float y, float z, float camera_offset, float *x_final, float *y_final, float *z_final) {
    *x_final = x;
    *y_final = y;
    *z_final = z + camera_offset;  // Adjusting for the offset
}

// Function to calculate the distance between marker and camera
float compute_distance(float x, float y, float z) {
    return sqrt(x * x + y * y + z * z);
}

int main() {
    float x, y, z = -60; // Given marker coordinates in the old reference frame
    float camera_offset = 55; // Offset to be adjusted
    float x_final, y_final, z_final;

    // Input the detected marker coordinates
    printf("Enter marker coordinates (x y): ");
    scanf("%f %f", &x, &y);

    // Compute the initial distance
    float initial_distance = compute_distance(x, y, z);

    // Adjust the marker position
    adjust_marker_position(x, y, z, camera_offset, &x_final, &y_final, &z_final);

    // Compute the final distance
    float final_distance = compute_distance(x_final, y_final, z_final);

    // Output the adjusted marker position
    printf("New Marker Position: (%.2f, %.2f, %.2f)\n", x_final, y_final, z_final);
    printf("Distance before adjustment: %.2f cm\n", initial_distance);
    printf("Distance after adjustment: %.2f cm\n", final_distance);

    return 0;
}