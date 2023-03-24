//
// Created by Quentin Gillet on 23/03/2023.
//

#ifndef COOKINGAPP_RECIPECARD_H
#define COOKINGAPP_RECIPECARD_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include "../widgets/QClickableImage.h"

class RecipeCard : public QLabel
{
Q_OBJECT

public:
    explicit RecipeCard(QWidget *parent = nullptr);

private slots:
    void clicked();
};


#endif //COOKINGAPP_RECIPECARD_H
