#include <WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int oneWireBus = 4;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

// WiFi
const char *ssid = "Tatay Jhoe"; // Enter your Wi-Fi name
const char *password = "24build13";  // Enter Wi-Fi password

// MQTT Broker
const char *mqtt_broker = "192.168.1.10";
const char *topic = "emqx/esp32/pH";
const char *topic_temp = "emqx/esp32/temp";

const char *mqtt_username = "user";
const char *mqtt_password = "public";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void callback(char *topic, byte *payload, unsigned int length) {
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
    Serial.print("Message:");
    for (int i = 0; i < length; i++) {
        Serial.print((char) payload[i]);
    }
    Serial.println();
    Serial.println("-----------------------");
}

void setup() {
    // Set software serial baud to 115200;
    Serial.begin(9600);
    // Connecting to a WiFi network
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the Wi-Fi network");
    //connecting to a mqtt broker
    client.setServer(mqtt_broker, mqtt_port);
    client.setCallback(callback);
    while (!client.connected()) {
        String client_id = "pH_esp32";
        client_id += String(WiFi.macAddress());
        Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
            Serial.println("Public EMQX MQTT broker connected");
        } else {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }
    // Publish and subscribe
    client.publish(topic, "Hi, I'm ESP32 ^^");
    client.subscribe(topic);

    pinMode(39, INPUT);

    // Start the DS18B20 sensor
    sensors.begin();
}

float calibration_value = 18.84;
int phval = 0;
unsigned long int avgval; 
int buffer_arr[10],temp;

void loop() {
    client.loop();
    int ph_reading = analogRead(39);
    
    sensors.requestTemperatures(); 
    float temperatureC = sensors.getTempCByIndex(0);
    char tempString[8];
    dtostrf(temperatureC, 1, 2, tempString);
    client.publish(topic_temp, tempString);
    
    

   


    // pH Measurement

    for(int i=0;i<10;i++) { 
      buffer_arr[i]=analogRead(39);
      delay(30);
    }
      for(int i=0;i<9;i++){
        for(int j=i+1;j<10;j++){
          if(buffer_arr[i]>buffer_arr[j]){
            temp=buffer_arr[i];
            buffer_arr[i]=buffer_arr[j];
            buffer_arr[j]=temp;
          }
        }
      }
      avgval=0;
      for(int i=2;i<8;i++)
      avgval+=buffer_arr[i];
      float volt=(float)avgval*5.0/4095/6;
      float ph_act = -5.70 * volt + calibration_value;

      char voltageString[8];
      dtostrf(ph_act, 1, 2, voltageString);
      client.publish(topic, voltageString);
}
