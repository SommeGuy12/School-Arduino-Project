void setup()
{
  pinMode(11,OUTPUT);       //start a serial connection with the computer
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);      //set pin 13 as an output that can be set to HIGH or LOW
}

void loop()
{
  //change the LED blink speed based on the pot value
  digitalWrite(11,LOW);
  digitalWrite(13, HIGH);           // Turn on the LED
    digitalWrite(12, LOW);           // Turn off the LED
  delay(1000);              // delay for as many milliseconds as potPosition (0-1023)
  digitalWrite(11,HIGH);
  digitalWrite(13, LOW);            // Turn off the LED
    digitalWrite(12, HIGH);           // Turn on the LED
  delay(1000);              // delay for as many milliseconds as potPosition (0-1023)
}
