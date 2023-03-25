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

    loadingGif = new QMovie(":loading.gif");
    this->setMovie(loadingGif);
    loadingGif->start();

    QObject::connect(fileDownloader, &FileDownloader::downloaded,
                     this, &QClickableImage::updatePixmap);
}


void QClickableImage::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}

void QClickableImage::updatePixmap()
{
    loadingGif->stop();
    delete loadingGif;

    image.loadFromData(fileDownloader->downloadedData());
    this->setPixmap(image.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}
