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
    for(int i = 0; i < recipes.length(); i++)
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
