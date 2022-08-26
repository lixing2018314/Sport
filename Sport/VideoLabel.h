#pragma once
#include <QObject>
#include <QLabel>
//#include"Video.h"

class VideoLabel : public QLabel
{
    Q_OBJECT

public:
    VideoLabel(QWidget* parent = nullptr);
    ~VideoLabel();
    enum  Type {
        None = 0,
        Amplification,
        Shrink,
        Lift,
        Right,
        Up,
        Down,
        Move
    };
    QPixmap* pix;
    QPixmap* rawPix;

    int action;          //����(�Ŵ�,��С,�ƶ�...)
    int pixW;            //ͼƬ��
    int pixH;            //ͼƬ��


    //QLabel label;
    QPoint mouseLocation;
    float ratio;                //����
    QPoint offset;              //һ�ε�ͼƬƫ��ֵ
    QPoint Alloffset;           //��ƫ��

    //void AddComboItem(QComboBox* cmbo);
    //bool event(QEvent* event);
    void wheelEvent(QWheelEvent* e);     //��껬���¼�

    void mouseDoubleClickEvent(QMouseEvent* event);

    //Video* video;
//private slots:
    //void paintEvent(QPaintEvent* event);

};
