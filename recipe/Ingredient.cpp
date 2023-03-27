//
// Created by Quentin Gillet on 12/03/2023.
//

#include "Ingredient.h"

Ingredient::Ingredient(const QJsonObject &ingredient)
{
    this->name = ingredient["nameClean"].toString();

    QJsonObject measureObject = ingredient["measures"].toObject()["metric"].toObject();
    this->measure = new Measure(measureObject);
}

Ingredient::~Ingredient()
{
    delete measure;
}

QJsonObject Ingredient::ingredientToJson()
{
    QJsonObject ingredientJson;
    ingredientJson.insert("nameClean", this->name);

    QJsonObject measureJson;
    measureJson.insert("metric", this->measure->mesureToJson());
    ingredientJson.insert("measures", measureJson);

    return ingredientJson;
}
