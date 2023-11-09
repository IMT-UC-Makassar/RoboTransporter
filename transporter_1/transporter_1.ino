#include <ServoInput.h>
#include <AFMotor.h>


ServoInputPin<19> ch1;
ServoInputPin<20> ch2;
ServoInputPin<21> ch3;

const int MPSwitchPosition = 4;

AF_DCMotor motorKiri(1);
AF_DCMotor motorKanan(2);

int stickKiri=0;
int stickKanan=0;
int swMultiPosition;

int topSpeed = 0;

const float Deadzone = 0.15;


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

  controlMotor();
}

void controlMotor(){
  if(stickKiri > 0){
    motorKiri.run(FORWARD);
    motorKiri.setSpeed(stickKiri*0.01*topSpeed);

  } else if(stickKiri < 0){
    motorKiri.run(BACKWARD);
    motorKiri.setSpeed(stickKiri*-0.01*topSpeed);
  } else {
    motorKiri.run(RELEASE);
  }

  Serial.print("motor Kiri: "); Serial.print(stickKiri*0.01*topSpeed);Serial.print(" | ");

  if(stickKanan > 0){
    motorKanan.run(FORWARD);
    motorKanan.setSpeed(stickKanan*0.01*topSpeed);

  } else if(stickKanan < 0){
    motorKanan.run(BACKWARD);
    motorKanan.setSpeed(stickKanan*-0.01*topSpeed);
  } else {
    motorKanan.run(RELEASE);
  }
  Serial.print("motor Kanan: "); Serial.print(stickKanan*0.01*topSpeed);Serial.println("");
  delay(10);
}
