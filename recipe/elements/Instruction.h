//
// Created by Quentin Gillet on 27/03/2023.
//

#ifndef COOKING_APP_INSTRUCTION_H
#define COOKING_APP_INSTRUCTION_H

#include <QJsonObject>
#include <QJsonArray>
#include <QStringList>

class Instruction
{
public:
    QString name;
    QStringList instructionSteps;

    explicit Instruction(const QJsonObject &instruction);
    ~Instruction() { instructionSteps.clear(); }

    QJsonObject instructionToJson();
};

#endif //COOKING_APP_INSTRUCTION_H
