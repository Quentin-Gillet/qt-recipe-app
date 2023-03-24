//
// Created by Quentin Gillet on 13/03/2023.
//

#ifndef COOKING_PROJECT_MEASURE_H
#define COOKING_PROJECT_MEASURE_H

#include <string>
#include <utility>

class Measure
{
public:
    double amount;
    std::string unitLong;
    std::string unitShort;

    Measure(double, std::string, std::string);
};


#endif //COOKING_PROJECT_MEASURE_H
