#include "VideoSlider.h"
#include <QMouseEvent>

VideoSlider::VideoSlider(QWidget* parent)
    : QSlider(parent)
{
    //sliderUi.setupUi();

}

VideoSlider::~VideoSlider()
{}
void VideoSlider::mousePressEvent(QMouseEvent* ev)
{
    //��ȡ��ǰ���λ��,�õ�������������������ڵ�ǰQSlider������
    int currentX = ev->pos().x();

    //��ȡ��ǰ�����λ��ռ����Slider�İٷֱ�
    double per = currentX * 1.0 / this->width();

    //������õİٷֱȵõ���������
    int value = per * (this->maximum() - this->minimum()) + this->minimum();

    //qDebug() << value;

    //�趨������λ��
    this->setValue(value);

    //�������ƶ��¼����¼�Ҳ�õ���mousePressEvent,����仰��Ϊ�˲��������Ӱ�죬�ǵ�Slider��������Ӧ��������¼�
    QSlider::mousePressEvent(ev);

}