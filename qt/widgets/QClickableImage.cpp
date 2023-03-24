//
// Created by Quentin Gillet on 23/03/2023.
//

#include "QClickableImage.h"


QClickableImage::QClickableImage(QString* url, QWidget *parent)
{
    if(url == nullptr)
        return;
    this->setScaledContents(true);

    QUrl imageUrl(*url);
    fileDownloader = new FileDownloader(imageUrl, this);

    QTimer timer;
    timer.setSingleShot(true);
    QEventLoop loop;

    QObject::connect(fileDownloader, &FileDownloader::downloaded,
                     &loop, &QEventLoop::quit);
    QObject::connect(&timer, &QTimer::timeout,
                     &loop, &QEventLoop::quit);
    timer.start(1000);
    loop.exec();

    if(!timer.isActive())
    {
        qDebug() << "Error while loading " << *url;
        return;
    }

    image.loadFromData(fileDownloader->downloadedData());
    this->setPixmap(image.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}


void QClickableImage::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}