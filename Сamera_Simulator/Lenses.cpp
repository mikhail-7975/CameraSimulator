#include "Lenses.h"

cv::Mat Lense_18_55_f_3_5::Execute(const cv::Mat& rawImage)
{
	return cv::Mat();
}

const size_t Lense_18_55_f_3_5::getMaxFocusDistanse() const
{
	return 18;
}

const size_t Lense_18_55_f_3_5::getMinFocusDistanse() const
{
	return 55;
}

const double Lense_18_55_f_3_5::getMaxApperture() const
{
	return 3.5;
}

const double Lense_18_55_f_3_5::getMinApperture() const
{
	return 25;
}

void Lense_18_55_f_3_5::setFocusDistance(size_t focDist)
{
	if (_currentFocusDistanse + focDist <= getMaxFocusDistanse())
		_currentFocusDistanse += focDist;
}


void Lense_18_55_f_3_5::setApperture(double apperture)
{
}

std::string Lense_18_55_f_3_5::name()
{
	return _name;
}

