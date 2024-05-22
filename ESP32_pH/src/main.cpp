#if defined(ESP8266)
#include <ESP8266WiFi.h>
#else
#include <WiFi.h>
#endif
#if defined(ESP8266)
#include <ESP8266WebServer.h>
#else
#include <WebServer.h>
#endif
#include <PubSubClient.h>

#include <OneWire.h>
#include <DallasTemperature.h>

const char* mqtt_server = "192.168.1.10"; //mqtt server
const char* ssid = "Tatay Jhoe";
const char* password = "24build13";

const char *topic = "emqx/esp32/pH";
const char *topic_temp = "emqx/esp32/temp";

WiFiClient espClient;
PubSubClient client(espClient); //lib required for mqtt

const int oneWireBus = 4;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(oneWireBus);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

float calibration_value = 18.84;
int phval = 0;
unsigned long int avgval; 
int buffer_arr[10],temp;

int LED = 02;

void callback(char* topic, byte* payload, unsigned int length) {   //callback includes topic and payload ( from which (topic) the payload is comming)
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  if ((char)payload[0] == 'O' && (char)payload[1] == 'N') //on
  {
    digitalWrite(LED, HIGH);
    Serial.println("on");
    client.publish("outTopic", "LED turned ON");
  }
  else if ((char)payload[0] == 'O' && (char)payload[1] == 'F' && (char)payload[2] == 'F') //off
  {
    digitalWrite(LED, LOW);
    Serial.println(" off");
    client.publish("outTopic", "LED turned OFF");
  }
  Serial.println();
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    if (client.connect("ESP32_clientID")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "Nodemcu connected to MQTT");
      // ... and resubscribe
      client.subscribe("inTopic");

    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void connectmqtt()
{
  client.connect("ESP32_clientID");  // ESP will connect to mqtt broker with clientID
  {
    Serial.println("connected to MQTT");
    // Once connected, publish an announcement...

    // ... and resubscribe
    client.subscribe("inTopic"); //topic=Demo
    client.publish("outTopic",  "connected to MQTT");

    if (!client.connected())
    {
      reconnect();
    }
  }
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(39, INPUT);

  // Start the DS18B20 sensor
    sensors.begin();

  WiFi.begin(ssid, password);
  Serial.println("connected");
  client.setServer(mqtt_server, 1883);//connecting to mqtt server
  client.setCallback(callback);
  //delay(5000);
  connectmqtt();
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (!client.connected())
  {
    reconnect();
  }

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

  client.loop();
}
