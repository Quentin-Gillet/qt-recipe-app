//
// Created by Quentin Gillet on 25/03/2023.
//

#ifndef COOKINGAPP_SEARCHDIALOG_H
#define COOKINGAPP_SEARCHDIALOG_H

#include <Qt>
#include <QInputDialog>

class SearchDialog: public QInputDialog
{
Q_OBJECT
public:
    explicit SearchDialog(QWidget *parent = nullptr);

};


#endif //COOKINGAPP_SEARCHDIALOG_H
