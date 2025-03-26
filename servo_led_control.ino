#include <Servo.h>

Servo myServo; // 建立伺服馬達物件
int servoPin = 9; // 伺服馬達的控制腳位
int led1Pin = 7; // LED1 的腳位
int led2Pin = 8; // LED2 的腳位
int angle = 0; // 伺服馬達的角度

void setup() {
  myServo.attach(servoPin); // 將伺服馬達連接到指定腳位
  pinMode(led1Pin, OUTPUT); // 設定 LED1 為輸出
  pinMode(led2Pin, OUTPUT); // 設定 LED2 為輸出
}

void loop() {
  // 控制伺服馬達角度
  for (angle = 0; angle <= 180; angle += 10) { // 從 0 度移動到 180 度
    myServo.write(angle); // 設定伺服馬達角度
    delay(500); // 等待馬達移動完成
    controlLEDs(angle); // 根據角度控制 LED
  }

  for (angle = 180; angle >= 0; angle -= 10) { // 從 180 度移動到 0 度
    myServo.write(angle); // 設定伺服馬達角度
    delay(500); // 等待馬達移動完成
    controlLEDs(angle); // 根據角度控制 LED
  }
}

void controlLEDs(int currentAngle) {
  if (currentAngle < 90) {
    digitalWrite(led1Pin, HIGH); // LED1 亮
    digitalWrite(led2Pin, LOW);  // LED2 暗
  } else {
    digitalWrite(led1Pin, LOW);  // LED1 暗
    digitalWrite(led2Pin, HIGH); // LED2 亮
  }
}