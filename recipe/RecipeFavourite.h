//
// Created by Quentin Gillet on 27/03/2023.
//

#ifndef COOKING_APP_RECIPE_FAVOURITE_H
#define COOKING_APP_RECIPE_FAVOURITE_H


#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QStandardPaths>
#include "scrapper/Scrapper.h"

class RecipeFavourite
{
public:
    explicit RecipeFavourite();
    void saveRecipe(Recipe* recipe);
    void removeRecipe(int id);
    bool isFavourite(int id);

    QList<Recipe*> loadRecipes();
private:
    bool getFilePath(QString* path);

    QString folderName = "/CookingApp";
    QString fileName = "/recipes_favourite.json";
};


#endif
