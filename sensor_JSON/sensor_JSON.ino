
#include <ArduinoJson.h>

//moisture and water level Sensor wiring pins 
int moist_pin = A1;
int wlevel_pin= A0;

 //Sensor variables
int moist_value ;
int wlevel_value;


void setup() {
  // Initialize serial port
  Serial.begin(9600);
  while (!Serial) continue;

}

void loop() {

   moist_value= analogRead(moist_pin);
// moist_value = map(moist_value,1023,100,0,100);

  wlevel_value= analogRead(wlevel_pin);

  const size_t bufferSize = JSON_OBJECT_SIZE(2) + 30;
  DynamicJsonBuffer jsonBuffer(bufferSize);

  const char* json = "{\"moisture\":\"32.23\",\"humidity\":\"344.22\"}";

  JsonObject& root = jsonBuffer.parseObject(json);

  const char* moist_v = root["moisture"]; // "32.23"
  const char* water_level = root["w_level"]; // "344.22"

  const size_t bufferSize1 = JSON_OBJECT_SIZE(2);

//DynamicJsonBuffer jsonBuffer(bufferSize1);

  JsonObject& root1 = jsonBuffer.createObject();
  root1["moisture"] = moist_value;
  root1["W_level"] = wlevel_value;

  root1.printTo(Serial);
  delay(2000);
  
  }
