import serial
import time

ser = serial.Serial(port='/dev/ttyUSB0', baudrate=9600, rtscts=True)

# 114 - capture plants
# 115 - next plant state
# 116 - return home position

# delay for each plant interval
del_plant = 10

# Sends command to mega to start the capture of plants
ser.write(b"<114,1>")

# Sends command to return to home position
ser.write(b"<116,1>") # dont add spaces in commands
# Wait 40s
time.sleep(40)

# Sends command to turn off home position
ser.write(b"<116,0>")

# Sends command to go to plant 1
ser.write(b"<115, 1>")
# Wait 35s
time.sleep(35)

# Sends command to go to plant 2
ser.write(b"<115, 2>")
# Wait 10s
time.sleep(10)


