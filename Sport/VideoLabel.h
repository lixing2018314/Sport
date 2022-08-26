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

    int action;          //动作(放大,缩小,移动...)
    int pixW;            //图片宽
    int pixH;            //图片高


    //QLabel label;
    QPoint mouseLocation;
    float ratio;                //比例
    QPoint offset;              //一次的图片偏移值
    QPoint Alloffset;           //总偏移

    //void AddComboItem(QComboBox* cmbo);
    //bool event(QEvent* event);
    void wheelEvent(QWheelEvent* e);     //鼠标滑轮事件

    void mouseDoubleClickEvent(QMouseEvent* event);

    //Video* video;
//private slots:
    //void paintEvent(QPaintEvent* event);

};
