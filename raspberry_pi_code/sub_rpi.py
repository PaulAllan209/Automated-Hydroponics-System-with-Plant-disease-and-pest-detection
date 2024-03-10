import paho.mqtt.client as mqtt
import time
import sys
import base64

def on_message(client, userdata, msg):
    image_dir = r"/home/superpotatorpi/Desktop/hydroponics_env/Automated-Hydroponics-System-with-Plant-disease-and-pest-detection/raspberry_pi_code/images/rpi_output/mr_fresh_out.png"
    with open(image_dir, "wb") as writer_img:
        msg_str = msg.payload.decode()
        image_data = base64.b64decode(msg_str)
        writer_img.write(image_data)
        print(f"Image received: {image_data}")

client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2, "rpi_client2") # bro change the name of this if it is on different devices
flag_connected = 0


if client.connect("192.168.1.10", 1883) != 0:
    print("Could not connect to broker")
    sys.exit(-1)

client.on_message = on_message

client.subscribe("esp32/mr_fresh")
client.loop_forever()
