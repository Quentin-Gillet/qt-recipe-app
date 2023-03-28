//
// Created by Quentin Gillet on 25/03/2023.
//

#include "SearchDialog.h"

SearchDialog::SearchDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Search for recipe");
    setFixedSize(400, 300);
    setModal(true);

    auto *gridLayout = new QGridLayout(this);
    setLayout(gridLayout);

    mealDietLabel = new QLabel("Select type of meal diet:");
    dietRadioButtonGroup = new QButtonGroup(gridLayout);
    defaultDiet = new QRadioButton("All");
    defaultDiet->setChecked(true);
    veganDiet = new QRadioButton("Vegan");
    vegetarianDiet = new QRadioButton("Vegetarian");
    dietRadioButtonGroup->addButton(defaultDiet);
    dietRadioButtonGroup->addButton(vegetarianDiet);
    dietRadioButtonGroup->addButton(veganDiet);
    gridLayout->addWidget(mealDietLabel, 0, 0);
    auto *hBoxLayout = new QHBoxLayout();
    hBoxLayout->addWidget(defaultDiet);
    hBoxLayout->addWidget(vegetarianDiet);
    hBoxLayout->addWidget(veganDiet);
    gridLayout->addLayout(hBoxLayout, 1, 0, 1, 4);

    ignorePantry = new QCheckBox("Ignore pantry");
    gridLayout->addWidget(ignorePantry, 2, 0, 1, 4);

    maxCaloriesLabel = new QLabel("Set max colories per serving: (0 = ignore)");
    caloriesCount = new QLabel("0");
    maxCaloriesSlider = new QSlider(Qt::Orientation::Horizontal);
    maxCaloriesSlider->setMaximum(1000);
    maxCaloriesSlider->setMinimum(0);
    maxCaloriesSlider->setValue(0);
    maxCaloriesSlider->setTickInterval(10);
    gridLayout->addWidget(maxCaloriesLabel, 3, 0, 1, 3);
    gridLayout->addWidget(maxCaloriesSlider, 4, 0, 1, 3);
    gridLayout->addWidget(caloriesCount, 4, 3);

    maxResultLabel = new QLabel("Set maximum results");
    maxResults = new QSpinBox(this);
    maxResults->setSuffix(" result(s)");
    maxResults->setMinimum(1);
    maxResults->setMaximum(100);
    maxResults->setValue(9);
    gridLayout->addWidget(maxResultLabel, 5, 0, 1, 2);
    gridLayout->addWidget(maxResults, 5, 2);

    connect(maxCaloriesSlider, &QSlider::valueChanged,
            this, &SearchDialog::maxCaloriesValueChanged);

    searchLabel = new QLabel("Search query:");
    searchInput = new QLineEdit();
    gridLayout->addWidget(searchLabel, 6, 0);
    gridLayout->addWidget(searchInput, 7, 0, 1, 4);
    searchInput->setFocus();

    closeButton = new QPushButton("Close");
    searchButton = new QPushButton("Search");
    searchButton->setDefault(true);
    closeButton->setDefault(false);
    gridLayout->addWidget(closeButton, 8, 2);
    gridLayout->addWidget(searchButton, 8, 3);

    connect(closeButton, &QPushButton::clicked,
            this, &QDialog::reject);

    connect(searchButton, &QPushButton::clicked,
            this, &SearchDialog::searchButtonClicked);

    connect(this, &SearchDialog::performSearch,
            this, &QDialog::accept);
}

void SearchDialog::maxCaloriesValueChanged(int value) const
{
    caloriesCount->setText(QString::number(value));
}

void SearchDialog::searchButtonClicked()
{
    if (this->searchInput->text().isEmpty())
    {
        QMessageBox::critical(this, "Error", "Please fill the search query");
        return;
    }
    emit performSearch();
}


