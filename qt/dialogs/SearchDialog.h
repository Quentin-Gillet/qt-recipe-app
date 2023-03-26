//
// Created by Quentin Gillet on 25/03/2023.
//

#ifndef COOKINGAPP_SEARCHDIALOG_H
#define COOKINGAPP_SEARCHDIALOG_H

#include <Qt>
#include <QLabel>
#include <QRadioButton>
#include <QSlider>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QDialog>

class SearchDialog: public QDialog
{
Q_OBJECT
public:
    explicit SearchDialog(QWidget *parent = nullptr);

    QLabel* searchLabel;
    QLabel* mealDietLabel;
    QLabel* maxCaloriesLabel;
    QLabel* caloriesCount;

    QSlider* maxCaloriesSlider;

    QButtonGroup* dietRadioButtonGroup;
    QRadioButton* defaultDiet;
    QRadioButton* veganDiet;
    QRadioButton* vegetarianDiet;

    QLineEdit* searchInput;

    QPushButton* closeButton;
    QPushButton* searchButton;
private slots:
    void maxCaloriesValueChanged(int value);
};


#endif //COOKINGAPP_SEARCHDIALOG_H
