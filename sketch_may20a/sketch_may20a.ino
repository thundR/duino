#define MAX_LEN 5
int arr[ MAX_LEN ] = { 1, 2, 3, 4, 5 };
 
void Func( int *ptr ){
   
  for( int idx = MAX_LEN - 1 ; idx >= 0 ; --idx ){
    Serial.println( ptr[ idx ], HEX );
  }
}
 
void setup(){
  Serial.begin( 9600 );
  Func( arr );
}
 
void loop() {}
