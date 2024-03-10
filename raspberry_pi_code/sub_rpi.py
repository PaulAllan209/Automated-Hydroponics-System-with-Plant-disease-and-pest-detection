import paho.mqtt.client as mqtt
import time
import sys

def on_message(client, userdata, msg):
    with open("raspberry_pi_code\images\rpi_output\mr_fresh_out.png", "wb") as writer_img:
        byte_arr = bytearray(msg.payload.decode())
        writer_img.write(byte_arr)
    print(f"Image received")

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2, "rpi_client1") #this should be a unique name
flag_connected = 0


if client.connect("192.168.1.10", 1883) != 0:
    print("Could not connect to broker")
    sys.exit(-1)

client.on_message = on_message

client.subscribe("esp32/mr_fresh")
