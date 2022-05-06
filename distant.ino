#define trigPin 13 // digitalni izlaz D13
#define echoPin 12 // digitalni izlaz D12
#define ledCrvena 11 // PWM izlaz 11 
#define ledZelena 10 // PWM izlaz 10

  float duration, distance;
  double sjaj;
  int k=0;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledCrvena, OUTPUT);
  pinMode(ledZelena, OUTPUT);
}

void loop() {


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(4);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 2.91;
  if (distance < 100 && distance >30) {  
  sjaj=map(distance,30,100,0,255);  
  analogWrite(ledCrvena,255-sjaj); 
  analogWrite(ledZelena,0);
}
  if (distance >= 100 && distance <240) {
    sjaj=map(distance, 100,240,0,255);
    analogWrite(ledCrvena,0);
    analogWrite(ledZelena,sjaj);
  }
  if (distance >= 240){
    Serial.println("Predaleko");
    analogWrite(ledCrvena,0);
    analogWrite(ledZelena,255);
  }
  else if (distance <= 30){
    Serial.println("Preblizo");
    Serial.println(k);
    switch (k) {
      case 0: {analogWrite(ledCrvena,0);analogWrite(ledZelena,255);k=1;delay(100); }
      break;
      case 1: {analogWrite(ledCrvena,255);analogWrite(ledZelena,1);k=0;delay(100); }
      break;
    } 
     
  }
  else {
    Serial.print(distance);
    Serial.println(" mm");
  }
  delay(10);
}