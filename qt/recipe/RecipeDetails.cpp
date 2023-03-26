//
// Created by Quentin Gillet on 26/03/2023.
//

#include "RecipeDetails.h"

RecipeDetails::RecipeDetails(Recipe* recipe, QWidget* parent)
{
    this->recipe = recipe;
    setFixedSize(1000, 700);
    setWindowTitle(recipe->title);

    QBoxLayout* boxLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    this->setLayout(boxLayout);

    QLabel* topImage = new QLabel(this);
    topImage->setScaledContents(true);
    topImage->setPixmap(recipe->imagePixmap);
    boxLayout->addWidget(topImage);

    QBoxLayout* titleLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    QLabel* recipeTitle = new QLabel(recipe->title);
    recipeTitle->setStyleSheet("QLabel {font-size: 30px; text-decoration: underline;}");
    //recipeTitle->setWordWrap(true);
    recipeTitle->setScaledContents(true);
    //recipeTitle->setSizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding);
    //recipeTitle->setFixedWidth(this->width() - 130);
    titleLayout->addWidget(recipeTitle, 500, Qt::AlignHCenter);
    if(recipe->veryPopular)
    {
        QLabel* popularLabel = new QLabel("POPULAR!");
        popularLabel->setStyleSheet("QLabel {font-size: 24px; font-style: italic;color:red; border-radius: 15px;"
                                    " background-color: yellow;}");
        titleLayout->addWidget(popularLabel, 0, Qt::AlignRight);
    }
    boxLayout->addLayout(titleLayout);

    QBoxLayout* indicatorLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    QIconLabel* timeLabel = new QIconLabel(QString::number(recipe->readyInMinutes) + " minutes");
    timeLabel->setIcon(QIcon(":clock.png"), 24);
    QIconLabel* personLabel = new QIconLabel(QString::number(recipe->servings) + " person(s)");
    personLabel->setIcon(QIcon(":persons.png"), 24);
    indicatorLayout->addWidget(timeLabel, 0, Qt::AlignHCenter);
    indicatorLayout->addWidget(personLabel, 0, Qt::AlignHCenter);
    boxLayout->addLayout(indicatorLayout);

    QBoxLayout* instructionLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    QLabel* instructionTextLabel = new QLabel("Instruction:");
    instructionTextLabel->setStyleSheet("QLabel {text-decoration: underline;}");
    instructionLayout->addWidget(instructionTextLabel, 0);

    QScrollArea* scrollArea = new QScrollArea(this);
    scrollArea->setFixedWidth(this->width() - 35);
    QLabel* instructionsLabel = new QLabel(recipe->instructions);
    instructionsLabel->setFixedWidth(this->width() - 40);
    instructionsLabel->setAlignment(Qt::AlignJustify);
    instructionsLabel->setScaledContents(true);
    instructionsLabel->setWordWrap(true);
    scrollArea->setWidget(instructionsLabel);
    instructionLayout->addWidget(scrollArea, 30, Qt::AlignHCenter);
    boxLayout->addLayout(instructionLayout, 50);

    QPushButton* closeButton = new QPushButton("Close");
    closeButton->setDefault(true);
    QPushButton* addToFavouriteButton = new QPushButton("Add to favourite");
    QPushButton* ingredientsButton = new QPushButton("Ingredient list");
    if(recipe->ingredients.count() == 0)
    {
        ingredientsButton->setDisabled(true);
        ingredientsButton->setText("No ingredients");
    }
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
    IngredientsDialog* ingredientsDialog = new IngredientsDialog(this->recipe, this);
    ingredientsDialog->show();
}
