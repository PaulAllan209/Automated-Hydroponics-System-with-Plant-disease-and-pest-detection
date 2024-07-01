"""
This code is integrated into one of the MyCodo outputs and is responsible 
for sending commands to the Arduino Mega to control the gantry robot's 
movements and capture images of the plants. Additionally, the code includes 
the machine learning component of the system and the functionality for 
sending email notifications.
"""

log_string = "ID: {id}: ON".format(id=output_id)
self.logger.info(log_string)

import serial
import time
import os
import cv2
from datetime import datetime

import tensorflow as tf
import os
from email.message import EmailMessage
import smtplib
import ssl

from ultralytics import YOLO

ser = serial.Serial(port='/dev/ttyUSB0', baudrate=9600)

# 114 - capture plants
# 115 - next plant state
# 116 - return home position

def initialize_camera(camera_index=0, warmup_time=5):
    # Initialize the camera
    cap = cv2.VideoCapture(camera_index)

    # Allow the camera to warm up for the specified time
    start_time = time.time()
    while (time.time() - start_time) < warmup_time:
        ret, frame = cap.read()
        if not ret:
            print("Failed to capture image")
            break

    return cap

def capture_and_save_image(output_dir, name_number, cap):
    # deletes a few frames from the camera
    for _ in range(10):
        ret, frame = cap.read()
        if not ret:
            print("Error: Could not read frame.")
            return

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

# for cropping image
def crop_image (img_path, startX, endX, startY, endY):
    image = cv2.imread(img_path)
    # Crop the image
    cropped_image = image[startY:endY, startX:endX]

    # Save the cropped image, overwriting the original file
    cv2.imwrite(img_path, cropped_image)

dir_path = create_directory_structure("/home/superpotatorpi/Desktop/images_captured")




cap = initialize_camera()
time.sleep(10)
# delay for each plant interval
del_plant = 15

# linear actuators on
ser.write(b"<107,1>")
time.sleep(15)

ser.write(b"<117,1>")
time.sleep(1)

# Sends command to mega to start the capture of plants
ser.write(b"<114,1>")

# Sends command to return to home position
ser.write(b"<116,1>") # dont add spaces in commands
# Wait 40s
time.sleep(15)

# Sends command to turn off home position
ser.write(b"<116,0>")

# Sends command to go to plant 1
ser.write(b"<115,1>")
# Wait 35s
time.sleep(35)
capture_and_save_image(dir_path, "01", cap)
time.sleep(3)

# Sends command to go to plant 2
ser.write(b"<115,2>")
# Wait 10s
time.sleep(del_plant)
capture_and_save_image(dir_path, "02", cap)
time.sleep(3)

ser.write(b"<115,3>")
time.sleep(del_plant)
capture_and_save_image(dir_path, "03", cap)
time.sleep(3)

ser.write(b"<115,4>")
time.sleep(del_plant)
capture_and_save_image(dir_path, "04", cap)
time.sleep(3)

ser.write(b"<115,5>")
time.sleep(del_plant)
capture_and_save_image(dir_path, "05", cap)
time.sleep(3)

ser.write(b"<115,6>")
time.sleep(del_plant)
capture_and_save_image(dir_path, "06", cap)
time.sleep(3)

ser.write(b"<115,7>")
time.sleep(del_plant)
capture_and_save_image(dir_path, "07", cap)
time.sleep(3)

ser.write(b"<115,8>")
time.sleep(del_plant)
capture_and_save_image(dir_path, "08", cap)
time.sleep(3)

ser.write(b"<115,9>")
time.sleep(del_plant)
capture_and_save_image(dir_path, "09", cap)
time.sleep(3)

ser.write(b"<115,10>")
time.sleep(del_plant)
capture_and_save_image(dir_path, "10", cap)
time.sleep(3)

ser.write(b"<115,0>")
time.sleep(1)

ser.write(b"<116,1>")
time.sleep(40)

ser.write(b"<116,0>")
time.sleep(1)

ser.write(b"<114,0>")
time.sleep(1)

ser.write(b"<117,0>")
time.sleep(1)

ser.write(b"<107,0>")

cap.release()

# Image cropping for eliminating some background
crop_image(os.path.join(dir_path, 'plant_01.jpg'), 0, 600, 0, 480)
crop_image(os.path.join(dir_path, 'plant_02.jpg'), 0, 600, 0, 480)
crop_image(os.path.join(dir_path, 'plant_03.jpg'), 0, 600, 0, 480)
crop_image(os.path.join(dir_path, 'plant_08.jpg'), 60, 640, 0, 480)
crop_image(os.path.join(dir_path, 'plant_09.jpg'), 20, 640, 0, 480)
crop_image(os.path.join(dir_path, 'plant_10.jpg'), 60, 640, 0, 480)

################################################################
'''
This part is for the disease detection
'''
################################################################

# Load model for disease detection
loaded_model = tf.keras.models.load_model(r"/home/superpotatorpi/Desktop/machine_learning_files/health_assessment_model.hdf5")
# Find latest folder for plants 
images_path = r"/home/superpotatorpi/Desktop/images_captured/"
list_files = os.listdir(images_path)
list_files.sort()

folder_1 = os.path.join(images_path, list_files[-1])
folder_1_list_files = os.listdir(folder_1)
folder_1_list_files.sort()
folder_2 = os.path.join(folder_1, folder_1_list_files[-1])
print(folder_2)

# Load the images
test_dataset = tf.keras.utils.image_dataset_from_directory(rf'{folder_2}', 
                                                           labels=None, shuffle=False, batch_size=1, image_size=(256,256))

pred = loaded_model.predict(test_dataset)
pred_adjusted = list(map(lambda x: 0 if x < 0.5 else 1, pred))
print(pred_adjusted)

# predicted list values
values = ['Healthy', 'Unhealthy']

################################################################
"""
This is for the pest detection system
"""
################################################################
# Load the model
model = YOLO(r"/home/superpotatorpi/Desktop/machine_learning_files/slugs_and_snails_detection.pt")

# Path to the folder containing images
image_path = dir_path
save_path = create_directory_structure(r"/home/superpotatorpi/Desktop/pest_detection_results")
images_to_attach = []

# Get list of all image paths
list_images = os.listdir(image_path)
list_path_images = [os.path.join(image_path, i) for i in list_images]

# Set confidence threshold
conf_threshold = 0.7

# Dictionary to store results
results_summary = {}

# Process each image and filter predictions
for image_path in list_path_images:
    results = model(image_path)
    
    image_name = os.path.basename(image_path)
    slugs_count = 0
    snails_count = 0

    for result in results:
        # Filter boxes by confidence
        filtered_boxes = [box for box in result.boxes if box.conf > conf_threshold]
        
        # Count occurrences of each label in filtered boxes
        for box in filtered_boxes:
            label = result.names[int(box.cls)]
            # print(result.names[int(box.cls)])
            if label == 'Slug':
                slugs_count += 1
            elif label == 'Snail':
                snails_count += 1
        
        # If there are filtered boxes, display them
        if filtered_boxes:
            result.boxes = filtered_boxes
            img = result.plot()
            
            # Save the image
            save_image_path = os.path.join(save_path, image_name)
            cv2.imwrite(save_image_path, img)
            # result.show()

    # Store the results for this image
    results_summary[image_name] = (slugs_count, snails_count)

# Print out the results summary
for image_name, counts in results_summary.items():
    print(f"{image_name} - Slugs:{counts[0]}, Snails:{counts[1]}")


################################################################
# Email part 
################################################################

email_sender = 'dpaulallan15@gmail.com'
email_password = 'shai majm tzag aybb'
email_receiver = 'dpaulallan14@gmail.com'
subject =  "Plant Health Assessment and Snails detection Results"
time_now = datetime.now().strftime("%Y-%m-%d %H:%M:%S")


body = f"""
These are the results for the Plant Health Assessment Snails detection on {time_now}.
Plant A - {values[pred_adjusted[0]]} | Snails:{results_summary["plant_01.jpg"][1]}
Plant B - {values[pred_adjusted[1]]} | Snails:{results_summary["plant_02.jpg"][1]}
Plant C - {values[pred_adjusted[2]]} | Snails:{results_summary["plant_03.jpg"][1]}
Plant D - {values[pred_adjusted[6]]} | Snails:{results_summary["plant_04.jpg"][1]}
Plant E - {values[pred_adjusted[5]]} | Snails:{results_summary["plant_05.jpg"][1]}
Plant F - {values[pred_adjusted[4]]} | Snails:{results_summary["plant_06.jpg"][1]}
Plant G - {values[pred_adjusted[3]]} | Snails:{results_summary["plant_07.jpg"][1]}
Plant H - {values[pred_adjusted[7]]} | Snails:{results_summary["plant_08.jpg"][1]}
Plant I - {values[pred_adjusted[8]]} | Snails:{results_summary["plant_09.jpg"][1]}
Plant J - {values[pred_adjusted[9]]} | Snails:{results_summary["plant_10.jpg"][1]}
"""

em = EmailMessage()
em['From'] = email_sender
em['To'] = email_receiver
em['Subject'] = subject
em.set_content(body)
context = ssl.create_default_context()

with smtplib.SMTP_SSL('smtp.gmail.com', 465, context=context) as smtp:
    smtp.login(email_sender, email_password)
    smtp.sendmail(email_sender, email_receiver, em.as_string())