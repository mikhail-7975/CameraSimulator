#pragma once

#include "ImageFacade.h"

#include "opencv2/opencv.hpp"

class LenseInterface {
public:
	LenseInterface() = default;
	virtual ~LenseInterface() = default;
	
	virtual cv::Mat Execute(const cv::Mat& rawImage) = 0;

	virtual const size_t getMaxFocusDistanse() const = 0;
	virtual const size_t getMinFocusDistanse() const = 0;

	virtual const double getMaxApperture() const = 0;
	virtual const double getMinApperture() const = 0;

	virtual void setFocusDistance(size_t focDist) = 0;

	virtual void setApperture(double apperture) = 0;
};