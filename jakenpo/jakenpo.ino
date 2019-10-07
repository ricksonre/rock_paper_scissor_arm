/*
ax12.h
    SetPosition(id,pos)
    GetPosition(id)
    TorqueOn(id)
    Relax(id)
    GetLeftIRData(id)
    GetCenterIRData(id)
    GetRightIRData(id)
    GetObstacles(id)
    PlayTone(id, note)

Servos
    d0,d1,d2

Buttons
    d3,d4,d5

Max rotation
    12: 0 1023
    13, 14 ?
    15, 16 ?
    17 200 - 800
    18 200 - 800?
   
    Observation:
      c++11 does not work
      enuns don't work
*/
#include <ax12.h>
#include <Servo.h>
#include <timer.h>
#include <Joint.h>

const int button_1 = 3;
const int button_2 = 4;
const int button_3 = 5;

Servo servo_1;
Servo servo_2;
Servo servo_3;

Joint rotation(12,5);
Joint shoulder_1(13, 5);
Joint shoulder_2(14, 5);
Joint elbow_1(15, 5);
Joint elbow_2(16, 5);
Joint wrist_v(17, 5);
Joint wrist_h(18, 5);

void setup()
{
    Serial.begin(9600);

    servo_1.attach(0);
    servo_2.attach(1);
    servo_3.attach(2);

    pinMode(button_1, INPUT);
    pinMode(button_2, INPUT);
    pinMode(button_3, INPUT);

    hand(0, 0, 0);

    rotation.center();
    shoulder_1.center();
    shoulder_2.center();
    elbow_1.center();
    elbow_2.center();
    wrist_h.center();
    wrist_v.center();
}
int get_input()
{
    if (digitalRead(button_1) == HIGH)
        return 0;
    else if (digitalRead(button_2) == HIGH)
        return 1;
    else if (digitalRead(button_3) == HIGH)
        return 2;
    else
        return 3;
}

void hand(int upper, int middle, int lower)
{
    servo_1.write(upper);
    servo_2.write(middle);
    servo_3.write(lower);
}

void loop()
{
    int state = get_input()
    
    if (state == 0)
    {
        shoulder_1.move(800);
        shoulder_2.move(800);

        hand(0, 0, 0);
    }
    else if (state == 1)
    {
        hand(180, 180, 180);
    }
    else if (state == 2)
    {
        hand(180, 180, 0);
    }
}
