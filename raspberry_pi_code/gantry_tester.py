import serial
import time

ser = serial.Serial(port='/dev/ttyUSB0', baudrate=9600)

# 114 - capture plants
# 115 - next plant state
# 116 - return home position

# delay for each plant interval
del_plant = 10

ser.write(b"<117,1>")
time.sleep(1)

# Sends command to mega to start the capture of plants
ser.write(b"<114,1>")

# Sends command to return to home position
ser.write(b"<116,1>") # dont add spaces in commands
# Wait 40s
time.sleep(40)

# Sends command to turn off home position
ser.write(b"<116,0>")

# Sends command to go to plant 1
ser.write(b"<115,1>")
# Wait 35s
time.sleep(35)

# Sends command to go to plant 2
ser.write(b"<115,2>")
# Wait 10s
time.sleep(del_plant)

ser.write(b"<115,3>")
time.sleep(del_plant)

ser.write(b"<115,4>")
time.sleep(del_plant)

ser.write(b"<115,5>")
time.sleep(del_plant)

ser.write(b"<115,6>")
time.sleep(del_plant)

ser.write(b"<115,7>")
time.sleep(del_plant)

ser.write(b"<115,8>")
time.sleep(del_plant)

ser.write(b"<115,9>")
time.sleep(del_plant)

ser.write(b"<115,10>")
time.sleep(del_plant)

ser.write(b"<115,0>")
time.sleep(1)

ser.write(b"<116,1>")
time.sleep(40)

ser.write(b"<116,0>")
time.sleep(1)

ser.write(b"<114,0>")
time.sleep(1)

ser.write(b"<117,0>")

