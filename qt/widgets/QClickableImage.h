//
// Created by Quentin Gillet on 23/03/2023.
//

#ifndef COOKING_APP_QCLICKABLE_IMAGE_H
#define COOKING_APP_QCLICKABLE_IMAGE_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QMovie>
#include "../../recipe/Recipe.h"

class QClickableImage : public QLabel
{
Q_OBJECT

public:
    explicit QClickableImage(QWidget *parent = nullptr);
private:
    QPixmap image;
    QMovie* loadingGif;
    bool isLoading;

protected:
    void mousePressEvent(QMouseEvent* event);

signals:
    void clicked();

public slots:
    void updatePixmap(const QPixmap&);
};

#endif //COOKING_APP_QCLICKABLEIMAGE_H
