#include <stdio.h>
#include <stdlib.h>

#define MAX_READINGS 1000  // Define max sensor readings

// Function to apply the Muchiko filter (3-point moving average)
void applyMuchikoFilter(int *data, int *filtered, int n) {
    filtered[0] = data[0]; // First value remains the same
    for (int i = 1; i < n - 1; i++) {
        filtered[i] = (data[i - 1] + data[i] + data[i + 1]) / 3;
    }
    filtered[n - 1] = data[n - 1]; // Last value remains the same
}

// Function to find the median of 3 numbers
int median(int a, int b, int c) {
    if ((a >= b && a <= c) || (a >= c && a <= b)) return a;
    if ((b >= a && b <= c) || (b >= c && b <= a)) return b;
    return c;
}

// Function to apply the Sanchiko filter (3-point moving median)
void applySanchikoFilter(int *data, int *filtered, int n) {
    filtered[0] = data[0]; // First value remains the same
    for (int i = 1; i < n - 1; i++) {
        filtered[i] = median(data[i - 1], data[i], data[i + 1]);
    }
    filtered[n - 1] = data[n - 1]; // Last value remains the same
}

// Function to determine the best filter by computing deviation
double calculateDeviation(int *original, int *filtered, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(original[i] - filtered[i]);
    }
    return sum / n;  // Average deviation
}

int main() {
    int data[MAX_READINGS], muchiko[MAX_READINGS], sanchiko[MAX_READINGS];
    int count = 0;

    // Read sensor readings from log.txt
    FILE *file = fopen("log.txt", "r");
    if (!file) {
        printf("Error opening log.txt\n");
        return 1;
    }

    while (fscanf(file, "%d", &data[count]) != EOF && count < MAX_READINGS) {
        count++;
    }
    fclose(file);

    // Apply the filters
    applyMuchikoFilter(data, muchiko, count);
    applySanchikoFilter(data, sanchiko, count);

    // Compute deviations
    double muchikoDeviation = calculateDeviation(data, muchiko, count);
    double sanchikoDeviation = calculateDeviation(data, sanchiko, count);

    // Determine the best filter
    printf("Muchiko Deviation: %.2f\n", muchikoDeviation);
    printf("Sanchiko Deviation: %.2f\n", sanchikoDeviation);

    if (muchikoDeviation < sanchikoDeviation) {
        printf("Muchiko filter is better.\n");
    } else if (sanchikoDeviation < muchikoDeviation) {
        printf("Sanchiko filter is better.\n");
    } else {
        printf("Both filters perform equally well.\n");
    }

    return 0;
}


