import cv2
import os
import time
from datetime import datetime

def capture_and_save_image(output_dir, name_number):
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
    image_filename = os.path.join(output_dir, f'plant_{name_number}.jpg')
    cv2.imwrite(image_filename, frame)
    print(f"Image saved as {image_filename}")

    # Release the camera
    cap.release()
    
def create_directory_structure(directory):
    # Get current date and time
    current_date = datetime.now().strftime('%Y-%m-%d')
    current_time = datetime.now().strftime('%H-%M-%S')
    date_directory = os.path.join(directory, current_date)
    time_directory = os.path.join(date_directory, current_time)
    
    # List all day directories
    day_list = os.listdir(directory)
    # Create the day directory if it exists it wont create one
    os.makedirs(date_directory, exist_ok=True)
        
    # List all time directories
    time_list = os.listdir(date_directory)
    # Create the time directory if it exists it wont create one
    os.makedirs(time_directory, exist_ok=True)

    print(f"Directory structure created: {time_directory}")
    
    # Return directory path
    return time_directory

dir_img = create_directory_structure(r"C:\Users\dpaul\Desktop\Automated-Hydroponics-System-with-Plant-disease-and-pest-detection\dir_tester")

capture_and_save_image(dir_img, 1)
