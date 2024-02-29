# On command
import serial

ser = serial.Serial('/dev/ttyUSB0', baudrate=9600)

ser.write(b"<107,1>")

log_string = "ID: {id}: ON".format(id=output_id)
self.logger.info(log_string)


# Off command
import serial

ser = serial.Serial('/dev/ttyUSB0', baudrate=9600)

ser.write(b"<107,0>")

log_string = "ID: {id}: OFF".format(id=output_id)
self.logger.info(log_string)