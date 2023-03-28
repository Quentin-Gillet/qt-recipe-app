//
// Created by Quentin Gillet on 25/03/2023.
//

#ifndef COOKINGAPP_SEARCHDIALOG_H
#define COOKINGAPP_SEARCHDIALOG_H

#include <Qt>
#include <QLabel>
#include <QRadioButton>
#include <QCheckBox>
#include <QSlider>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QDialog>
#include <QMessageBox>
#include <QSpinBox>

class SearchDialog: public QDialog
{
Q_OBJECT
public:
    explicit SearchDialog(QWidget *parent = nullptr);

    QLabel* searchLabel;
    QLabel* mealDietLabel;
    QLabel* maxCaloriesLabel;
    QLabel* caloriesCount;
    QLabel* maxResultLabel;

    QSlider* maxCaloriesSlider;

    QButtonGroup* dietRadioButtonGroup;
    QRadioButton* defaultDiet;
    QRadioButton* veganDiet;
    QRadioButton* vegetarianDiet;
    QCheckBox* ignorePantry;

    QSpinBox* maxResults;

    QLineEdit* searchInput;

    QPushButton* closeButton;
    QPushButton* searchButton;
signals:
    void performSearch();
private slots:
    void searchButtonClicked();
    void maxCaloriesValueChanged(int value);
};


#endif //COOKINGAPP_SEARCHDIALOG_H
