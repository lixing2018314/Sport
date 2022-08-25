#include "VideoLabel.h"
#include"qevent.h"
#include"qapplication.h"
#include"QPainter.h"
#include"VideoLabel.h"
VideoLabel::VideoLabel(QWidget* parent)
    : QLabel(parent),
    Alloffset(0, 0)
{

    ratio = 1.0;             //��ʼ��ͼƬ���ű���
    action = VideoLabel::None;
    pixW = 985;            //����ͼƬ�ߴ�Ϊ985*740
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
//        //�ж�����Ƿ����������,�����λ���Ƿ��ڻ滭����
//        if (mouse->button() == Qt::LeftButton && this->geometry().contains(mouse->pos()))
//        {
//            press = true;
//            QApplication::setOverrideCursor(Qt::OpenHandCursor); //���������ʽ
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
//        //�ж�����Ƿ�������ͷ�,��֮ǰ���ڻ滭����
//        if (mouse->button() == Qt::LeftButton && press)
//        {
//            QApplication::setOverrideCursor(Qt::ArrowCursor); //�Ļ������ʽ
//            press = false;
//        }
//    }
//
//    if (event->type() == QEvent::MouseMove)              //�ƶ�ͼƬ
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

void VideoLabel::wheelEvent(QWheelEvent* event)     //��껬���¼�
{
    if (event->angleDelta().y() > 0) {      //�ϻ�,��С
        action = VideoLabel::Shrink;
        this->update();

    }
    else {                    //�»�,�Ŵ�
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
//    if (action == VideoLabel::Amplification)           //��С
//    {
//        ratio -= 0.1 * ratio;
//        if (ratio < 0.18)
//            ratio = 0.1;
//
//
//    }
//    else  if (action == VideoLabel::Shrink)           //�Ŵ�
//    {
//
//        ratio += 0.1 * ratio;
//        if (ratio > 4.5)
//            ratio = 5.000;
//
//
//    }
//    if (action == VideoLabel::Amplification || action == VideoLabel::Shrink)      //����ͼƬ
//    {
//        NowW = ratio * pixW;
//        NowH = ratio * pixH;
//        //pix->load("D:/tu/test2.jpg");                 //����װ��,��Ϊ֮ǰ��ͼƬ�Ѿ������Ź�
//        *pix = rawPix->scaled(NowW, NowH, Qt::KeepAspectRatio);
//   
//        action = VideoLabel::None;
//
//    }
//
//    if (action == VideoLabel::Move)                    //�ƶ�
//    {
//        int offsetx = Alloffset.x() + offset.x();
//        Alloffset.setX(offsetx);
//
//        int offsety = Alloffset.y() + offset.y();
//        Alloffset.setY(offsety);
//        action = VideoLabel::None;
//    }
//
//    if (abs(Alloffset.x()) >= (this->width() / 2 + NowW / 2 - 10))    //����Xƫ��ֵ
//    {
//        if (Alloffset.x() > 0)
//            Alloffset.setX(this->width() / 2 + NowW / 2 - 10);
//        else
//            Alloffset.setX(-this->width() / 2 + -NowW / 2 + 10);
//    }
//    if (abs(Alloffset.y()) >= (this->height() / 2 + NowH / 2 - 10))    //����Yƫ��ֵ
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
//    //this.drawRect(this->x() - 1, this->y() - 1, this->width() + 1, this->height() + 1); //����
//    //painter.drawTiledPixmap(x + this->x(), y + this->y(), w, h, *pix, sx, sy);             //�滭ͼ��
//}
