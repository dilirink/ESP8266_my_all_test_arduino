#define LED_BLU D5 // Led in NodeMCU at pin GPIO16 (D0).
#define LED_RED D0
#define LED_GRE D7
void setup() {
pinMode(LED_BLU, OUTPUT); // set the digital pin as output.
pinMode(LED_RED, OUTPUT); // set the digital pin as output.
pinMode(LED_GRE, OUTPUT); // set the digital pin as output.
}
void loop() {
digitalWrite(LED_BLU, HIGH);// turn the LED off.(Note that LOW is the voltage level but actually//the LED is on; this is because it is acive low on the ESP8266.
delay(500);          // wait for 1 second.
digitalWrite(LED_BLU, LOW); // turn the LED on.
delay(500);         // wait for 1 second.


digitalWrite(LED_RED, HIGH);// turn the LED off.(Note that LOW is the voltage level but actually                     //the LED is on; this is because it is acive low on the ESP8266.
delay(500);          // wait for 1 second.
digitalWrite(LED_RED, LOW); // turn the LED on.
delay(500);  



digitalWrite(LED_GRE, HIGH);// turn the LED off.(Note that LOW is the voltage level but actually                      //the LED is on; this is because it is acive low on the ESP8266.
delay(500);          // wait for 1 second.
digitalWrite(LED_GRE, LOW); // turn the LED on.
delay(500); 
}
