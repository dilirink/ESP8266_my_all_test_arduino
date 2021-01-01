
void setup()
{
  // put your setup code here, to run once:
  pinMode(D5, INPUT_PULLUP);
  pinMode(D7, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  byte val = digitalRead(D5);
  if (val == HIGH)
    digitalWrite(D7, LOW);
  else
    digitalWrite(D7, HIGH);
}
