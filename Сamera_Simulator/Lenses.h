#pragma once

#include "LenseInterface.h"

#include "opencv2/opencv.hpp"

#include <string>
/*class LenseInterface {
public:
	LenseInterface() = default;
	virtual ~LenseInterface() = default;
	
	virtual void Execute(ImageFacade& rawImage) = 0;

	virtual const double getMaxFocusDistanse() const = 0;
	virtual const double getMinFocusDistanse() const = 0;

	virtual const double getMaxApperture() const = 0;
	virtual const double getMinApperture() const = 0;
};*/

class Lense_18_55_f_3_5 final: public LenseInterface {
public:
	Lense_18_55_f_3_5() = default;
	virtual ~Lense_18_55_f_3_5() = default;

	cv::Mat Execute(const cv::Mat& rawImage) override;

	const size_t getMaxFocusDistanse() const override;
	const size_t getMinFocusDistanse() const override;

	const double getMaxApperture() const override;
	const double getMinApperture() const override;

	void setFocusDistance(size_t focDist) override;

	void setApperture(double apperture) override;

	std::string name();
private:
	const std::string _name = "Canon 18-55 f/3.5";
	size_t _currentFocusDistanse;
	size_t _currentApperture;
};