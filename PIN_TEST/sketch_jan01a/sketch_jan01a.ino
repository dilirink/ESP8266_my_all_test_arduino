#define LED 8
void setup() {
  // put your setup code here, to run once:
      pinMode(LED, OUTPUT);        //D3
}

void loop() {
  // put your main code here, to run repeatedly:
        analogWrite(LED, 256);
        delay(500);
        analogWrite(LED, 0);
        delay(500);
       
}
