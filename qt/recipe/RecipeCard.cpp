//
// Created by Quentin Gillet on 23/03/2023.
//


#include "RecipeCard.h"


RecipeCard::RecipeCard(QWidget *parent) :
        QLabel(parent)
{
    auto* layout = new QVBoxLayout();
    setLayout(layout);

    auto* url = new QString("https://www.inspiredtaste.net/wp-content/uploads/2018/12/Sauteed-Zucchini-Recipe-1-1200.jpg");
    auto* image = new QClickableImage(url, this);
    QObject::connect(image, &QClickableImage::clicked,
                     this, &RecipeCard::clicked);

    layout->addWidget(image);

    auto* label = new QLabel("TEST");
    layout->addWidget(label);

}

void RecipeCard::clicked()
{
    qDebug() << "test";
}
