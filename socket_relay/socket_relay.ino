#define RELAY1  4
#define RELAY2  5
#define RELAY3  6
#define RELAY4  7

int input;
bool debug = false; // all relays write HIGH
bool pwr = true; 

void setup() {  
    
  Serial.begin(9600);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);
  
  digitalWrite(RELAY1,HIGH);
  digitalWrite(RELAY2,HIGH);
  digitalWrite(RELAY3,HIGH);
  digitalWrite(RELAY4,HIGH);
     
}

void loop() {
  if(debug) {
    digitalWrite(RELAY1,HIGH);
    digitalWrite(RELAY2,HIGH);
    digitalWrite(RELAY3,HIGH);
    digitalWrite(RELAY4,HIGH);
  } 
  
  else {
    if(Serial.available() > 0) {
      input = Serial.read();
      Serial.print("You entered ");
      Serial.print(input - 48);
      Serial.print(" (ASCII ");
      Serial.print(input);
      Serial.println(")");
      
      if(pwr) {
        pwr = false;
        
        if(input == 49) { // ASCII 48 = 1
          digitalWrite(RELAY1,LOW);
        } 
        else if(input == 50) {
          digitalWrite(RELAY2,LOW);
        }
        else if(input == 51) {
          digitalWrite(RELAY3,LOW);
        }
        else if(input == 52) {
          digitalWrite(RELAY4,LOW);
        }
      }
    
      else {
        pwr = true;
        if(input == 49) {
          digitalWrite(RELAY1,HIGH);
        } 
        else if(input == 50) {
          digitalWrite(RELAY2,HIGH);
        }
        else if(input == 51) {
          digitalWrite(RELAY3,HIGH);
        }
        else if(input == 52) {
          digitalWrite(RELAY4,HIGH);
        }
      }
    }
  }
}
