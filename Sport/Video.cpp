#include "Video.h"
#include "opencv2/opencv.hpp"
#include "QTimer.h"
#include "VideoSlider.h"
#include"VideoLabel.h"
using namespace cv;
using namespace std;

Video::Video()
	: QWidget()
{
	videoUi.setupUi(this);
	//videoUi.videoLabelShow->setScaledContents(true);
	frameGap = new QTimer(this);
	ptrKNN = createBackgroundSubtractorKNN(200, 300, true);
	//setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);//设置子窗口属性
	//videoSlider = new VideoSlider(this);
	//videoUi.verticalLayout->addWidget(videoSlider);
	//this->setParent(parent);
	//connect(updataFrame, SIGNAL(timeout()), this, SLOT(vedioshow()));
	//connect(videoUi.pushButton,SIGNAL(clicked()),this,SLOT(showVideo()));
	//connect(videoUi.pushButton, &QPushButton::clicked, this, &Video::showVideo);
	connect(videoUi.openVideoButton, &QPushButton::clicked, this, &Video::openVideo);
	connect(videoUi.firstFrameButton, &QPushButton::clicked, this, &Video::setFirstFrame);
	connect(videoUi.finalButton, &QPushButton::clicked, this, &Video::setFinalFrame);
	connect(videoUi.leftFrameButton, &QPushButton::clicked, [=]() {
		currentFrame--;
		showCurrentFrame(currentFrame);
		frameGap->stop();
		});
	connect(videoUi.rightButton, &QPushButton::clicked, [=]() {
		currentFrame++;
		showCurrentFrame(currentFrame);
		frameGap->stop();
		});
	connect(videoUi.quitButton, &QPushButton::clicked, this, &Video::playOrDisplay);

	connect(frameGap, &QTimer::timeout, [=]() {
		if (videoUi.backPushButton->isCheckable()) {
			currentFrame++;
		}
		else {
			currentFrame--;
		}
		showCurrentFrame(currentFrame);
		});
	connect(videoUi.videoSlider, &VideoSlider::valueChanged, this, &Video::sliderChangeValue);
	connect(videoUi.frameStepBox, &QDoubleSpinBox::valueChanged, this, &Video::frameStepValue);
	connect(videoUi.newButton, &QPushButton::clicked, [=]() {
		currentFrame = 0;
		videoUi.backPushButton->setCheckable(true);
		showCurrentFrame(currentFrame); });
	connect(videoUi.backPushButton, &QPushButton::clicked, [=]() {
		videoUi.backPushButton->setCheckable(!videoUi.backPushButton->isCheckable()); });
}

Video::~Video()
{}
void Video::frameStepValue()
{
	frameGap->stop();
	frequency = int(frequency / videoUi.frameStepBox->value());
	frameGap->start(frequency);
}
void Video::sliderChangeValue()
{
	currentFrame = videoUi.videoSlider->value();
	showCurrentFrame(currentFrame);
}
void Video::playOrDisplay()
{
	showCurrentFrame(currentFrame);
	if (frameGap->isActive() == true)
	{
		frameGap->stop();
	}
	else
	{
		frameGap->start(frequency);
	}
}
void Video::setFirstFrame()
{
	currentFrame = 0;
	showCurrentFrame(currentFrame);
	frameGap->stop();
}
void Video::setFinalFrame()
{
	currentFrame = allFrame - 1;
	showCurrentFrame(currentFrame);
	frameGap->stop();
}
String Video::setFileName(String fileName)
{
	this->fileName = fileName;
	return fileName;
}
void Video::openVideo()
{
	fileName = "C:\\Users\\zrs-run\\Desktop\\7.mp4";//待改
	currentFrame = 0;
	rawVideo.open(fileName);
	allFrame = (int)rawVideo.get(cv::CAP_PROP_FRAME_COUNT);
	frequency = 1000 / rawVideo.get(CAP_PROP_FPS);//待改
	frameGap->start(frequency);
	videoUi.videoSlider->setMinimum(0);
	videoUi.videoSlider->setMaximum(allFrame - 1);
	videoUi.frameStepBox->setValue(1);
	videoUi.frameStepBox->setMinimum(0.01);
	videoUi.frameStepBox->setSingleStep(0.5);
	videoUi.frameStepBox->setMaximum(5);
	videoUi.backPushButton->setCheckable(true);
}
void Video::getVideo()
{
	currentFrame = 0;
	rawVideo.open(fileName);
	allFrame = (int)rawVideo.get(cv::CAP_PROP_FRAME_COUNT);
	frequency = 1000 / rawVideo.get(CAP_PROP_FPS);//待改
}

void Video::showCurrentFrame(int i)
{
	if (currentFrame == -1)
	{
		currentFrame++;
		showCurrentFrame(currentFrame);
		return;
	}
	else if (currentFrame == allFrame)
	{
		currentFrame--;
		showCurrentFrame(currentFrame);
		return;
	}
	rawVideo.set(cv::CAP_PROP_POS_FRAMES, i);
	rawVideo >> frame;
	if (frame.empty())//如果视频已经读取完成则停止发送timeout()信号
	{
		return;
	}
	temp = QImage((uchar*)(frame.data), frame.cols, frame.rows, QImage::Format_BGR888);
	videoUi.videoLabelShow->clear();
	videoUi.videoLabelShow->setPixmap(QPixmap::fromImage(temp));
	videoUi.videoLabelShow->rawPix->fromImage(temp);
	videoUi.videoLabelShow->pix->fromImage(temp);
	videoUi.videoLabelShow->resize(temp.size());
	videoUi.videoLabelShow->show();
	videoUi.videoSlider->setValue(currentFrame);
}
void Video::getCurrentFrame(int i)
{
	if (currentFrame == -1)
	{
		currentFrame++;
		getCurrentFrame(currentFrame);
		return;
	}
	else if (currentFrame == allFrame)
	{
		currentFrame--;
		getCurrentFrame(currentFrame);
		return;
	}
	rawVideo.set(cv::CAP_PROP_POS_FRAMES, i);
	rawVideo >> frame;
	if (frame.empty())//如果视频已经读取完成则停止发送timeout()信号
	{
		return;
	}
	temp = QImage((uchar*)(frame.data), frame.cols, frame.rows, QImage::Format_BGR888);
}
void Video::bkgExtractFrame(int i)
{
	if (currentFrame == -1)
	{
		currentFrame++;
		showCurrentFrame(currentFrame);
		return;
	}
	else if (currentFrame == allFrame)
	{
		currentFrame--;
		showCurrentFrame(currentFrame);
		return;
	}
	rawVideo.set(cv::CAP_PROP_POS_FRAMES, i);
	rawVideo >> frame;
	if (frame.empty())//如果视频已经读取完成则停止发送timeout()信号
	{
		return;
	}
	ptrKNN->apply(frame, bgMask_KNN);
	//ptrKNN->getBackgroundImage(background);
	Mat th, eh, dh;
	//cv::adaptiveThreshold(bgMask_KNN.clone(),th, 255, cv::THRESH_BINARY_INV, cv::ADAPTIVE_THRESH_GAUSSIAN_C, 7, 8);
	cv::threshold(bgMask_KNN.clone(), th, 120, 255, cv::THRESH_BINARY);
	//cv::erode(th, eh, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3)), cv::Point(-1, -1), 2);
	//cv::dilate(eh, dh, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(9, 9)), cv::Point(-1, -1), 2);
	//cv::morphologyEx(th, eh, cv::MORPH_OPEN, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(2, 2)), cv::Point(-1, -1), 2);
	cv::morphologyEx(th, eh, cv::MORPH_CLOSE, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 5)), cv::Point(-1, -1), 2);
	cv::morphologyEx(th, background, cv::MORPH_OPEN, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(2, 2)), cv::Point(-1, -1), 2);
	//cv::threshold(dh, background, 60, 255, cv::THRESH_BINARY);
	//background = dh;
	//frame.copyTo(bgMask_KNN, dh);

	//mask.append(m);
	//m = frame.mul(th);
		//imshow("background_by_KNN", background);
	//QImage temp1 = QImage((uchar*)(background.data), background.cols, background.rows, QImage::Format_RGB888);
	//videoUi.videoLabelShow->setPixmap(QPixmap::fromImage(temp1));
	//videoUi.videoLabelShow->resize(temp1.size());
	//videoUi.videoLabelShow->show();
	//QImage temp2 = QImage((uchar*)(bgMask_KNN.data), bgMask_KNN.cols, bgMask_KNN.rows, QImage::Format_Grayscale8);
	//QImage temp2 = QImage((uchar*)(dh.data), dh.cols, dh.rows, QImage::Format_Grayscale8);
	//QImage temp2 = QImage((uchar*)(m.data), m.cols, m.rows, QImage::Format_BGR888);
	//QImage temp2 = QImage((uchar*)(bgMask_KNN.data), bgMask_KNN.cols, bgMask_KNN.rows, QImage::Format_BGR888);
	//QImage temp2 = QImage((uchar*)(th.data), th.cols, th.rows, QImage::Format_Grayscale8);

}