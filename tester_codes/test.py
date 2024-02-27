import serial

ser = serial.Serial('COM5', baudrate=9600)

ser.write(b'hello!!')