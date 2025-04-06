# MArs
## Q1.
I learned how to use basic Linux commands to manage files, view system information, and perform tasks like renaming files, searching for content, and scheduling a shutdown. It helped me understand practical commands such as mkdir, touch, mv, grep, top, and shutdown. My approach was to try each command step-by-step, using online resources and man pages when I needed help with syntax or options. Some difficulties I faced included remembering correct flags and interpreting outputs from commands like top. Despite minor challenges, this task improved my confidence and efficiency in using the Linux terminal for day-to-day operations.

## Q2.
When working on the Bash script for the rover system check, I broke the task into smaller steps: generating a random battery percentage, checking if it’s below a threshold, testing network connectivity with ⁠ ping ⁠, and logging messages accordingly. The main challenges were understanding Bash syntax, handling exit statuses, and managing edge cases like boundary values. To tackle these, I developed the script step-by-step, testing each part and using ⁠ echo ⁠ for debugging. With more practice, I got more comfortable with Bash scripting and handling its nuances.

## Q3.
I adjusted the rover’s position by shifting the x-coordinate to account for the camera's 55 cm offset, ensuring it aligns with the marker. The main challenge was understanding the impact of the camera's offset on navigation and correctly calculating the new position. With some adjustments, I resolved the issue and ensured accurate positioning for the 360-degree turn.

## Q4.
In this task involved using a dictionary for Morse code translation and splitting the input to handle word boundaries. The main challenge was managing the word separation with spaces and handling the translation efficiently. The process was straightforward once I understood how to map Morse code to letters and apply basic string manipulation techniques like split() and join().  Q5.
In solving this, I used basic string manipulation and ASCII operations (ord and chr). The main challenge was correctly applying the reverse shift and ensuring the alphabet wrapped around when going past 'A'. By using modulo 26, I ensured that the shifting was circular and handled edge cases where the letters shifted back before 'A'. The process was clear once I understood the encryption pattern and how to reverse it systematically

## Q6.
In this task, I learned how to apply different filters for noise reduction in sensor data and evaluate their effectiveness by calculating variance. The key challenge was implementing the sliding window technique for both the moving average and median filters, and correctly combining them in the hybrid filter. Calculating stability using variance helped in objectively selecting the best filter. The task required understanding of basic signal processing techniques like moving averages and medians, as well as performance evaluation of filters.

## Q7.
The key learning was understanding how quaternions represent 3D rotations and how they avoid the issues of gimbal lock that can arise with Euler angles. The approach was straightforward once I understood the conversion formula. The main difficulty was remembering the correct formula for converting Euler angles to quaternions and ensuring that angles were correctly converted to radians. The resulting quaternion can then be used in 3D graphics or robotic applications to represent rotations without suffering from gimbal lock.
1. Convert Euler Angles (Roll, Pitch, Yaw) to Quaternion:

Given the Euler angles:
	•	Roll (ϕ): Rotation about the x-axis
	•	Pitch (θ): Rotation about the y-axis
	•	Yaw (ψ): Rotation about the z-axis

The quaternion components can be computed as:

q₀ = cos(ϕ/2) * cos(θ/2) * cos(ψ/2) + sin(ϕ/2) * sin(θ/2) * sin(ψ/2)

q₁ = sin(ϕ/2) * cos(θ/2) * cos(ψ/2) - cos(ϕ/2) * sin(θ/2) * sin(ψ/2)

q₂ = cos(ϕ/2) * sin(θ/2) * cos(ψ/2) + sin(ϕ/2) * cos(θ/2) * sin(ψ/2)

q₃ = cos(ϕ/2) * cos(θ/2) * sin(ψ/2) - sin(ϕ/2) * sin(θ/2) * cos(ψ/2)

Where:
	•	ϕ is the roll angle
	•	θ is the pitch angle
	•	ψ is the yaw angle

These equations convert Euler angles (roll, pitch, yaw) into a quaternion q = (q₀, q₁, q₂, q₃).



## Q8.
I Learned how to represent a 2D arena grid and use BFS for finding the shortest path while avoiding obstacles. The main challenge was correctly parsing the obstacle data from the .txt file and mapping it to the grid, while also managing boundaries. Debugging BFS to avoid revisiting positions and obstacles was tricky, but overall, it was a good exercise in pathfinding and grid management 

## Q9.
I learned how to apply computer vision techniques for detecting objects and calculating distances using the pinhole camera model. My approach involved processing the image, detecting the arrow, and applying a formula to estimate the distance based on the camera specifications. A challenge was correctly calculating the focal length and ensuring accurate measurements of the perceived width. Debugging contour detection and handling image processing steps was tricky at times. Overall, it was a great exercise in image analysis and real-world application of the pinhole camera model.


Formulas:
Distance = (Real arrow width * Focal Length) / Percieved arrow width
f=w/(2* tan(FOV/2))




## Q10. 
In this task, we learned how to use Behavior Trees (BT) to model decision-making for a Mars rover. The approach involved understanding the difference between Sequence and Fallback nodes, where the Sequence node executes tasks one by one, and the Fallback node tries tasks until one succeeds. We applied these principles to design a BT for battery checks and navigation. The Fallback node, in particular, allows the rover to prioritize actions, such as returning to base when the battery is critically low, or conserving power when it’s low but not critical. This structure avoids the complexity of long if-else conditions and makes the decision-making process more modular and flexible. The main challenges included visualizing and structuring the BT logic, ensuring the correct flow of tasks, and understanding how to balance between flexibility and robustness in decision-making. Ultimately, this approach results in more scalable and maintainable rover control systems.


