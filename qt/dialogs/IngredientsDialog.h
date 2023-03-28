//
// Created by Quentin Gillet on 26/03/2023.
//

#ifndef COOKING_APP_INGREDIENTS_DIALOG_H
#define COOKING_APP_INGREDIENTS_DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QSpinBox>
#include "../../recipe/Recipe.h"
#include "../tools/Tools.h"

class IngredientsDialog: public QDialog
{
Q_OBJECT

public:
    explicit IngredientsDialog(Recipe* recipe, QWidget* parent = nullptr);
private:
    QSpinBox* personCount;
    Recipe* recipe;
    QBoxLayout* ingredientsLayout;

private slots:
    void updateIngredients();
};


#endif
