import cv2
import os

def capture_and_save_image(output_dir):
    # Open a connection to the default camera (usually the first camera)
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        print("Error: Could not open video device.")
        return


    # Read a single frame
    ret, frame = cap.read()

    if not ret:
        print("Error: Could not read frame.")
        return

    # Ensure the output directory exists
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    # Save the captured image to a file in the specified directory
    image_filename = os.path.join(output_dir, 'captured_image.jpg')
    cv2.imwrite(image_filename, frame)
    print(f"Image saved as {image_filename}")

    # Release the camera
    cap.release()