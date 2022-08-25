#pragma once

#include <QObject>
#include <QSlider>

class VideoSlider : public QSlider
{
	Q_OBJECT

public:
	VideoSlider(QWidget* parent = nullptr);
	~VideoSlider();

	//private:
	void mousePressEvent(QMouseEvent* ev);

	//Ui::VideoSliderClass sliderUi;
};
