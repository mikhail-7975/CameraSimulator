#include "app.h"

CameraSimulatorApp::CameraSimulatorApp() :
	mouse_posX(0), mouse_posY(0)
{
	appName = "Camera simulator";
	cv::namedWindow(appName, cv::WINDOW_AUTOSIZE);
	cv::setMouseCallback(appName, OnMouseHandle, this);

	cv::createTrackbar("Focus distance: ", appName, &focusDistance, 300, OnBlurParamsChanged);
	cv::createTrackbar("Apperture: ", appName, &apperture, 50, OnBlurParamsChanged);
	displaySize.height = 100;
	displaySize.width = 100;
}

void CameraSimulatorApp::start()
{
	cameraImage = cv::imread("Canon 700D.jpg");
	if (cameraImage.empty()) {
		std::cout << "Can't open camera image" << std::endl;
		return;
	}

	_img = cv::imread("1.jpg");
	if (_img.empty()) {
		std::cout << "Can't open image" << std::endl;
		return;
	}

	cv::imshow(appName, cameraImage);
}

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
	setFocusDistance(focusDistance);
	setApperture(apperture);

	cv::Mat newImg = _cam.takePhoto(_img);
	cv::Mat resizedImg;
	cv::resize(newImg, resizedImg, displaySize);
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