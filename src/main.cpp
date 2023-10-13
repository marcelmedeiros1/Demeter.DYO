#include <Arduino.h>
#include <DabbleESP32.h>
#include <functions.h>
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

enum MOTOR_PWM_PIN {
    MOTOR1_PWM = 23,
    MOTOR2_PWM = 25,
    MOTOR3_PWM = 27,
    MOTOR4_PWM = 16,
};

enum SHIFTREG_CONTROL_PIN {
    MC_LATCH = 19,
    MC_CLK = 17,
    MC_ENABLE = 14,
    MC_DATA = 12,
};

void setup() {
    // Coloque seu código de configuração aqui, para ser executado uma vez:
    Serial.begin(115200); // Certifique-se de que seu Serial Monitor também está configurado com a mesma taxa de transmissão.
    Dabble.begin("MyEsp32"); // Defina o nome Bluetooth do seu dispositivo
}

void loop() {
    // Coloque seu código principal aqui, para ser executado continuamente:
    Dabble.processInput(); // Esta função é usada para atualizar os dados obtidos do smartphone. Portanto, chamá-la é obrigatório para obter os dados corretamente do seu dispositivo móvel.
    Serial.print("KeyPressed: ");
    
    if (GamePad.isUpPressed()) {
        Serial.print("Up");
    }

    if (GamePad.isDownPressed()) {
        Serial.print("Down");
    }

    if (GamePad.isLeftPressed()) {
        Serial.print("Left");
    }

    if (GamePad.isRightPressed()) {
        Serial.print("Right");
    }

    if (GamePad.isStartPressed()) {
        Serial.print("Start");
    }

    if (GamePad.isSelectPressed()) {
        Serial.print("Select");
    }
    
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
    
    analogWrite(9, abs(c) * 35); // Esta linha controla um motor usando a entrada do eixo X do gamepad virtual.
}

