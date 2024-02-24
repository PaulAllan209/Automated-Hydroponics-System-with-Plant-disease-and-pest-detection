from modules import communication

ArduinoComms = communication.ArduinoMegaCommunication()

data = {
    "base_peris_pump":2,
    "acid_peris_pump":2,
    "nutriA_peris_pump":2,
    "nutriB_peris_pump":2,
    
    "water_pump_speed":0.5,
    
    "peltier_state":True,
    "peltier_mode":"Cold",
    
    "linear_act":True,
    
    "grow_light_1":True,
    "grow_light_2":True,
    
    "air_pump":True,
    
    "exhaust_fan_1":True,
    "exhaust_fan_2":True,
    
    "solenoid":False,
    
    "step_x":200,
    "step_y":200,
    "step_z1":200,
    "step_z2":200
}

ArduinoComms.send_data(data)
