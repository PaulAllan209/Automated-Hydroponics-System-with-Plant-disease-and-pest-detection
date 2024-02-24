import serial
from time import sleep



class ArduinoMegaCommunication:
    def __init__(self, port='/dev/ttyS0', baudrate=9600, xonxoff=True) -> None:
        self.serial_port = serial.Serial(port, baudrate, xonxoff=xonxoff)
        
        
    def send_data(self, data: dict):
        # Data needed to be sent:
        # Number of pulses for the 4 peristaltic pumps controlled by L298N
        # Water pump speed controlled by L298N
        # Peltier cooler state (turn on and hot or cold?)
        # Linear actuators state
        # Grow light 1, 2, 3 state
        # Air pump state
        # Exhaust fan 1 state
        # Exhaust fan 2 state
        # Solenoid valve state
        # Stepper motor X, Y, Z1, Z2 locations 
        
        base_peris_pump = data["base_peris_pump"]
        acid_peris_pump = data["acid_peris_pump"]
        nutriA_peris_pump = data["nutriA_peris_pump"]
        nutriB_peris_pump = data["nutriB_peris_pump"]
        
        
        
        
    
    def receive_data(self, data):
        pass
    
    def open(self):
        self.serial_port.open()
    
    def close(self):
        self.serial_port.close()
        
    