//
// Created by Quentin Gillet on 26/03/2023.
//

#include "RecipeDetails.h"

RecipeDetails::RecipeDetails(Recipe *recipe, QWidget *parent) : QWidget(parent)
{
    this->recipe = recipe;
    setFixedSize(1000, 700);
    setWindowTitle(recipe->title);

    auto *boxLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    this->setLayout(boxLayout);

    auto *topImage = new QLabel(this);
    topImage->setScaledContents(true);
    topImage->setPixmap(recipe->imagePixmap);
    boxLayout->addWidget(topImage);

    auto *titleLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    auto *recipeTitle = new QLabel(recipe->title);
    recipeTitle->setStyleSheet("QLabel {font-size: 30px; text-decoration: underline;}");
    recipeTitle->setScaledContents(true);
    titleLayout->addWidget(recipeTitle, 500, Qt::AlignHCenter);
    if (recipe->veryPopular)
    {
        auto *popularLabel = new QLabel("POPULAR!");
        popularLabel->setStyleSheet("QLabel {font-size: 24px; font-style: italic;color:red; border-radius: 15px;"
                                    " background-color: yellow;}");
        titleLayout->addWidget(popularLabel, 0, Qt::AlignRight);
    }
    if (recipe->veryHealthy)
    {
        auto *healthyLabel = new QLabel("HEALTHY!");
        healthyLabel->setStyleSheet(
                "QLabel {font-size: 24px; font-style: italic; color: greenyellow; border-radius: 15px;"
                " background-color: forestgreen;}");
        titleLayout->addWidget(healthyLabel, 0, Qt::AlignRight);
    }
    boxLayout->addLayout(titleLayout);

    auto *indicatorLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    auto *timeLabel = new QIconLabel(QString::number(recipe->readyInMinutes) + " minutes");
    timeLabel->setIcon(QIcon(":clock.png"), 24);
    auto *personLabel = new QIconLabel(QString::number(recipe->servings) + " person(s)");
    personLabel->setIcon(QIcon(":persons.png"), 24);
    indicatorLayout->addWidget(timeLabel, 0, Qt::AlignHCenter);
    indicatorLayout->addWidget(personLabel, 0, Qt::AlignHCenter);
    boxLayout->addLayout(indicatorLayout);

    auto *instructionLayout = new QBoxLayout(QBoxLayout::TopToBottom);
    auto *instructionTextLabel = new QLabel("Instruction:");
    instructionTextLabel->setStyleSheet("QLabel {text-decoration: underline;}");
    instructionLayout->addWidget(instructionTextLabel, 0);

    auto *scrollArea = new QScrollArea(this);
    scrollArea->setFixedWidth(this->width() - 35);
    auto *instructionsLabel = new QLabel(recipe->getInstructionString());
    instructionsLabel->setTextFormat(Qt::RichText);
    instructionsLabel->setFixedWidth(this->width() - 40);
    instructionsLabel->setAlignment(Qt::AlignJustify);
    instructionsLabel->setScaledContents(true);
    instructionsLabel->setWordWrap(true);
    scrollArea->setWidget(instructionsLabel);
    instructionLayout->addWidget(scrollArea, 30, Qt::AlignHCenter);
    boxLayout->addLayout(instructionLayout, 50);

    auto *closeButton = new QPushButton("Close");
    closeButton->setDefault(true);
    QString favouriteText = recipe->isFavourite ? "Remove from favourite" : "Add to favourite";
    favouriteButton = new QPushButton(favouriteText);
    auto *ingredientsButton = new QPushButton("Ingredient list");
    if (recipe->ingredients.count() == 0)
    {
        ingredientsButton->setDisabled(true);
        ingredientsButton->setText("No ingredients");
    }
    auto *buttonLayout = new QBoxLayout(QBoxLayout::RightToLeft);
    buttonLayout->addWidget(closeButton);
    buttonLayout->addWidget(favouriteButton);
    buttonLayout->addWidget(ingredientsButton);
    boxLayout->addLayout(buttonLayout);

    connect(closeButton, &QPushButton::clicked,
            this, &RecipeDetails::closeWindow);

    connect(favouriteButton, &QPushButton::clicked,
            this, &RecipeDetails::favouriteAction);

    connect(ingredientsButton, &QPushButton::clicked,
            this, &RecipeDetails::seeIngredients);

}

void RecipeDetails::closeWindow()
{
    this->close();
}

void RecipeDetails::favouriteAction()
{
    if (recipe->isFavourite)
    {
        RecipeFavourite jsonRecipe;
        jsonRecipe.removeRecipe(this->recipe->id);
        this->recipe->isFavourite = false;
        this->favouriteButton->setText("Add to favourite");
    } else
    {
        RecipeFavourite jsonRecipe;
        jsonRecipe.saveRecipe(this->recipe);
        this->recipe->isFavourite = true;
        this->favouriteButton->setText("Remove from favourite");
    }
}

void RecipeDetails::seeIngredients()
{
    auto *ingredientsDialog = new IngredientsDialog(this->recipe, this);
    ingredientsDialog->show();
}

void RecipeDetails::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Enter)
        this->closeWindow();
}
