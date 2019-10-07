#include <ax12.h>
#include <BioloidController.h>
 
BioloidController bioloid = BioloidController(1000000);
 
int R12;
int R13;
int R14;
int R15;
int R16;
int R17;
int R18;
 
void setup(){
  Serial.begin(9600);
// Initially moving all servos to default position.
  SetPosition(12, 512);
  SetPosition(13, 512);
  SetPosition(14, 512);
  SetPosition(15, 512);
  SetPosition(16, 512);
  SetPosition(17, 512);
  SetPosition(18, 512);
  delay(100);
// Turning torque off of the servos on one arm.
  Relax(12);    
  Relax(13);
  Relax(14);
  Relax(15);
  Relax(16);
  Relax(17);
  Relax(18);
  delay(1000);
}
 
void loop(){
// Reading "Present Position" register value, writing it to variable
  Serial.println(ax12GetRegister(12, 36, 2));
  Serial.println(ax12GetRegister(13, 36, 2));
  Serial.println(ax12GetRegister(14, 36, 2));
  Serial.println(ax12GetRegister(15, 36, 2));
  Serial.println(ax12GetRegister(16, 36, 2));
  Serial.println(ax12GetRegister(17, 36, 2));
  Serial.println(ax12GetRegister(18, 36, 2));
  Serial.println();

  delay(5000);
}
