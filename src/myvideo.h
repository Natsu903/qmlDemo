#ifndef MYVIDEO_H
#define MYVIDEO_H

#include <QImage>
#include <QQmlEngine>
#include <QQuickPaintedItem>
#include <opencv2/opencv.hpp>

class MyVideo : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
public:
    Q_INVOKABLE bool open(QString filename);
    Q_INVOKABLE QVariant readFrame();
    Q_INVOKABLE void paintFrame(QVariant frame);
    MyVideo(QQuickPaintedItem *parent=nullptr);
    void paint(QPainter *painter) override;

signals:
    void readEnd();

private:
    std::unique_ptr<cv::VideoCapture> video_;
    cv::Mat frame_;
    QImage img_;
};

#endif // MYVIDEO_H
