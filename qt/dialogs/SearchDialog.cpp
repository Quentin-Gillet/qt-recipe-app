//
// Created by Quentin Gillet on 25/03/2023.
//

#include "SearchDialog.h"

SearchDialog::SearchDialog(QWidget *parent)
{
    setWindowTitle("Search for recipe");
    setFixedSize(300, 150);
    setModal(true);

    setCancelButtonText("Cancel");
    setOkButtonText("Search");
    setInputMode(QInputDialog::InputMode::TextInput);
    setLabelText("Search for a recipe");
}
