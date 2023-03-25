//
// Created by Quentin Gillet on 12/03/2023.
//

#ifndef COOKING_PROJECT_INGREDIENT_H
#define COOKING_PROJECT_INGREDIENT_H


#include <string>
#include <vector>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include "Measure.h"

class Ingredient
{
public:
    int amount;
    QString consistency;
    QString name;
    QString nameClean;
    QString image;
    QList<Measure> measures;

    explicit Ingredient(const QJsonObject &ingredient);
    ~Ingredient();
};


#endif //COOKING_PROJECT_INGREDIENT_H
