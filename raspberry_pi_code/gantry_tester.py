import serial

ser = serial.Serial(port='/dev/ttyUSB0', baudrate=9600, rtscts=True)


# Sends command to mega to start the capture of plants
ser.write(b"<114,1>")

# receives message if the gantry is in home position
while True:
    bytes_waiting = ser.in_waiting()
    if bytes_waiting > 0:
        data_str = ser.readline().decode('ascii').strip()
        
        if data_str == 'at_home':
            ser.write(b"<115, 1>")
        
        if data_str == "plant_2":
            ser.write(b"<115, 2>")
        
        



# Go to plant 1
# Wait until it is on plant 1

# If it is on plant 1 go to plant 2

#Repeat until plant 10