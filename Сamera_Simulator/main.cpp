#include "Camera.h"
#include "Lenses.h"
#include "app.h"

int main() {
	Lense_18_55_f_3_5 lense_1;

	camera Canon700D;

	Canon700D.setLense(lense_1);
	
	CameraSimulatorApp a;
	a.setCamera(Canon700D);
	a.start();
}