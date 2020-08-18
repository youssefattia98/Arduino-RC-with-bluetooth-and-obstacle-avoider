/*
 Author: Youssef Attia
 Description: Arduino RC with bluetooth and obstacle avoider. app to be used from any andriod smarphone form play store:
 https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&hl=enavoider
*/

#define motor1PWM 3
#define motor1F 4
#define motor1R 5
#define motor2PWM 9
#define motor2F 6
#define motor2R 7
#define trig 10
#define echo 11
#define buzzer 12
int Time;
float distance;
void setup() {
  Serial.begin(9600);
  pinMode(motor1PWM, OUTPUT);
  pinMode(motor1F, OUTPUT);
  pinMode(motor1R, OUTPUT);
  pinMode(motor2PWM, OUTPUT);
  pinMode(motor2F, OUTPUT);
  pinMode(motor2R, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  Time = pulseIn(echo, HIGH);
  distance = constrain((Time / 58.31), 4, 400);
  /*if (distance >400 || distance<4){
    distance =0;
    }*/
  //distance = constrain(distance, 4, 400);
  digitalWrite(trig, LOW);
  Serial.println("F-->Forward");
  Serial.println("R-->Reverse");
  Serial.println("L-->left");
  Serial.println("R-->Right");
  Serial.println("S-->Stop");
  Serial.println("N-->Neutral");
  Serial.println("the distance between object:");
  Serial.println(distance);
  Serial.println("CM");
  while (!Serial.available());
  char x =  Serial.read();
  switch (x) {
    case 'F':
      if (distance <= 100) {
        digitalWrite(buzzer, HIGH);
        digitalWrite(motor1F, HIGH);
        digitalWrite(motor1R, HIGH);
        digitalWrite(motor2F, HIGH);
        digitalWrite(motor2R, HIGH);
      }
      else {
        digitalWrite(motor1F, HIGH);
        digitalWrite(motor1R, LOW);
        digitalWrite(motor2F, HIGH);
        digitalWrite(motor2R, LOW);
      }
      break;
    case 'B':
      digitalWrite(motor1F, LOW);
      digitalWrite(motor1R, HIGH);
      digitalWrite(motor2F, LOW);
      digitalWrite(motor2R, HIGH);
      break;
    case 'L':
      digitalWrite(motor1F, HIGH);
      digitalWrite(motor1R, LOW);
      digitalWrite(motor2F, LOW);
      digitalWrite(motor2R, LOW);
      break;
    case 'R':
      digitalWrite(motor1F, LOW);
      digitalWrite(motor1R, LOW);
      digitalWrite(motor2F, HIGH);
      digitalWrite(motor2R, LOW);
      break;
    case 'S':
      digitalWrite(motor1F, HIGH);
      digitalWrite(motor1R, HIGH);
      digitalWrite(motor2F, HIGH);
      digitalWrite(motor2R, HIGH);
      break;
    case 'N':
      digitalWrite(motor1F, LOW);
      digitalWrite(motor1R, LOW);
      digitalWrite(motor2F, LOW);
      digitalWrite(motor2R, LOW);
      break;
  }
}
