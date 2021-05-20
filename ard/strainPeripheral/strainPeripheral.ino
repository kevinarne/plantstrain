#include <Wire.h>

#define ITWOC_ADDR 16
#define WB_REF 4
#define WB_SG 3

void setup() 
{
  //Set up I2C details
  Wire.begin(ITWOC_ADDR);
  Wire.onRequest(handleEvent);

  pinMode(WB_REF, INPUT);
  pinMode(WB_SG, INPUT);
}

void loop() 
{
  //Kick your feet up and relax
}

void handleEvent() 
{
  //Read both ADCs
  uint16_t ref = 1023; 
  uint16_t var = analogRead(WB_SG);

  //Temporary variable for sending data
  byte data[4];

  //These lines transform the uint16_t's into bytes for I2C transmission
  data[0] = (ref >> 8) & 0xFF;
  data[1] = ref & 0xFF;
  data[2] = (var >> 8) & 0xFF;
  data[3] = var & 0xFF;
  
  Wire.write(data, 4);
}
