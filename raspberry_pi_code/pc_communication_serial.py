import serial
ser = serial.Serial(port='COM3', baudrate=9600)

while True:
    bytes_waiting = ser.in_waiting
    if bytes_waiting > 0:
        data_str = str(ser.readline().decode('ascii').strip())
        
        print(data_str)
        if data_str == "wow":
            print('kek')
            