//
// Created by Quentin Gillet on 23/03/2023.
//


#include "RecipeCard.h"


RecipeCard::RecipeCard(Recipe* recipe, QWidget *parent) :
        QWidget(parent)
{
    this->recipe = recipe;

    auto* layout = new QBoxLayout(QBoxLayout::TopToBottom);
    setLayout(layout);

    auto* image = new QClickableImage(this);
    recipe->startImageDownload(image, SLOT(updatePixmap(QPixmap)));
    connect(image, &QClickableImage::clicked,
                     this, &RecipeCard::clicked);

    layout->addWidget(image);
}

void RecipeCard::clicked()
{
    RecipeDetails* recipeDetails = new RecipeDetails(this->recipe);
    recipeDetails->show();
}

void RecipeCard::setText(QString& text)
{
    this->text = text;
    auto *label = new QLabel(this->text);
    this->layout()->addWidget(label);
}

RecipeCard::~RecipeCard(){}
