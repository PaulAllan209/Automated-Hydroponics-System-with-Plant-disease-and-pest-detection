import paho.mqtt.client as mqtt
import time
import sys

def on_message(client, userdata, msg):
    received_message = msg.payload.decode()
    print(f"messaged received: {received_message}")

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2, "rpi_client1") #this should be a unique name
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
    byteArr = bytearray(image_content)
    # print(byteArr)

client.publish(payload=f"{byteArr}", topic="esp32/mr_fresh")
client.loop_forever()
    
# client_subscriptions(client)
print("......client setup complete............")


