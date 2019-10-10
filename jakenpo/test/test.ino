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

void move(int a1,int a2,int a3,int a4,int a5,int a6, int a7)
{
	SetPosition(12,a1);
	SetPosition(12,a2);
	SetPosition(12,a3);
	SetPosition(12,a4);
	SetPosition(12,a5);
	SetPosition(12,a6);
	SetPosition(12,a7);
}

void center()
{
    move(512,512,512,512,512,512,512);
    delay(800);
}

void hello()
{
	int m_12[] = {512,512,512,512,512,512,512,512};
	int m_13[] = {471,472,473,472,472,472,473,472};
	int m_14[] = {550,549,547,549,548,549,547,549};
	int m_15[] = {764,764,764,764,764,764,764,764};
	int m_16[] = {261,261,261,261,261,261,261,261};
	int m_17[] = {535,542,536,542,542,542,542,542};
	int m_18[] = {505,393,323,393,522,597,709,597};
	
	for(int i=0;i<8;i++)
	{
		move(m_12[i],m_12[i],m_12[i],m_12[i],m_12[i],m_12[i]);
		delay(40);
	}

}

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
    center();
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
    int state = get_input();

    if (state == 0)
    {
        hello();

        hand(0, 0, 0);
    }
    else if (state == 1)
    {

        center();
		
        hand(180, 180, 180);
    }
    else if (state == 2)
    {
        hand(180, 180, 0);
    }
}