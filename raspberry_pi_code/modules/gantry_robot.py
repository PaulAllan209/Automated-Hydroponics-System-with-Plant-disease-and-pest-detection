import os
from datetime import datetime
# Maybe create a class for the gantry robot system that also has the methods for the picture system
# This python file will be run single time and the gantry robot system will move to take pictures each of the plants

# Variables for the position each of the plants (debug this and test the positions)
plant1 = [1, 2, 3]
plant2 = []
plant3 = []
plant4 = []
plant5 = []
plant6 = []
plant7 = []
plant8 = []
plant9 = []
plant10 = []


# Function for sending the position for the plants

# Funciton for receiving the current position and comparing if it already matches the plant position

# Function for the esp32 cam to take pictures

# Function for creation of directory


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