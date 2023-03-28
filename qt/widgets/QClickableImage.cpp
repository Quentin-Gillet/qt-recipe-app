//
// Created by Quentin Gillet on 23/03/2023.
//

#include "QClickableImage.h"


QClickableImage::QClickableImage(QWidget *parent) : QLabel(parent)
{
    this->setScaledContents(true);

    this->loadingGif = new QMovie(":loading.gif");
    this->setMovie(this->loadingGif);
    this->loadingGif->start();
    this->isLoading = true;
}


void QClickableImage::mousePressEvent(QMouseEvent *event)
{
    if (!this->isLoading)
            emit this->clicked();
}

void QClickableImage::updatePixmap(const QPixmap &pixmap)
{
    this->loadingGif->stop();
    delete this->loadingGif;
    this->isLoading = false;

    this->image = pixmap;
    this->setPixmap(this->image.scaled(this->width(), this->height(), Qt::KeepAspectRatio));
}
