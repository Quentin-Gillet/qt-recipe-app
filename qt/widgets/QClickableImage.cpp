//
// Created by Quentin Gillet on 23/03/2023.
//

#include "QClickableImage.h"


QClickableImage::QClickableImage(QWidget *parent)
{
    this->setScaledContents(true);

    loadingGif = new QMovie(":loading.gif");
    this->setMovie(loadingGif);
    loadingGif->start();
}


void QClickableImage::mousePressEvent(QMouseEvent *event)
{
    emit clicked();
}

void QClickableImage::updatePixmap(QPixmap pixmap)
{
    loadingGif->stop();
    delete loadingGif;

    this->image = pixmap;
    this->setPixmap(image.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}
