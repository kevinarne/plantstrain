#include <Wire.h>

#define ITWOC_ADDR 16

void setup() 
{
  Wire.begin();
  Serial.begin(9600);
}

void loop() 
{
  //Request 1 byte from peripheral
  Wire.requestFrom(ITWOC_ADDR, 4);    
  if (Wire.available()) 
  {
    uint8_t val1 = Wire.read();
    uint8_t val2 = Wire.read();
    uint8_t val3 = Wire.read();
    uint8_t val4 = Wire.read();
    
    uint16_t ref = val1;
    ref = ref << 8 | val2;
    uint16_t wb_sg = val3;
    wb_sg = wb_sg << 8 | val4;

    Serial.print("Reference Value: ");
    Serial.println(ref);
    Serial.print("Strain Gauge Value: ");
    Serial.println(wb_sg);
  }
  delay(1000);
}
