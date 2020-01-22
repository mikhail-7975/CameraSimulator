#pragma once
#include "Camera.h"

class CameraSimulatorApp final {
public:
	CameraSimulatorApp();
	~CameraSimulatorApp();

	void setLense(LenseInterface& lense);
	void setCamera(camera cam);

	void setFocusDistance(size_t focDst);
	void setApperture(double apperture);
private:
	void update();

	static void		OnMouseHandle(int event, int x, int y, int, void* instance);
	void			OnMouseHandleInner(int x, int y);

	static void		OnBlurParamsChanged(int x, void* instance);

	camera _cam;
	cv::Mat _img;
	cv::Size displaySize;
	cv::Mat cameraImage;

	int mouse_posX, mouse_posY;
};