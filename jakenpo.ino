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

//timer to keep time and regulate internal actions
class Timer
{
    long start;
    long curr;

public:
    Timer()
    {
        restart();
    }

    double get_millis()
    {
        curr = millis();
        long diff = curr - start;

        return diff;
    }

    void restart()
    {
        start = millis();
        curr = start;
    }
};

class Joint
{
    int id;
    double velocity;
    int goal;
    int min_rotation, max_rotation;
    Timer timer;

public:
    Joint(int id, double vel, int min, int max)
    {
        this->id = id;
        velocity = vel;
        max_rotation = max;
        min_rotation = min;
    }

    void update()
    {
        if (timer.get_millis() > 1 / velocity)
        {
            int curr = GetPosition(id);

            if (goal < curr)
                SetPosition(id, curr + 1);
            if (goal > curr)
                SetPosition(id, curr - 1);

            timer.restart();
        }
    }
    void move(int pos)
    {
        if (pos < max_rotation && pos > min_rotation)
        {
            goal = pos;
        }
    }
    void relax()
    {
        Relax(id);
    }
}

const int button_1 = 3;
const int button_2 = 4;
const int button_3 = 5;

Servo servo_1;
Servo servo_2;
Servo servo_3;

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
