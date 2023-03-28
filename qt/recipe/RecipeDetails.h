//
// Created by Quentin Gillet on 26/03/2023.
//

#ifndef COOKING_APP_RECIPE_DETAILS_H
#define COOKING_APP_RECIPE_DETAILS_H

#include <QLabel>
#include <QWidget>
#include <QBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QKeyEvent>
#include "../dialogs/IngredientsDialog.h"
#include "../../recipe/Recipe.h"
#include "../../recipe/RecipeFavourite.h"
#include "../widgets/QIconLabel.h"

class RecipeDetails: public QWidget
{
    Q_OBJECT
public:
    explicit RecipeDetails(Recipe* recipe, QWidget* parent = nullptr);

private:
    void keyPressEvent(QKeyEvent* event);
    QPushButton* favouriteButton;
    Recipe *recipe;

private slots:
    void closeWindow();
    void favouriteAction();
    void seeIngredients();
};


#endif
