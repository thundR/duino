// the value of the 'other' resistor
#define SERIESRESISTOR 10000    
 
// What pin to connect the sensor to
#define THERMISTORPIN A0 
#define PHOTOPIN A1
 #define POTENPIN A2
void setup(void) {
  Serial.begin(9600);
}
 
void loop(void) {
  float reading;
  float reading2;
  float reading3;
 
  reading = analogRead(THERMISTORPIN);
  reading2 = analogRead(PHOTOPIN);
  reading3 = analogRead(POTENPIN);
 
  Serial.print("Analog reading therm"); 
  Serial.println(reading);
  Serial.print("Analog reading photo"); 
  Serial.println(reading2);
  Serial.print("Analog reading poten"); 
  Serial.println(reading3);
 
  // convert the value to resistance
  reading = (1023 / reading)  - 1;
  reading = SERIESRESISTOR / reading;
  Serial.print("Thermistor resistance "); 
  Serial.println(reading);

  analogWrite(11, reading3);
 
  delay(1000);
}
