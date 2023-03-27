//
// Created by Quentin Gillet on 23/03/2023.
//

#ifndef COOKINGAPP_QCLICKABLEIMAGE_H
#define COOKINGAPP_QCLICKABLEIMAGE_H

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
    inline ~QClickableImage(){}
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

#endif //COOKINGAPP_QCLICKABLEIMAGE_H
