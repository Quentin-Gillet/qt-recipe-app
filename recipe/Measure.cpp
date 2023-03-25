//
// Created by Quentin Gillet on 13/03/2023.
//

#include "Measure.h"

Measure::Measure(const QJsonObject & measures)
{
    this->amount = measures["amount"].toDouble();
    this->unitLong = measures["unitLong"].toString();
    this->unitShort = measures["unitShort"].toString();
}
