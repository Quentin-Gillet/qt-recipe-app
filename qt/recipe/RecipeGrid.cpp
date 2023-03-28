//
// Created by Quentin Gillet on 24/03/2023.
//

#include "RecipeGrid.h"

RecipeGrid::RecipeGrid(QWidget *parent) :
    QWidget(parent)
{
    QWidget* scrollWidget = new QWidget(this);
    this->gridLayout = new QGridLayout(scrollWidget);
    this->gridLayout->setSizeConstraint(QLayout::SetFixedSize);

    scrollWidget->setLayout(this->gridLayout);
    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setFixedSize(1030, 650);
}

void RecipeGrid::generateRecipeGrid(QList<Recipe*> recipes)
{
    if(recipes.count() == 0)
    {
        QLabel* errorLabel = new QLabel("No recipes found !");
        errorLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        errorLabel->setStyleSheet("QLabel {font-size: 30px; color: red;}");
        this->gridLayout->addWidget(errorLabel);
    }

    for(int i = 0; i < recipes.count(); i++)
    {
        Recipe* recipe = recipes[i];
        RecipeCard* card = new RecipeCard(recipe);
        card->setText(recipe->title);
        card->setFixedSize(this->width() / 3 - 15, this->height() / 3 - 15);
        this->gridLayout->addWidget(card, i / 3, i % 3);
    }
}

void RecipeGrid::clearRecipeGrid()
{
    Tools::ClearLayout(this->gridLayout);
}
