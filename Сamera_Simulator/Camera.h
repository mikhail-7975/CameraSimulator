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
	void setLense(LenseInterface& Lense) {}; //��������� ��������
	void setRawImage(cv::Mat& rawImage) {};

	cv::Mat takePhoto(cv::Mat& _rawImage); //"����������" ����������� ����� ��������. 
	void showReadyImage() {};//�������� ������� �����������

	void setFocusDistance(size_t focusDist);
	void setApperture(double apperture);

	std::string name() {
		return _name;
	}

	//camera& operator=(const camera&); 
private:
	std::string _name;
	LenseInterface* _Lense;
	//cv::Mat* _rawImage; //�����������, ������� ����� ����
	//cv::Mat* _reagyImage; //�����������, ������� ���������� ����� ����������� ����� ��������
};