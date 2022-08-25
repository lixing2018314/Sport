#include "VideoLabel.h"
#include"qevent.h"
#include"qapplication.h"
#include"QPainter.h"
#include"VideoLabel.h"
VideoLabel::VideoLabel(QWidget* parent)
    : QLabel(parent),
    Alloffset(0, 0)
{

    ratio = 1.0;             //初始化图片缩放比例
    action = VideoLabel::None;
    pixW = 985;            //设置图片尺寸为985*740
    pixH = 740;
    //video = new Video;
}

VideoLabel::~VideoLabel()
{}
void VideoLabel::mouseDoubleClickEvent(QMouseEvent* event)
{
    QMouseEvent* mouse = dynamic_cast<QMouseEvent*>(event);
    this->mouseLocation = mouse->pos();
}
//bool VideoLabel::event(QEvent* event)
//{
//    static bool press = false;
//    static QPoint PreDot;
//
//    if (event->type() == QEvent::MouseButtonPress)
//    {
//        QMouseEvent* mouse = dynamic_cast<QMouseEvent*>(event);
//        
//        //判断鼠标是否是左键按下,且鼠标位置是否在绘画区域
//        if (mouse->button() == Qt::LeftButton && this->geometry().contains(mouse->pos()))
//        {
//            press = true;
//            QApplication::setOverrideCursor(Qt::OpenHandCursor); //设置鼠标样式
//
//            PreDot = mouse->pos();
//            this->mouseLocation = mouse->pos();
//        }
//
//    }
//    else if (event->type() == QEvent::MouseButtonRelease)
//    {
//        QMouseEvent* mouse = dynamic_cast<QMouseEvent*>(event);
//
//        //判断鼠标是否是左键释放,且之前是在绘画区域
//        if (mouse->button() == Qt::LeftButton && press)
//        {
//            QApplication::setOverrideCursor(Qt::ArrowCursor); //改回鼠标样式
//            press = false;
//        }
//    }
//
//    if (event->type() == QEvent::MouseMove)              //移动图片
//    {
//        if (press)
//        {
//            QMouseEvent* mouse = dynamic_cast<QMouseEvent*>(event);
//
//            offset.setX(mouse->x() - PreDot.x());
//            offset.setY(mouse->y() - PreDot.y());
//            PreDot = mouse->pos();
//            action = VideoLabel::Move;
//            this->update();
//        }
//    }
//    return QWidget::event(event);
//}

void VideoLabel::wheelEvent(QWheelEvent* event)     //鼠标滑轮事件
{
    if (event->angleDelta().y() > 0) {      //上滑,缩小
        action = VideoLabel::Shrink;
        this->update();

    }
    else {                    //下滑,放大
        action = VideoLabel::Amplification;
        this->update();
    }

    event->accept();
}



//void VideoLabel::paintEvent(QPaintEvent* event)
//{
//    //QPainter painter(this);
//    int NowW = ratio * pixW;
//    int NowH = ratio * pixH;
//
//    if (action == VideoLabel::Amplification)           //缩小
//    {
//        ratio -= 0.1 * ratio;
//        if (ratio < 0.18)
//            ratio = 0.1;
//
//
//    }
//    else  if (action == VideoLabel::Shrink)           //放大
//    {
//
//        ratio += 0.1 * ratio;
//        if (ratio > 4.5)
//            ratio = 5.000;
//
//
//    }
//    if (action == VideoLabel::Amplification || action == VideoLabel::Shrink)      //更新图片
//    {
//        NowW = ratio * pixW;
//        NowH = ratio * pixH;
//        //pix->load("D:/tu/test2.jpg");                 //重新装载,因为之前的图片已经被缩放过
//        *pix = rawPix->scaled(NowW, NowH, Qt::KeepAspectRatio);
//   
//        action = VideoLabel::None;
//
//    }
//
//    if (action == VideoLabel::Move)                    //移动
//    {
//        int offsetx = Alloffset.x() + offset.x();
//        Alloffset.setX(offsetx);
//
//        int offsety = Alloffset.y() + offset.y();
//        Alloffset.setY(offsety);
//        action = VideoLabel::None;
//    }
//
//    if (abs(Alloffset.x()) >= (this->width() / 2 + NowW / 2 - 10))    //限制X偏移值
//    {
//        if (Alloffset.x() > 0)
//            Alloffset.setX(this->width() / 2 + NowW / 2 - 10);
//        else
//            Alloffset.setX(-this->width() / 2 + -NowW / 2 + 10);
//    }
//    if (abs(Alloffset.y()) >= (this->height() / 2 + NowH / 2 - 10))    //限制Y偏移值
//    {
//        if (Alloffset.y() > 0)
//            Alloffset.setY(this->height() / 2 + NowH / 2 - 10);
//        else
//            Alloffset.setY(-this->height() / 2 + -NowH / 2 + 10);
//
//    }
//
//    int x = this->width() / 2 + Alloffset.x() - NowW / 2;
//    if (x < 0)
//        x = 0;
//
//
//    int y = this->height() / 2 + Alloffset.y() - NowH / 2;
//    if (y < 0)
//        y = 0;
//
//    int  sx = NowW / 2 - this->width() / 2 - Alloffset.x();
//    if (sx < 0)
//        sx = 0;
//
//    int  sy = NowH / 2 - this->height() / 2 - Alloffset.y();
//    if (sy < 0)
//        sy = 0;
//
//
//    int w = (NowW - sx) > this->width() ? this->width() : (NowW - sx);
//    if (w > (this->width() - x))
//        w = this->width() - x;
//
//    int h = (NowH - sy) > this->height() ? this->height() : (NowH - sy);
//    if (h > (this->height() - y))
//        h = this->height() - y;
//    this->setPixmap(*pix);
//    //this.drawRect(this->x() - 1, this->y() - 1, this->width() + 1, this->height() + 1); //画框
//    //painter.drawTiledPixmap(x + this->x(), y + this->y(), w, h, *pix, sx, sy);             //绘画图形
//}
