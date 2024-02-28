from pySerialTransfer import pySerialTransfer as txfer

class struct(object):
    x = 1
    y = 2
    z = 3
    


link = txfer.SerialTransfer('/dev/ttyUSB0')
link.open()

sendSize = 0


