
int photoresistor = A0;          //variable for storing the photoresistor value
int potentiometer = A1;          //this variable will hold a value based on the position of the knob
int threshold = 700;            //if the photoresistor reading is lower than this value the light will turn on
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;
void setup() {
  Serial.begin(9600);           //start a serial connection with the computer

  //set the LED pins to output
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  pinMode(13,OUTPUT);
}
void loop() {
  photoresistor = analogRead(A0);         //read the value of the photoresistor
  potentiometer = analogRead(A1);
  Serial.print("Photoresistor value:");
  Serial.print(photoresistor);          //print the photoresistor value to the serial monitor
  Serial.print("  Potentiometer value:");
  Serial.println(potentiometer);          //print the potentiometer value to the serial monitor
  if (photoresistor < threshold) { 
    if (potentiometer > 0 && potentiometer <= 150)
      red();
       digitalWrite(13,HIGH);
    if (potentiometer > 150 && potentiometer <= 300)
      orange();
       digitalWrite(13,HIGH);
    if (potentiometer > 300 && potentiometer <= 450)
      yellow();
       digitalWrite(13,HIGH);
    if (potentiometer > 450 && potentiometer <= 600)
      green();
       digitalWrite(13,HIGH);
    if (potentiometer > 600 && potentiometer <= 750)
      cyan();
       digitalWrite(13,HIGH);
    if (potentiometer > 750 && potentiometer <= 900)
      blue();
       digitalWrite(13,HIGH);
    if (potentiometer > 900)
      magenta();
       digitalWrite(13,HIGH);
  }
  else {                                //if it isn't dark turn the LED off
digitalWrite(13,LOW);
    turnOff();                            //call the turn off function
  
  }

  delay(100);                             //short delay so that the printout is easier to read
}

void red () {

  //set the LED pins to values that make red
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
void orange () {

  //set the LED pins to values that make orange
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 50);
  analogWrite(BluePin, 0);
}
void yellow () {

  //set the LED pins to values that make yellow
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void green () {

  //set the LED pins to values that make green
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 0);
}
void cyan () {

  //set the LED pins to values that make cyan
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 100);
  analogWrite(BluePin, 100);
}
void blue () {

  //set the LED pins to values that make blue
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void magenta () {

  //set the LED pins to values that make magenta
  analogWrite(RedPin, 100);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 100);
}
void turnOff () {

  //set all three LED pins to 0 or OFF
  analogWrite(RedPin, 0);
  analogWrite(GreenPin, 0);
  analogWrite(BluePin, 0);
}
