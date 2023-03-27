//
// Created by Quentin Gillet on 27/03/2023.
//

#ifndef COOKINGAPP_INSTRUCTION_H
#define COOKINGAPP_INSTRUCTION_H

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

#endif //COOKINGAPP_INSTRUCTION_H
