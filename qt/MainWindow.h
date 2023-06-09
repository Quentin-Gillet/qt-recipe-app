#ifndef COOKING_APP_MAIN_WINDOW_H
#define COOKING_APP_MAIN_WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "recipe/RecipeGrid.h"
#include "dialogs/SearchDialog.h"
#include "../recipe/RecipeFavourite.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    RecipeGrid* recipeGrid;

    QMenu* recipeMenu;
    QAction* searchAction;
    QAction* exploreAction;
    QAction* favouriteAction;

public slots:
    void displaySearchDialog();
    void displayFavourites();
    void performSearch(const QString& result, const QString& mealDiet,
                       int maxCalories, bool ignorePantry, int resultsCount);
};
#endif //COOKING_APP_MAIN_WINDOW_H
