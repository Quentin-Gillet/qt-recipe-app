//
// Created by Quentin Gillet on 26/03/2023.
//

#include "QIconLabel.h"

QIconLabel::QIconLabel(const QString &text, QWidget *parent) : QWidget(parent)
{
    auto * layout = new QBoxLayout(QBoxLayout::RightToLeft);
    setLayout(layout);

    this->textLabel = new QLabel(text, this);
    layout->addWidget(this->textLabel);

    this->iconLabel = new QLabel(this);
}

void QIconLabel::setIcon(const QIcon &icon, int size)
{
    QPixmap pixmap = icon.pixmap(QSize(size, size));
    this->iconLabel->setPixmap(pixmap);
    layout()->addWidget(iconLabel);
}
