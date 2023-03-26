//
// Created by Quentin Gillet on 26/03/2023.
//

#ifndef COOKINGAPP_INGREDIENTSDIALOG_H
#define COOKINGAPP_INGREDIENTSDIALOG_H

#include <Qt>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QSpinBox>
#include <QWidget>
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


#endif //COOKINGAPP_INGREDIENTSDIALOG_H
