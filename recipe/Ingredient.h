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
    QString name;
    Measure* measure;

    explicit Ingredient(const QJsonObject &ingredient);
    ~Ingredient();

    QJsonObject ingredientToJson();
};


#endif //COOKING_PROJECT_INGREDIENT_H
