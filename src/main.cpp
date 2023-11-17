#include <Arduino.h>
#include <Wire.h>
#include <DabbleESP32.h>
#include <MotorControl.h>

#define maxSpeed 150
// Select the motors to control
MotorControl motor3(3);
MotorControl motor4(4);

void stopMotors(){
    motor3.setSpeed(0);
    motor4.setSpeed(0);    
}

void setup() {
    MotorControl::init();
    Serial.begin(115200);
    Dabble.begin("Dyo");
    stopMotors();
}

void loop() {
    Dabble.processInput();

    int x_axis = GamePad.getXaxisData(); // Obtém dados do eixo X
    int y_axis = GamePad.getYaxisData(); // Obtém dados do eixo Y

    int motor3_speed = y_axis * maxSpeed / 7;
    int motor4_speed = y_axis * maxSpeed / 7;

    motor4_speed = constrain(motor4_speed + x_axis * maxSpeed / 7, -maxSpeed, maxSpeed);
    motor3_speed = constrain(motor3_speed - x_axis * maxSpeed / 7, -maxSpeed, maxSpeed);
    // Define as velocidades dos motores
    motor3.setSpeed(motor3_speed);
    motor4.setSpeed(motor4_speed);

    // Move os motores de acordo com as velocidades definidas
    if (y_axis > 0) {
        motor3.forward();
        motor3.setSpeed(motor3_speed);
        motor4.forward();
        motor4.setSpeed(motor4_speed);
    } else if (y_axis < 0) {
        motor3.backward();
        motor3.setSpeed(motor3_speed);
        motor4.backward();
        motor4.setSpeed(motor4_speed);
    } else {
        stopMotors();
    }
}
