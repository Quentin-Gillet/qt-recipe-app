#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include "../recipe/RecipeGrid.h"
#include "../dialogs/SearchDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    RecipeGrid* recipeGrid;

public slots:
    void displaySearchDialog();
    void performSearch(QString result);
};
#endif // MAINWINDOW_H
