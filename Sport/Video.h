
#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Video.h"
#include "opencv2/opencv.hpp"
#include "VideoSlider.h"
#include"VideoLabel.h"
#include"qvector.h"
using namespace cv;

class Video : public QWidget
{
	Q_OBJECT

public:
	Video();
	~Video();
	//cv::VideoCapture getRawVideo();
	String setFileName(String fileName);
	void showVideo();
	//void closeVideo();
	String fileName;
	int currentFrame, allFrame, frequency;
	cv::VideoCapture rawVideo;
	void openVideo();
	void showCurrentFrame(int i);
	void getCurrentFrame(int i);
	void setFirstFrame();
	void setFinalFrame();
	void playOrDisplay();
	void sliderChangeValue();
	void frameStepValue();
	void bkgExtractFrame(int i);
	void getVideo();
	QImage temp;
	Mat frame, bgMask_KNN, background;
	//QVector<Mat> mask;
	Ptr<BackgroundSubtractor> ptrKNN;

	//QTimer* updataFrame = new QTimer();
private:
	Ui::VideoClass videoUi;
	QTimer* frameGap;
	//VideoSlider *videoSlider;
};
