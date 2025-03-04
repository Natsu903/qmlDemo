#include "myvideo.h"

#include <QPainter>

bool MyVideo::open(QString filename)
{
    auto re = video_->open(filename.toStdString());
    if(re)
    {
        img_=QImage(width(),height(),QImage::Format_BGR888);
    }
    return re;
}

QVariant MyVideo::readFrame()
{
    QVariant re;
    if(!video_->read(frame_))
    {
        emit readEnd();
        return re;
    }
    re=QVariant::fromValue(frame_);
    return re;
}

void MyVideo::paintFrame(QVariant frame)
{
    auto src=frame.value<cv::Mat>();
    if(src.empty()) return;
    cv::Mat view;
    cv::resize(src,view,cv::Size(img_.width(),img_.height()));
    memcpy(img_.bits(),view.data,view.cols*view.rows*view.elemSize());
    update();
}

MyVideo::MyVideo(QQuickPaintedItem *parent)
{
    qDebug()<<"Create MyVideo";
    video_.reset(new cv::VideoCapture);
}

void MyVideo::paint(QPainter *painter)
{
    if(!img_.isNull())
    {
        painter->drawImage(QPoint(0,0),img_);
    }
}
