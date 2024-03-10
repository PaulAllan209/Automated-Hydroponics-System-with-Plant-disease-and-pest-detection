import paho.mqtt.client as mqtt
import time
import sys
import base64

def on_message(client, userdata, msg):
    received_message = msg.payload.decode()
    print(f"messaged received: {received_message}")

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2, "rpi_client1") # bro change the name of this if it is on different devices
flag_connected = 0


if client.connect("192.168.1.10", 1883) != 0:
    print("Could not connect to broker")
    sys.exit(-1)

client.on_message = on_message
# start a new thread
counter = 0


# Send image
with open("raspberry_pi_code\images\mr_fresh.png", "rb") as mr_fresh:
    image_content = mr_fresh.read()
    base64_str = base64.b64encode(image_content).decode('utf-8')
    print(base64_str)


# TODO: Check for single publish in the documentation might be useful because loop_forever() is just not flexible
client.publish(payload=base64_str, topic="esp32/mr_fresh")
client.loop_forever()
    
# client_subscriptions(client)
print("......client setup complete............")


