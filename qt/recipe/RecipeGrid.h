//
// Created by Quentin Gillet on 24/03/2023.
//

#ifndef COOKINGAPP_RECIPEGRID_H
#define COOKINGAPP_RECIPEGRID_H


#include <QWidget>
#include <QBoxLayout>
#include <QString>
#include <QList>
#include "../../scrapper/Scrapper.h"
#include "../../recipe/Recipe.h"
#include "../tools/Tools.h"
#include "RecipeCard.h"

class RecipeGrid : public QWidget
{
Q_OBJECT

public:
    explicit RecipeGrid(QWidget *parent = nullptr);
    void generateRecipeGrid(QList<Recipe*>);
    void clearRecipeGrid();
public slots:
    inline void refreshRecipeGrid()
    {
        Scrapper scrapper;
        QList<Recipe*> recipes = scrapper.getRandomRecipe(9);

        clearRecipeGrid();
        generateRecipeGrid(recipes);
    }
};


#endif //COOKINGAPP_RECIPEGRID_H
