#include <Servo.h>
#include <SoftwareSerial.h>
Servo myservo;
SoftwareSerial myserial(13,12);

int b;
int i=0;

void setup() {
  myserial.begin(9600);
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(11, OUTPUT);
  // put your setup code here, to run once:
}

void loop() {

  if(myserial.available())
  {
    delay(100);
    i++;
  String a = myserial.readString();
  int b=a.toFloat();
  if (i == 1) {
  Serial.println(b);
  analogWrite(11,b);
  }  
  if(i == 2) {
  Serial.println("etape servo");
  myservo.write(b); 
  delay(1000); 
  i=0;
  } 
  Serial.println(i);
   
  }

  delay(1000);
}
