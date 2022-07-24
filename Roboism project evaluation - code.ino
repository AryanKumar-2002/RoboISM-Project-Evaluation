const int trigPin1 = 12;
const int echoPin1 = 13;

const int trigPin2 = 7;
const int echoPin2 = 8;

long duration1;
int distance1;

long duration2;
int distance2;

const int LED_PIN = 5;

void setup()
{
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
  
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
  
pinMode(LED_PIN, OUTPUT);
  
Serial.begin(9600);
}

void loop()
{
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);

digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH);
distance1 = duration1*0.034/2;
  
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
  
digitalWrite(trigPin2, LOW);
  
duration2 = pulseIn(echoPin2, HIGH);
distance2 = duration2*0.034/2;
  
Serial.print("Distance 1 = ");
Serial.print(distance1);
Serial.print("\n");
  
Serial.print("Distance 2 = ");
Serial.print(distance2);
Serial.print("\n\n");
  
delay(100);
  
int dist = (distance1 < distance2) ? distance1:distance2;

long vol = dist/300.0*255.0;  
analogWrite(LED_PIN, vol);
}