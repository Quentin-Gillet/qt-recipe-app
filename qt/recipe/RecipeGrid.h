//
// Created by Quentin Gillet on 24/03/2023.
//

#ifndef COOKING_APP_RECIPE_GRID_H
#define COOKING_APP_RECIPE_GRID_H


#include <QWidget>
#include <QBoxLayout>
#include <QString>
#include <QList>
#include <QScrollArea>
#include "../../recipe/scrapper/Scrapper.h"
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
private:
    QGridLayout* gridLayout;
public slots:
    inline void refreshRecipeGrid()
    {
        Scrapper scrapper;
        QList<Recipe*> recipes = scrapper.getRandomRecipe(9);

        clearRecipeGrid();
        generateRecipeGrid(recipes);
    }
};


#endif
