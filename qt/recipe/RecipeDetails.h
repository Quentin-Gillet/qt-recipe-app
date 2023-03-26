//
// Created by Quentin Gillet on 26/03/2023.
//

#ifndef COOKINGAPP_RECIPEDETAILS_H
#define COOKINGAPP_RECIPEDETAILS_H

#include <Qt>
#include <QLabel>
#include <QWidget>
#include <QBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include "../dialogs/IngredientsDialog.h"
#include "../../recipe/Recipe.h"

class RecipeDetails: public QWidget
{
    Q_OBJECT
public:
    explicit RecipeDetails(Recipe* recipe, QWidget* parent = nullptr);
private:
    Recipe *recipe;
private slots:
    void closeWindow();
    void addToFavourite();
    void seeIngredients();
};


#endif //COOKINGAPP_RECIPEDETAILS_H
