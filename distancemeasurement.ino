int trigpin=10;
int echopin=9;
float utime;
float distance;
float speedofsound=725; // Speed of sound in miles per hour
void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigpin,LOW);

  utime= pulseIn(echopin,HIGH,5000);
  utime= utime/1000000;
  utime= utime/3600;

  distance= speedofsound*utime; ;
  distance= distance/2;
  distance= distance*63360; // miles to inches

  Serial.print("distance measured is ");
  Serial.println(distance);
  delay(500);
}
