//
// Created by Quentin Gillet on 12/03/2023.
//

#include "Ingredient.h"

Ingredient::Ingredient(const QJsonObject &ingredient)
{
    this->amount = ingredient["amount"].toInt();
    this->consistency = ingredient["consistency"].toString();
    this->name = ingredient["name"].toString();
    this->nameClean = ingredient["nameClean"].toString();
    this->image = ingredient["image"].toString();

    QJsonArray measures = ingredient["measures"].toArray();
    for (auto && i : measures)
    {
        QJsonObject jsonMeasure = i.toObject()["metric"].toObject();
        Measure measure (jsonMeasure);
    }
}

Ingredient::~Ingredient()
{
    this->measures.clear();
}
