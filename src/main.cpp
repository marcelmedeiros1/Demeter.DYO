#include <Arduino.h>
#include <DabbleESP32.h>
#include <MotorControl.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

// Select the motors to control
MotorControl motor3(3);
MotorControl motor4(4);

void setup() {
    // Coloque seu código de configuração aqui, para ser executado uma vez:
    Serial.begin(115200); // Certifique-se de que seu Serial Monitor também está configurado com a mesma taxa de transmissão.
    Dabble.begin("MyEsp32_DYO"); // Defina o nome Bluetooth do seu dispositivo
    MotorControl::init();
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
}

void loop() {
//Set the motors initial speeds
    motor3.setSpeed(255);
    motor4.setSpeed(255);
// Move forward
    motor3.forward();
    motor4.forward();
    delay(5000);
    // Move backwards slowly
    motor3.setSpeed(127);
    motor4.setSpeed(127);
    motor3.backward();
    motor4.backward();
    delay(5000);
    // Stop!
    motor3.setSpeed(0);
    motor4.setSpeed(0);
    delay(3000);    // Coloque seu código principal aqui, para ser executado continuamente:
    Dabble.processInput(); // Esta função é usada para atualizar os dados obtidos do smartphone. Portanto, chamá-la é obrigatório para obter os dados corretamente do seu dispositivo móvel.
    Serial.print("KeyPressed: ");
    
    // if (GamePad.isUpPressed()) {
    //     Serial.print("Up");
    // }

    // if (GamePad.isDownPressed()) {
    //     Serial.print("Down");
    // }

    // if (GamePad.isLeftPressed()) {
    //     Serial.print("Left");
    // }

    // if (GamePad.isRightPressed()) {
    //     Serial.print("Right");
    // }

    // if (GamePad.isStartPressed()) {
    //     Serial.print("Start");
    // }

    // if (GamePad.isSelectPressed()) {
    //     Serial.print("Select");
    // }
    
    Serial.print('\t');
    int a = GamePad.getAngle();
    Serial.print("Angle: ");
    Serial.print(a);
    Serial.print('\t');
    int b = GamePad.getRadius();
    Serial.print("Radius: ");
    Serial.print(b);
    Serial.print('\t');
    float c = GamePad.getXaxisData();
    Serial.print("x_axis: ");
    Serial.print(c);
    Serial.print('\t');
    float d = GamePad.getYaxisData();
    Serial.print("y_axis: ");
    Serial.println(d);
    Serial.println();
    
    analogWrite(6, abs(d) * 35);
    analogWrite(5, abs(d) * 35); // Esta linha controla um motor usando a entrada do eixo X do gamepad virtual.
}

