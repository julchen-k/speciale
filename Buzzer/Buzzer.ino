
#define buzzer 13

void setup()
{
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  vibrationOn();
  delay(2000);       
  vibrationOff();
  delay(2000);    
}


void vibrationOn()
{
  digitalWrite(buzzer, HIGH); // Set buzzer on
}

void vibrationOff()
{
  digitalWrite(buzzer, LOW);

}

