#include "app.h"

void CameraSimulatorApp::setLense(LenseInterface& lense)
{
	_cam.setLense(lense);
}
 
void CameraSimulatorApp::setCamera(camera cam)
{
	_cam = cam;
} 

void CameraSimulatorApp::setFocusDistance(size_t focDst)
{
	_cam.setFocusDistance(focDst);
}
 
void CameraSimulatorApp::setApperture(double apperture)
{
	_cam.setApperture(apperture);
}

void CameraSimulatorApp::update()
{
	cv::Mat newImg = _cam.takePhoto(_img);
	cv::Mat resizedImg;
	//cv::resize(newImg, resizedImg, displaySize);
}

void CameraSimulatorApp::OnMouseHandle(int event, int x, int y, int, void* instance)
{
	if (instance == nullptr) return;
	reinterpret_cast<CameraSimulatorApp*>(instance)->OnMouseHandleInner(x, y);
}

void CameraSimulatorApp::OnMouseHandleInner(int x, int y)
{
	std::cout << x << ' ' << y << std::endl;
	mouse_posX = x;
	mouse_posY = y;

	update();
}

void CameraSimulatorApp::OnBlurParamsChanged(int x, void* instance)
{
	if (instance == nullptr) return;
	reinterpret_cast<CameraSimulatorApp*>(instance)->update();
}