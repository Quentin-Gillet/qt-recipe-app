//
// Created by Quentin Gillet on 24/03/2023.
//

#include "RecipeGrid.h"

RecipeGrid::RecipeGrid(QWidget *parent) :
    QWidget(parent)
{
    QGridLayout* gridLayout = new QGridLayout(this);
    setLayout(gridLayout);
}

void RecipeGrid::generateRecipeGrid(QList<Recipe*> recipes)
{
    if(recipes.count() == 0)
    {
        QLabel* errorLabel = new QLabel("There is no recipes !");
        errorLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        errorLabel->setStyleSheet("QLabel {font-size: 30px; color: red;}");
        layout()->addWidget(errorLabel);
    }

    for(int i = 0; i < recipes.count(); i++)
    {
        Recipe* recipe = recipes[i];
        RecipeCard* card = new RecipeCard(recipe);
        card->setText(recipe->title);
        QGridLayout* layout = qobject_cast<QGridLayout*>(this->layout());
        layout->addWidget(card, i / 3, i % 3);
    }
}

void RecipeGrid::clearRecipeGrid()
{
    Tools::ClearLayout(this->layout());
}
