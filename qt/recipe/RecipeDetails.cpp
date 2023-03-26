//
// Created by Quentin Gillet on 26/03/2023.
//

#include "RecipeDetails.h"

RecipeDetails::RecipeDetails(Recipe* recipe, QWidget* parent)
{
    setFixedSize(900, 700);
    setWindowTitle(recipe->title);

    QBoxLayout* boxLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    this->setLayout(boxLayout);

    QLabel* topImage = new QLabel(this);
    topImage->setScaledContents(true);
    topImage->setPixmap(recipe->imagePixmap);
    boxLayout->addWidget(topImage);

    QLabel* recipeTitle = new QLabel(recipe->title);
    recipeTitle->setStyleSheet("QLabel {font-size: 30px; text-decoration: underline;}");
    boxLayout->addWidget(recipeTitle, 0, Qt::AlignHCenter);

    QBoxLayout* instructionLayout = new QBoxLayout(QBoxLayout::TopToBottom);

    QLabel* instructionTextLabel = new QLabel("Instruction:");
    instructionTextLabel->setStyleSheet("QLabel {text-decoration: underline;}");
    instructionLayout->addWidget(instructionTextLabel, 50);

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setFixedWidth(this->width() - 35);
    QLabel* instructionsLabel = new QLabel(recipe->instructions);
    instructionsLabel->setFixedWidth(this->width() - 40);
    instructionsLabel->setAlignment(Qt::AlignJustify);
    instructionsLabel->setScaledContents(true);
    instructionsLabel->setWordWrap(true);
    scrollArea->setWidget(instructionsLabel);
    instructionLayout->addWidget(scrollArea, 0, Qt::AlignHCenter);
    boxLayout->addLayout(instructionLayout);

    QPushButton* closeButton = new QPushButton("Close");
    closeButton->setDefault(true);
    QPushButton* addToFavouriteButton = new QPushButton("Add to favourite");
    QPushButton* ingredientsButton = new QPushButton("Ingredient list");
    QBoxLayout* buttonLayout = new QBoxLayout(QBoxLayout::RightToLeft);
    buttonLayout->addWidget(closeButton);
    buttonLayout->addWidget(addToFavouriteButton);
    buttonLayout->addWidget(ingredientsButton);
    boxLayout->addLayout(buttonLayout);

    connect(closeButton, &QPushButton::clicked,
            this, &RecipeDetails::closeWindow);

    connect(addToFavouriteButton, &QPushButton::clicked,
            this, &RecipeDetails::addToFavourite);

    connect(ingredientsButton, &QPushButton::clicked,
            this, &RecipeDetails::seeIngredients);

}

void RecipeDetails::closeWindow()
{
    this->close();
}

void RecipeDetails::addToFavourite()
{

}

void RecipeDetails::seeIngredients()
{

}
