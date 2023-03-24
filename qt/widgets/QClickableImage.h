//
// Created by Quentin Gillet on 23/03/2023.
//

#ifndef COOKINGAPP_QCLICKABLEIMAGE_H
#define COOKINGAPP_QCLICKABLEIMAGE_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QTimer>
#include <QEventLoop>
#include "../tools/FileDownloader.h"

class QClickableImage : public QLabel
{
Q_OBJECT

public:
    explicit QClickableImage(QString* url, QWidget *parent = nullptr);

private:
    FileDownloader* fileDownloader;
    QPixmap image;

protected:
    void mousePressEvent(QMouseEvent* event);

signals:
    void clicked();
};

#endif //COOKINGAPP_QCLICKABLEIMAGE_H
