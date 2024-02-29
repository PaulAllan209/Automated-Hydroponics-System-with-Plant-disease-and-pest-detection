import serial
from time import sleep



class ArduinoMegaCommunication:
    def __init__(self, port='/dev/ttyUSB0', baudrate=9600, xonxoff=True) -> None:
        self.serial_port = serial.Serial(port, baudrate, xonxoff=xonxoff)
        # self.serial_port.open()
        
        
    def send_data(self, arduino_data: dict):
        # Data needed to be sent:
        # Number of pulses for the 4 peristaltic pumps controlled by L298N
        # Water pump speed controlled by L298N
        # Peltier cooler state (turn on and hot or cold?)
        # Linear actuators state
        # Grow light 1, 2 state
        # Air pump state
        # Exhaust fan 1 state
        # Exhaust fan 2 state
        # Solenoid valve state
        # Stepper motor X, Y, Z1, Z2 locations 
        
        
        # Peristaltic pumps
        base_peris_pump = arduino_data["base_peris_pump"]
        acid_peris_pump = arduino_data["acid_peris_pump"]
        nutriA_peris_pump = arduino_data["nutriA_peris_pump"]
        nutriB_peris_pump = arduino_data["nutriB_peris_pump"]
        
        # Water pump
        water_pump_speed = arduino_data["water_pump_speed"]
        
        # Peltier cooler
        peltier_state = arduino_data["peltier_state"] # on or off?
        peltier_mode = arduino_data["peltier_mode"] # hot or cold?
        
        # Linear actuators state
        linear_act = arduino_data["linear_act"]
        
        
        # Grow light 1 and 2 state
        grow_light_1 = arduino_data["grow_light_1"]
        grow_light_2 = arduino_data["grow_light_2"]
        
        # Air pump state
        air_pump = arduino_data["air_pump"]
        
        # Exhaust fan 1 and 2 state
        exhaust_fan_1 = arduino_data["exhaust_fan_1"]
        exhaust_fan_2 = arduino_data["exhaust_fan_2"]
        
        # Solenoid valve state
        solenoid = arduino_data["solenoid"]
        
        # Stepper motor positions
        step_x = arduino_data["step_x"]
        step_y = arduino_data["step_y"]
        step_z1 = arduino_data["step_z1"]
        step_z2 = arduino_data["step_z2"]
        
        data_str = (
    f'<100,{base_peris_pump}>'
    f'<101,{acid_peris_pump}>'
    f'<102,{nutriA_peris_pump}>'
    f'<103,{nutriB_peris_pump}>'
    f'<104,{water_pump_speed}>'
    f'<105,{peltier_state}>'
    f'<106,{peltier_mode}>'
    f'<107,{linear_act}>'
    f'<108,{grow_light_1}>'
    f'<109,{grow_light_2}>'
    f'<110,{air_pump}>'
    f'<111,{exhaust_fan_1}>'
    f'<112,{exhaust_fan_2}>'
    f'<113,{solenoid}>'
    f'<114,{step_x}>'
    f'<115,{step_y}>'
    f'<116,{step_z1}>'
    f'<117,{step_z2}>'
)
        
        self.serial_port.write(data_str.encode('utf-8'))
        
    def receive_data(self, data):
        pass
    
    def send_raw_data(self, data):
        self.serial_port.write(data.encode('utf-8'))
    
    def open(self):
        self.serial_port.open()
    
    def close(self):
        self.serial_port.close()
        
    