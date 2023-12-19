const int trigPin = 11;           //connects to the trigger pin on the distance sensor
const int echoPin = 12;           //connects to the echo pin on the distance sensor
const int redPin = 3;             //pin to control the red LED inside the RGB LED
const int greenPin = 5;           //pin to control the green LED inside the RGB LED
const int bluePin = 6;            //pin to control the blue LED inside the RGB LED
float distance = 0;               //stores the distance measured by the distance sensor
int speakerPin = 13;               //the pin that buzzer is connected to
void setup()
{
  Serial.begin (9600);        //set up a serial connection with the computer
  pinMode(trigPin, OUTPUT);   //the trigger pin will output pulses of electricity
  pinMode(echoPin, INPUT);    //the echo pin will measure the duration of pulses coming back from the distance sensor
  //set the RGB LED pins to output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(speakerPin, OUTPUT);    //set the output pin for the speaker
}
void loop() {
  distance = getDistance();   //variable to store the distance measured by the sensor
  Serial.print(distance);     //print the distance that was measured
  Serial.println(" in");      //print units after the distance
  if (distance <= 10) {                       //if the object is close
    //make the RGB LED red
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
   play('g', 2);    
  } else if (10 < distance && distance < 20) { //if the object is a medium distance
    //make the RGB LED yellow
    analogWrite(redPin, 255);
    analogWrite(greenPin, 50);
    analogWrite(bluePin, 0);
     play('a', 4);  
  } else {                                    //if the object is far away
    //make the RGB LED green
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }
  delay(50);      //delay 50ms between each reading
}
//------------------FUNCTIONS-------------------------------
//RETURNS THE DISTANCE MEASURED BY THE HC-SR04 DISTANCE SENSOR
float getDistance()
{
  float echoTime;                   //variable to store the time it takes for a ping to bounce off an object
  float calculatedDistance;         //variable to store the distance calculated from the echo time
  //send out an ultrasonic pulse that's 10ms long
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  echoTime = pulseIn(echoPin, HIGH);      //use the pulsein command to see how long it takes for the
                                          //pulse to bounce back to the sensor
  calculatedDistance = echoTime / 148.0;  //calculate the distance of the object that reflected the pulse (half the bounce time multiplied by the speed of sound)
  return calculatedDistance;              //send back the distance that was calculated
}
void play( char note, int beats)
{
  int numNotes = 14;  // number of notes in our note and frequency array (there are 15 values, but arrays start at 0)

  //Note: these notes are C major (there are no sharps or flats)

  //this array is used to look up the notes
  char notes[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B', ' '};
  //this array matches frequencies with each letter (e.g. the 4th note is 'f', the 4th frequency is 175)
  int frequencies[] = {131, 147, 165, 175, 196, 220, 247, 262, 294, 330, 349, 392, 440, 494, 0};

  int currentFrequency = 0;    //the frequency that we find when we look up a frequency in the arrays
  int beatLength = 150;   //the length of one beat (changing this will speed up or slow down the tempo of the song)

  //look up the frequency that corresponds to the note
  for (int i = 0; i < numNotes; i++)  // check each value in notes from 0 to 14
  {
    if (notes[i] == note)             // does the letter passed to the play function match the letter in the array?
    {
      currentFrequency = frequencies[i];   // Yes! Set the current frequency to match that note
    }
  }

  //play the frequency that matched our letter for the number of beats passed to the play function
  tone(speakerPin, currentFrequency, beats * beatLength);
  delay(beats * beatLength);  //wait for the length of the tone so that it has time to play
  delay(50);                  //a little delay between the notes makes the song sound more natural

}