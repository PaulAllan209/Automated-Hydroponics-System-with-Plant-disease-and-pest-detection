# from modules import communication
import os
# from modules import gantry_robot
from cv2 import VideoCapture, imshow, imwrite, waitKey, destroyWindow
from datetime import datetime
import serial
import time

# ArduinoComms = communication.ArduinoMegaCommunication()

# data = {
#     # 18 values sent
#     "base_peris_pump":2,
#     "acid_peris_pump":2,
#     "nutriA_peris_pump":2,
#     "nutriB_peris_pump":2,
    
#     "water_pump_speed":0.5,
    
#     "peltier_state":1,
#     "peltier_mode":"C",
    
#     "linear_act":1,
    
#     "grow_light_1":1,
#     "grow_light_2":1,
    
#     "air_pump":1,
    
#     "exhaust_fan_1":1,
#     "exhaust_fan_2":1,
    
#     "solenoid":0,
    
#     "step_x":200,
#     "step_y":200,
#     "step_z1":200,
#     "step_z2":200
# }

# data2 = "<100,576>"

# # ArduinoComms.send_raw_data(data2)

# ArduinoComms.send_data(data)
# print(len(data))


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

# Lets say this is the image file
def captureimg(filename_path, plant_num):
    
    # program to capture single image from webcam in python 
    
    # importing OpenCV library 
    
    # initialize the camera 
    # If you have multiple camera connected with  
    # current device, assign a value in cam_port  
    # variable according to that 
    cam_port = 0
    cam = VideoCapture(cam_port) 
    
    # reading the input using the camera 
    result, image = cam.read() 
    
    # If image will detected without any error,  
    # show result 
    if result: 
        ret, frame = cam.read()
        # Save the captured image to a file
        image_filename = f"{filename_path}\{plant_num}"
        imwrite(image_filename, frame)
        print(f"Image saved as {image_filename}")
    
    # If captured image is corrupted, moving to else part 
    else: 
        print("No image detected. Please! try again")
        
        # Read a frame from the webcam


    
    
# tester code for saving images
directory_folder = r"C:\Users\dpaul\Desktop\Electrical engineering files\4rth year\2nd sem\Research Project Capstone"
name_source_folder = create_directory_structure(directory_folder)

whole_dir_src_fol = os.path.join(directory_folder, name_source_folder)
captureimg(whole_dir_src_fol, "plant_1.png")


# function for communicating with arduino mega
# sends command to arduino mega to begin moving the robot
# read serial check if it is on plant 1 
# captures image
# sends to serial "next"
# until last plant the robot will return to home position

def capture_all_plants():
    serial_port = serial.Serial(port='COM3', baudrate=9600, rtscts=True) #/dev/ttyUSB0
    plant_num = 1
    start_command = "s"
    next_command = "n"
    serial_port.write(start_command.encode('utf-8'))
    
    while plant_num != 9:
        while True:
            if serial_port.in_waiting > 0:
                msg = serial_port.read().decode('utf-8')
                print(msg)
                if msg == f"plant_1":
                    captureimg(whole_dir_src_fol, f"plant_{plant_num}.png")
                    serial_port.write(next_command.encode('utf-8'))
                    plant_num=+1
                    break 
                else:
                    time.sleep(0.1)
                    
    if plant_num == 9:
        while True:
            if serial_port.in_waiting > 0:
                if serial_port.read().decode('utf-8') == f"plant_{plant_num}":
                    captureimg(whole_dir_src_fol, f"plant_{plant_num}.png")
                    serial_port.write(next_command.encode('utf-8'))
                    break 
                else:
                    time.sleep(0.1)

capture_all_plants()
    
        
    
