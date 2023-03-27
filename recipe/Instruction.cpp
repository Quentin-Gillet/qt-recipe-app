//
// Created by Quentin Gillet on 27/03/2023.
//

#include "Instruction.h"

Instruction::Instruction(const QJsonObject &instruction)
{
    this->name = instruction["name"].toString();
    QJsonArray steps = instruction["steps"].toArray();
    for(int i = 0; i < steps.count(); i++)
    {
        this->instructionSteps.append(steps[i].toObject()["step"].toString());
    }
}

QJsonObject Instruction::instructionToJson()
{
    QJsonObject instructionJson;
    instructionJson.insert("name", this->name);

    QJsonArray stepsArray;
    for(int i = 0; i < this->instructionSteps.count(); i++)
    {
        QJsonObject stepJson;
        stepJson.insert("step", this->instructionSteps[i]);
        stepsArray.push_back(stepJson);
    }
    instructionJson.insert("steps", stepsArray);

    return instructionJson;
}
