//
// Created by Quentin Gillet on 23/03/2023.
//

#ifndef COOKINGAPP_RECIPECARD_H
#define COOKINGAPP_RECIPECARD_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QBoxLayout>
#include "../widgets/QClickableImage.h"

class RecipeCard : public QWidget
{
Q_OBJECT

public:
    explicit RecipeCard(QString url, QWidget *parent = nullptr);
    void setText(QString& text);
    ~RecipeCard();
private:
    QString text;

private slots:
    void clicked();

};


#endif //COOKINGAPP_RECIPECARD_H
