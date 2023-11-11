#include <ServoInput.h>
#include <AFMotor.h>


ServoInputPin<19> ch1;
ServoInputPin<20> ch2;
ServoInputPin<21> ch3;

const int MPSwitchPosition = 4;

AF_DCMotor motorKiri(1);
AF_DCMotor motorKiriDepan(4);

AF_DCMotor motorKanan(2);
AF_DCMotor motorKananDepan(3);

int stickKiri=0;
int stickKanan=0;
int swMultiPosition;

int topSpeed = 100;

const float Deadzone = 0.15;

  //Channel 1 & 2 itu buat 
  int leftSpeed;
  int rightSpeed;



void setup() {
 Serial.begin(115200);
}

void loop() {
  //Ambil Data Remote Di setiap Loop
  stickKiri = ch1.mapDeadzone(-100, 100, Deadzone);
  stickKanan = ch2.mapDeadzone(-100, 100, Deadzone);
  swMultiPosition = ch3.map(1,MPSwitchPosition);

  Serial.print("ch1: "); Serial.print(stickKiri);Serial.print(" | ");
  Serial.print("ch2: "); Serial.print(stickKanan);Serial.print(" | ");
  Serial.print("ch3: "); Serial.print(swMultiPosition);Serial.println("");

  //Channel 1 & 2 itu buat 
  leftSpeed = stickKiri + stickKanan;
  rightSpeed = stickKiri - stickKanan;

  controlMotor();
  capitControl();
}

void controlMotor(){
  if(leftSpeed > 0){
    motorKiri.run(FORWARD);
    motorKiriDepan.run(FORWARD);
    motorKiri.setSpeed(leftSpeed);
    motorKiriDepan.setSpeed(leftSpeed);

  } else if(leftSpeed < 0){
    motorKiri.run(BACKWARD);
    motorKiriDepan.run(BACKWARD);
    motorKiri.setSpeed(leftSpeed * -1);
    motorKiriDepan.setSpeed(leftSpeed * -1);
  } else {
    motorKiri.run(RELEASE);
        motorKiriDepan.run(RELEASE);

  }

  Serial.print("motor Kiri: "); Serial.print(leftSpeed);Serial.print(" | ");

  if(rightSpeed > 0){
    motorKanan.run(FORWARD);
    motorKananDepan.run(FORWARD);
    motorKanan.setSpeed(rightSpeed);
    motorKananDepan.setSpeed(rightSpeed);

  } else if(rightSpeed < 0){
    motorKanan.run(BACKWARD);
    motorKananDepan.run(BACKWARD);
    motorKanan.setSpeed(rightSpeed * -1);
    motorKananDepan.setSpeed(rightSpeed * -1);
  } else {
    motorKanan.run(RELEASE);
    motorKananDepan.run(RELEASE);
  }
  Serial.print("motor Kanan: "); Serial.print(rightSpeed);Serial.println("");
  delay(10);
}

void capitControl(){
  if(swMultiPosition = 3){
  //buka capit  
  } else if(swMultiPosition =1){
    //tutup capit
  } else {
    //nda ngapa-ngpain
  }
  }
}
