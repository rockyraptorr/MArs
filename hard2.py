import cv2
import numpy as np
import math

# Webcam specs
REAL_ARROW_WIDTH = 17.0  # cm
FRAME_WIDTH = 1280  # pixels
FRAME_HEIGHT = 720  # pixels
DIAGONAL_FOV_DEG = 55  # degrees

# Compute focal length using pinhole camera model
def compute_focal_length():
    diagonal_resolution = math.hypot(FRAME_WIDTH, FRAME_HEIGHT)  # Pythagoras
    diagonal_fov_rad = math.radians(DIAGONAL_FOV_DEG)
    focal_length = (diagonal_resolution / 2) / math.tan(diagonal_fov_rad / 2)
    return focal_length

FOCAL_LENGTH_PIXELS = compute_focal_length()

def detect_arrow(image_path):
    image = cv2.imread(image_path)
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    blurred = cv2.GaussianBlur(gray, (5, 5), 0)
    edges = cv2.Canny(blurred, 50, 150)
    contours, _ = cv2.findContours(edges, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

    for cnt in contours:
        approx = cv2.approxPolyDP(cnt, 0.02 * cv2.arcLength(cnt, True), True)

        if len(approx) == 7:
            cv2.drawContours(image, [approx], 0, (0, 255, 0), 3)
            print("Arrow detected!")

            x, y, w, h = cv2.boundingRect(approx)
            perceived_width = max(w, h)

            distance = find_distance(perceived_width)
            print(f"Estimated Distance: {distance:.2f} cm")

    cv2.imshow('Detected Arrow', image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

def find_distance(perceived_width):
    if perceived_width == 0:
        return float('inf')  # Avoid division by zero
    return (FOCAL_LENGTH_PIXELS * REAL_ARROW_WIDTH) / perceived_width

# Test
image_path = 'arrow.jpg'
detect_arrow(image_path)