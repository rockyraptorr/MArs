#include <stdio.h>
#include <math.h>

// Function to convert degrees to radians
double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// Function to convert Euler angles (yaw, pitch, roll) to Quaternions
void eulerToQuaternion(double yaw, double pitch, double roll, double *q_w, double *q_x, double *q_y, double *q_z) {
    // Convert angles to radians
    double cy = cos(toRadians(yaw) / 2);
    double sy = sin(toRadians(yaw) / 2);
    double cp = cos(toRadians(pitch) / 2);
    double sp = sin(toRadians(pitch) / 2);
    double cr = cos(toRadians(roll) / 2);
    double sr = sin(toRadians(roll) / 2);

    // Compute quaternion values
    *q_w = cy * cp * cr + sy * sp * sr;
    *q_x = sy * cp * cr - cy * sp * sr;
    *q_y = cy * sp * cr + sy * cp * sr;
    *q_z = cy * cp * sr - sy * sp * cr;
}

int main() {
    double yaw, pitch, roll;
    double q_w, q_x, q_y, q_z;

    // Input Euler angles (in degrees)
    printf("Enter Yaw (Z-axis rotation): ");
    scanf("%lf", &yaw);
    printf("Enter Pitch (Y-axis rotation): ");
    scanf("%lf", &pitch);
    printf("Enter Roll (X-axis rotation): ");
    scanf("%lf", &roll);

    // Convert to Quaternion
    eulerToQuaternion(yaw, pitch, roll, &q_w, &q_x, &q_y, &q_z);

    // Output Quaternion representation
    printf("\nQuaternion Representation (w, x, y, z):\n");
    printf("%.6lf, %.6lf, %.6lf, %.6lf\n", q_w, q_x, q_y, q_z);

    return 0;
}

