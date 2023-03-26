//
// Created by Quentin Gillet on 23/03/2023.
//

#ifndef COOKINGAPP_RECIPECARD_H
#define COOKINGAPP_RECIPECARD_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QBoxLayout>
#include "../../recipe/Recipe.h"
#include "../widgets/QClickableImage.h"
#include "RecipeDetails.h"

class RecipeCard : public QWidget
{
Q_OBJECT

public:
    explicit RecipeCard(Recipe* recipe, QWidget *parent = nullptr);
    void setText(QString& text);
    ~RecipeCard();
private:
    QString text;
    Recipe *recipe;

private slots:
    void clicked();
};


#endif //COOKINGAPP_RECIPECARD_H
