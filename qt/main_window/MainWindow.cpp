#include "MainWindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->show();

    //Entry label
    QString labelText = "Welcome to your app cooking helper !";
    QLabel* label = new QLabel(labelText, this);
    auto labelWidth = label->fontMetrics().boundingRect(labelText).width();
    label->setGeometry(this->width() / 2 - labelWidth / 2,
                       -90, labelWidth, labelWidth);

    //Recipe grid
    QFrame* frame = this->ui->frame;
    recipeGrid = new RecipeGrid(this);
    recipeGrid->setGeometry(frame->geometry());
    recipeGrid->refreshRecipeGrid();
    recipeGrid->show();

    //Refresh button
    connect(this->ui->refreshButton, &QPushButton::clicked,
            recipeGrid, &RecipeGrid::refreshRecipeGrid);

    //Menu bar
    //Search
    connect(this->ui->actionSearch, &QAction::triggered,
            this, &MainWindow::displaySearchDialog);
    //Discover
    connect(this->ui->actionExplore, &QAction::triggered,
            recipeGrid, &RecipeGrid::refreshRecipeGrid);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::performSearch(const QString& searchQuery, const QString& mealDiet, int maxCalories)
{
    Scrapper scrapper;
    QList<Recipe> recipes = scrapper.searchRecipe(searchQuery, mealDiet, maxCalories);
    recipeGrid->clearRecipeGrid();
    recipeGrid->generateRecipeGrid(recipes);
}

void MainWindow::displaySearchDialog()
{
    SearchDialog* searchDialog = new SearchDialog(this);
    int resultCode = searchDialog->exec();
    if(resultCode == 1)
    {
        performSearch(searchDialog->searchInput->text(),
                      searchDialog->dietRadioButtonGroup->checkedButton()->text(),
                      searchDialog->maxCaloriesSlider->value());
    }
    delete searchDialog;
}

