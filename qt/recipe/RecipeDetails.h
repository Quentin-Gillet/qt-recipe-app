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
#include "../../recipe/Recipe.h"

class RecipeDetails: public QWidget
{
    Q_OBJECT
public:
    explicit RecipeDetails(Recipe* recipe, QWidget* parent = nullptr);
};


#endif //COOKINGAPP_RECIPEDETAILS_H
