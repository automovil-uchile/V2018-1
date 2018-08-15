#include <EngineAdministrator.h>
#include <Engine.h>
#include <Car.h>

int pinStF = 13; //status input
int pinStN = 12; //status input
int pinStB = 11; //status input
int tc = 0; //traction control
int pinRET = 3; //right throttle output
int pinRES = 4; //right status output
int pinLET = 5; //left throttle output
int pinLES = 6; //left status output
int pinBrake = 8;
int pinAcc = 0;
float w = 1; //car width
float l = 2; // car length

Car Auto(pinAcc, pinBrake, pinStB, pinStN, pinStF, tc, pinRET, pinRES, pinLET, pinLES, w, l);

void setup()
{
	
	Serial.begin(9600);
}

void loop()
{
	//EA.startEngines();
  Auto.ReadSensors();
	Auto.ReadState(2);
	Auto.StateMachine();
  
  Serial.print(Auto.getBrake());
  Serial.print("\t");
  
  Serial.print(Auto.getAcc());
  
  Serial.print("\n");
	//delay(1000);
}

float deg2rad(float angle){
	return angle*3.14/180.;
}
