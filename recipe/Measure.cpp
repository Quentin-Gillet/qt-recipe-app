//
// Created by Quentin Gillet on 13/03/2023.
//

#include "Measure.h"

Measure::Measure(double amount, std::string unitLong, std::string unitShort)
{
    this->amount = amount;
    this->unitLong = std::move(unitLong);
    this->unitShort = std::move(unitShort);
}
