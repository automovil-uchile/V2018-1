#include "Arduino.h"
#include "Engine.h"
#include "EngineAdministrator.h"
#include <math.h>

EngineAdministrator::EngineAdministrator(int pinRET, int pinRES, int pinLET, int pinLES, float w, float l)
{
	_rightEngine = Engine("right", pinRET, pinRES);
	_leftEngine = Engine("left", pinLET, pinLES);
	_w = w;
	_l = l;
	_state = 0;
	_accL = 0;
	_accR = 0;
	_a = 0;
}

void EngineAdministrator::startEngines()
{
	_rightEngine.start();
	_leftEngine.start();
}

void EngineAdministrator::stopEngines()
{
	_rightEngine.stop();
	_leftEngine.stop();
}

void EngineAdministrator::differential(float angle, float acc){
	if (angle>0){
		//left curve
		_a = _l/tan(angle);
		_accR = acc;
		_accL = acc*(_a - _w/_l)/(_a + _w/_l);
	}
	else if (angle<0){
		//right curve
		_a = _l/tan(angle);
		_accL = acc;
		_accR = acc*(_a + _w/_l)/(_a - _w/_l);
	}
	else{
		_accL = acc;
		_accR = acc;
	}
}

/*
  Diferencial 
*/


/* LEFT

def set_vel(self, v, ang):
        ang = ang*np.pi/180
        a = self.l/(np.tan(ang) + 1e-5)
        self.vel = v*(1 - self.w/2/a)

*/

/* RIGHT

def set_vel(self, v, ang):
        ang = ang*np.pi/180
        a = self.l/(np.tan(ang) + 1e-5)
        self.vel = v*(1 + self.w/2/a)

*/



/*
void EngineAdministrator::setMarcha(int marcha)
{
	_marcha = marcha;
}

void EngineAdministrator::getVelocity()
{
	return _velocity;
}

void EngineAdministrator::getMarcha()
{
	return _marcha;
}
*/