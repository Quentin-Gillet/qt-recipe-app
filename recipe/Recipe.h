//
// Created by Quentin Gillet on 12/03/2023.
//

#ifndef COOKING_PROJECT_RECIPE_H
#define COOKING_PROJECT_RECIPE_H

#include <string>
#include <vector>
#include <QPixmap>
#include <QObject>
#include "Ingredient.h"
#include "Instruction.h"
#include "../qt/tools/FileDownloader.h"

class Recipe: public QObject
{
    Q_OBJECT
public:
    bool vegetarian;
    bool vegan;
    bool veryPopular;
    bool veryHealthy;

    QString title;
    QString imageUrl;
    QPixmap imagePixmap;
    int servings;
    int readyInMinutes;

    int id;
    bool isFavourite;

    QList<Ingredient*> ingredients;
    QList<Instruction*> instructions;

    FileDownloader* fileDownloader;

    explicit Recipe(const QJsonObject &recipeJson);
    ~Recipe();
    QJsonObject recipeToJson();
    void startImageDownload(QObject* object, const char* slot);

    QString getInstructionString();
private slots:
    void imageDownloaded();
signals:
    void imageLoaded(const QPixmap&);
};


#endif //COOKING_PROJECT_RECIPE_H
