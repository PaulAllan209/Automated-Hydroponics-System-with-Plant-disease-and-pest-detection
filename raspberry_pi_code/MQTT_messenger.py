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
client.publish(payload="wowmagic from pc", topic="esp32/light")
counter = 0
while True:
    client.subscribe("esp32/light")
    client.publish(payload=f"wowmagic from pc num={counter}", topic="esp32/light")
    counter+=1
    time.sleep(5)
    # client.loop_forever()
    
# client_subscriptions(client)
print("......client setup complete............")


