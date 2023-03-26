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
#include "../qt/tools/FileDownloader.h"

class Recipe: public QObject
{
    Q_OBJECT
public:
    bool vegetarian;
    bool vegan;
    bool veryPopular;

    QString title;
    QString imageUrl;
    QPixmap imagePixmap;
    int servings;
    int readyInMinutes;
    QStringList dishTypes;
    QString instructions;

    QList<Ingredient*> ingredients;

    FileDownloader* fileDownloader;

    explicit Recipe(const QJsonObject &recipeJson);
    ~Recipe();

    void startImageDownload(QObject* object, const char* slot);
private slots:
    void imageDownloaded();
signals:
    void imageLoaded(const QPixmap&);
};


#endif //COOKING_PROJECT_RECIPE_H
