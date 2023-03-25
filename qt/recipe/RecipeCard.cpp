//
// Created by Quentin Gillet on 23/03/2023.
//


#include "RecipeCard.h"


RecipeCard::RecipeCard(QString url, QWidget *parent) :
        QWidget(parent)
{
    auto* layout = new QBoxLayout(QBoxLayout::TopToBottom);
    setLayout(layout);

    auto* image = new QClickableImage(&url, this);
    QObject::connect(image, &QClickableImage::clicked,
                     this, &RecipeCard::clicked);

    layout->addWidget(image);
}

void RecipeCard::clicked()
{
    qDebug() << "test";
}

void RecipeCard::setText(QString& text)
{
    this->text = text;
    auto *label = new QLabel(this->text);
    this->layout()->addWidget(label);
}

RecipeCard::~RecipeCard(){}
