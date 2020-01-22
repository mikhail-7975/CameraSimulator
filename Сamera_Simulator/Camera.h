#pragma once
#include "ImageFacade.h"
#include "LenseInterface.h"

#include "opencv2/opencv.hpp"
#include <opencv2/core/types.hpp>

#include <string>
#include <memory>

class camera { 
public:
	camera(std::string name);
	camera(camera& cam);
	void setLense(LenseInterface& Lense) {}; //поставить объектив
	void setRawImage(cv::Mat& rawImage) {};

	cv::Mat takePhoto(cv::Mat& _rawImage); //"пропустить" изображение через объектив. 
	void showReadyImage() {};//показать готовое изображение

	void setFocusDistance(size_t focusDist);
	void setApperture(double apperture);

	std::string name() {
		return _name;
	}

	//camera& operator=(const camera&); 
private:
	std::string _name;
	LenseInterface* _Lense;
	//cv::Mat* _rawImage; //изображение, которое видит глаз
	//cv::Mat* _reagyImage; //изображение, которое получается после прохождения через объектив
};