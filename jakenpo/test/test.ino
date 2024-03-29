/*
ax12.h
	ax12SetRegister
	ax12GetRegister
	ax12SetRegister2
	ax12GetRegister2
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
    13 - 18: 200 - 800
	
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

const int vel = 100;

Servo servo_1;
Servo servo_2;
Servo servo_3;

void move(int a1,int a2,int a3,int a4,int a5,int a6, int a7)
{
  
	SetPosition(12,a1);
	SetPosition(13,a2);
	SetPosition(14,a3);
	SetPosition(15,a4);
	SetPosition(16,a5);
	SetPosition(17,a6);
	SetPosition(18,a7);
	
	ax12SetRegister2(12, 32, vel);
	ax12SetRegister2(13, 32, vel);
	ax12SetRegister2(14, 32, vel);
	ax12SetRegister2(15, 32, vel);
	ax12SetRegister2(16, 32, vel);
	ax12SetRegister2(17, 32, vel);
	ax12SetRegister2(18, 32, vel);
}

bool is_pos(int a1,int a2,int a3,int a4,int a5,int a6, int a7)
{
	Serial.println(GetPosition(12));
	Serial.println(GetPosition(13));
	Serial.println(GetPosition(14));
	Serial.println(GetPosition(15));
	Serial.println(GetPosition(16));
	Serial.println(GetPosition(17));
	Serial.println(GetPosition(18));
	Serial.println();

    return ( GetPosition(12) == a1 
		&& GetPosition(13) == a2 && GetPosition(14) == a3 
		&& GetPosition(15) == a4 && GetPosition(16) == a5 
		&& GetPosition(17) == a6 && GetPosition(18) == a7);
}

void center()
{
	move(512,512,512,512,512,512,512);
	while(!is_pos(512,512,512,512,512,512,512)){}
		
}

void hello()
{
	int m_12[] = {486,480,512,482,515,482,515};
	int m_13[] = {442,439,442,439,442,439,442};
	int m_14[] = {577,582,578,582,578,582,578};
	int m_15[] = {635,619,589,619,589,619,589};
	int m_16[] = {391,404,432,404,432,404,432};
	int m_17[] = {635,639,639,639,639,639,639};
	int m_18[] = {506,228,645,228,645,228,645};
	inr deay[] = {800,800,800,800,800,800,800};
	int siz = 7

	for(int i = =;i<siz;i++)
	{
		move(m_12[i],m_13[i],m_14[i],m_15[i],m_16[i],m_17[i],m_18[i]);
		delay(deay);
	}		
}

void jaken()
{
	int m_12[] = {475,474,460,474,460,474,460};
	int m_13[] = {662,660,677,660,677,660,677};
	int m_14[] = {361,366,344,366,344,366,344};
	int m_15[] = {599,735,567,735,567,735,567};
	int m_16[] = {423,290,457,290,457,290,457};
	int m_17[] = {608,800,643,800,643,800,643};
	int m_18[] = {524,800,643,800,643,800,643};
	inr deay[] = {800,800,800,800,800,800,800};
	int siz = 7

	for(int i = =;i<siz;i++)
	{
		move(m_12[i],m_13[i],m_14[i],m_15[i],m_16[i],m_17[i],m_18[i]);
		delay(deay);
	}	
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
		jaken();
	
        hand(180, 180, 0);
    }
}
