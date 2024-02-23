import serial
from time import sleep

arduino_mega_ser = serial.Serial('COM5', 9600, xonxoff=True)


def tester():
    return b"wowmagic"
    
    
    
while True:
    arduino_mega_ser.write(tester())
    sleep(1)
    
    