#include "MainWindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Entry label
    QString labelText = "Welcome to your app cooking helper !";
    QLabel* label = new QLabel(labelText, this);
    auto labelWidth = label->fontMetrics().boundingRect(labelText).width();
    label->setGeometry(this->width() / 2 - labelWidth / 2,
                       -90, labelWidth, labelWidth);

    QGridLayout* gridLayout = this->ui->recipeGrid;
    RecipeCard* card = new RecipeCard();
    RecipeCard* card2 = new RecipeCard();
    RecipeCard* card3 = new RecipeCard();
    RecipeCard* card4 = new RecipeCard();
    gridLayout->addWidget(card, 0, 0);
    gridLayout->addWidget(card2, 1, 0);
    gridLayout->addWidget(card3, 0, 1);
    gridLayout->addWidget(card4, 1, 1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

