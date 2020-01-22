#include "Camera.h"

camera::camera()
{
	_name = "Canon 700D";
}

camera::camera(camera& cam)
{
	_name = cam._name;
	_Lense = cam._Lense;
}

cv::Mat camera::takePhoto(cv::Mat& _rawImage)
{
	return _Lense->Execute(_rawImage);
}

void camera::setFocusDistance(size_t focusDist)
{
	_Lense->setFocusDistance(focusDist);
}


void camera::setApperture(double apperture)
{
	_Lense->setApperture(apperture);
}
