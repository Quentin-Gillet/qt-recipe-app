//
// Created by Quentin Gillet on 26/03/2023.
//

#include "IngredientsDialog.h"

IngredientsDialog::IngredientsDialog(Recipe* recipe, QWidget* parent)
{
    this->recipe = recipe;

    setWindowTitle("Ingredients needed");
    setModal(true);
    QList<Ingredient*> ingredients = recipe->ingredients;
    setFixedSize(400, ingredients.count() * 33);

    QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom);
    setLayout(layout);

    QBoxLayout* servingLayout = new QBoxLayout(QBoxLayout::RightToLeft);
    QLabel* servingLabel = new QLabel("Servings: ");
    servingLayout->addWidget(servingLabel);
    personCount = new QSpinBox(this);
    personCount->setMinimum(0);
    personCount->setValue(recipe->servings);
    personCount->setSingleStep(1);
    personCount->setSuffix("person(s)");
    servingLayout->addWidget(personCount);
    layout->addLayout(servingLayout);

    connect(personCount, &QSpinBox::valueChanged,
            this, &IngredientsDialog::updateIngredients);

    this->ingredientsLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    updateIngredients();
    layout->addLayout(ingredientsLayout);

    QBoxLayout* buttonLayout = new QBoxLayout(QBoxLayout::RightToLeft);
    QPushButton* closeButton = new QPushButton("Close");
    QPushButton* toFileButton = new QPushButton("Save to file");
    buttonLayout->addWidget(closeButton);
    buttonLayout->addWidget(toFileButton);
    layout->addLayout(buttonLayout);

    connect(closeButton, &QPushButton::clicked,
            this, &QDialog::reject);
}

void IngredientsDialog::updateIngredients()
{
    Tools::ClearLayout(this->ingredientsLayout);
    QList<Ingredient*> ingredients = this->recipe->ingredients;
    for(int i = 0; i < ingredients.count(); i++)
    {
        Ingredient* ingredient = ingredients[i];
        Measure* measure = ingredient->measure;
        double ingredientMesure = ((double)personCount->value() / recipe->servings) * measure->amount;
        QLabel* ingredientLabel = new QLabel("- " + QString::number(ingredientMesure, 'f', 2) + measure->unitShort
                                             + " of " + ingredient->nameClean);
        ingredientsLayout->addWidget(ingredientLabel);
    }
}

