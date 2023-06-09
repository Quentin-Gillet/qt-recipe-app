//
// Created by Quentin Gillet on 13/03/2023.
//

#ifndef COOKING_PROJECT_MEASURE_H
#define COOKING_PROJECT_MEASURE_H

#include <QString>
#include <QJsonObject>

class Measure
{
public:
    double amount;
    QString unitLong;
    QString unitShort;

    explicit Measure(const QJsonObject&);
    [[nodiscard]] QJsonObject mesureToJson() const;
};


#endif //COOKING_PROJECT_MEASURE_H
