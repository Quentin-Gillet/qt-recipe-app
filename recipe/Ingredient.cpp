//
// Created by Quentin Gillet on 12/03/2023.
//

#include "Ingredient.h"

Ingredient::Ingredient(const QJsonObject &ingredient)
{
    this->amount = ingredient["amount"].toInt();
    this->consistency = ingredient["consistency"].toString().toStdString();
    this->name = ingredient["name"].toString().toStdString();
    this->nameClean = ingredient["nameClean"].toString().toStdString();
    this->image = ingredient["image"].toString().toStdString();

    QJsonArray measures = ingredient["measures"].toArray();
    for (auto && i : measures)
    {
        QJsonObject jsonMeasure = i.toObject()["metric"].toObject();
        Measure measure (jsonMeasure["amount"].toDouble(), jsonMeasure["unitLong"].toString().toStdString(), jsonMeasure["unitShort"].toString().toStdString());
    }
}

Ingredient::~Ingredient()
{
    this->measures.clear();
}
