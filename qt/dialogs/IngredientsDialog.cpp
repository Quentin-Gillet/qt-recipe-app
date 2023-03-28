//
// Created by Quentin Gillet on 26/03/2023.
//

#include "IngredientsDialog.h"

IngredientsDialog::IngredientsDialog(Recipe *recipe, QWidget *parent) : QDialog(parent)
{
    this->recipe = recipe;

    setWindowTitle("Ingredients needed");
    setModal(true);
    QList<Ingredient *> ingredients = recipe->ingredients;
    setFixedSize(400, (int) ingredients.count() * 33 + 15);

    auto *layout = new QBoxLayout(QBoxLayout::TopToBottom);
    setLayout(layout);

    auto *servingLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    auto *servingLabel = new QLabel("Servings: ");
    servingLabel->setStyleSheet("QLabel {text-decoration: underline; font-weight: bold;}");
    servingLayout->addWidget(servingLabel);
    personCount = new QSpinBox(this);
    personCount->setMinimum(0);
    personCount->setValue(recipe->servings);
    personCount->setSingleStep(1);
    personCount->setSuffix(" person(s)");
    servingLayout->addWidget(personCount);
    layout->addLayout(servingLayout);

    connect(personCount, &QSpinBox::valueChanged,
            this, &IngredientsDialog::updateIngredients);

    this->ingredientsLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    updateIngredients();
    layout->addLayout(ingredientsLayout);

    auto *closeButton = new QPushButton("Close");
    layout->addWidget(closeButton, Qt::AlignHCenter);

    connect(closeButton, &QPushButton::clicked,
            this, &QDialog::reject);
}

void IngredientsDialog::updateIngredients()
{
    Tools::ClearLayout(this->ingredientsLayout);
    QList<Ingredient *> ingredients = this->recipe->ingredients;
    for (int i = 0; i < ingredients.count(); i++)
    {
        Ingredient *ingredient = ingredients[i];
        Measure *measure = ingredient->measure;
        double ingredientMesure = ((double) personCount->value() / recipe->servings) * measure->amount;
        auto *ingredientLabel = new QLabel("- " + QString::number(ingredientMesure, 'f', 2) + measure->unitShort
                                           + " of " + ingredient->name);
        ingredientsLayout->addWidget(ingredientLabel);
    }
}

