//
// Created by Quentin Gillet on 12/03/2023.
//

#include "Ingredient.h"

Ingredient::Ingredient(const QJsonObject &ingredient)
{
    this->name = ingredient["name"].toString();
    this->nameClean = ingredient["nameClean"].toString();
    this->image = ingredient["image"].toString();

    QJsonObject measureObject = ingredient["measures"].toObject()["metric"].toObject();
    this->measure = new Measure(measureObject);
}

Ingredient::~Ingredient()
{
    delete measure;
}
