from modules import communication

ArduinoComms = communication.ArduinoMegaCommunication()

data = {
    # 18 values sent
    "base_peris_pump":2,
    "acid_peris_pump":2,
    "nutriA_peris_pump":2,
    "nutriB_peris_pump":2,
    
    "water_pump_speed":0.5,
    
    "peltier_state":1,
    "peltier_mode":"Cold",
    
    "linear_act":1,
    
    "grow_light_1":1,
    "grow_light_2":1,
    
    "air_pump":1,
    
    "exhaust_fan_1":1,
    "exhaust_fan_2":1,
    
    "solenoid":0,
    
    "step_x":200,
    "step_y":200,
    "step_z1":200,
    "step_z2":200
}

# ArduinoComms.send_data(data)
print(len())
