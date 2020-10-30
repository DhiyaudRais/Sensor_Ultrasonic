int pingPin = 11;
int echoPin = 10;
int led = 7;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  long duration, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin, LOW);

   pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);

if(cm <= 200){
  digitalWrite(led, HIGH);
}
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}



long microsecondsToCentimeters(long microseconds)
{
  
  return microseconds*0.034/2;
}
