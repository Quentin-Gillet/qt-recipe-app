#include "MainWindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->show();

    this->setFixedSize(this->width(), this->height());

    //Entry label
    QString labelText = "Welcome to your app cooking helper !";
    auto *label = new QLabel(labelText, this);
    auto labelWidth = label->fontMetrics().boundingRect(labelText).width();
    label->setGeometry(this->width() / 2 - labelWidth / 2,
                       -90, labelWidth, labelWidth);
    label->show();

    //Recipe grid
    recipeGrid = new RecipeGrid(this);
    recipeGrid->setGeometry(QRect(25, 50, 1030, 650));
    recipeGrid->refreshRecipeGrid();
    recipeGrid->show();

    this->searchAction = new QAction("Search");
    this->searchAction->setIcon(QIcon(":search.png"));
    this->searchAction->setShortcut(QKeySequence::Find);

    this->exploreAction = new QAction("Explore");
    this->exploreAction->setIcon(QIcon(":explore.png"));
    this->exploreAction->setShortcut(QKeySequence::Open);

    this->favouriteAction = new QAction("Favourite");
    this->favouriteAction->setIcon(QIcon(":favourite.png"));
    this->favouriteAction->setShortcut(QKeySequence::New);

    this->recipeMenu = menuBar()->addMenu("Recipe");
    this->recipeMenu->addAction(this->searchAction);
    this->recipeMenu->addAction(this->exploreAction);
    this->recipeMenu->addSeparator();
    this->recipeMenu->addAction(this->favouriteAction);

    //Refresh button
    connect(this->ui->refreshButton, &QPushButton::clicked,
            recipeGrid, &RecipeGrid::refreshRecipeGrid);

    //Menu bar
    //Search
    connect(this->searchAction, &QAction::triggered,
            this, &MainWindow::displaySearchDialog);
    //Discover
    connect(this->exploreAction, &QAction::triggered,
            recipeGrid, &RecipeGrid::refreshRecipeGrid);
    //Favourite
    connect(this->favouriteAction, &QAction::triggered,
            this, &MainWindow::displayFavourites);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::performSearch(const QString &searchQuery, const QString &mealDiet,
                               int maxCalories, bool ignorePantry, int resultsCount)
{
    Scrapper scrapper;
    QList<Recipe *> recipes = scrapper.searchRecipe(searchQuery, mealDiet,
                                                    maxCalories, ignorePantry, resultsCount);
    recipeGrid->clearRecipeGrid();
    recipeGrid->generateRecipeGrid(recipes);
}

void MainWindow::displaySearchDialog()
{
    auto *searchDialog = new SearchDialog(this);
    int resultCode = searchDialog->exec();
    if (resultCode == 1)
    {
        performSearch(searchDialog->searchInput->text(),
                      searchDialog->dietRadioButtonGroup->checkedButton()->text(),
                      searchDialog->maxCaloriesSlider->value(),
                      searchDialog->ignorePantry->isChecked(),
                      searchDialog->maxResults->value());
    }
    delete searchDialog;
}

void MainWindow::displayFavourites()
{
    RecipeFavourite jsonRecipe;
    QList<Recipe *> recipes = jsonRecipe.loadRecipes();
    recipeGrid->clearRecipeGrid();
    recipeGrid->generateRecipeGrid(recipes);
}

