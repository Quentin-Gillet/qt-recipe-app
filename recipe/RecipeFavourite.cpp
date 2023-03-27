//
// Created by Quentin Gillet on 27/03/2023.
//

#include "RecipeFavourite.h"

RecipeFavourite::RecipeFavourite(){}

void RecipeFavourite::saveRecipe(Recipe *recipe)
{
    QString path;
    bool validPath = getFilePath(&path);
    if (validPath) {
        QFile file(path + this->fileName);
        if (!QFileInfo::exists(path + this->fileName))
        {
            QJsonObject recipesJson;
            QJsonArray recipesArray;
            recipesArray.push_back(recipe->recipeToJson());
            recipesJson.insert("recipes", recipesArray);

            QJsonDocument doc(recipesJson);
            if (file.open(QIODevice::ReadWrite | QIODevice::Text))
                file.write(doc.toJson());
        } else
        {
            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QJsonObject oldJson = Scrapper::objectFromString(file.readAll());
                QJsonArray existingRecipesArray = oldJson["recipes"].toArray();
                file.close();

                if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                {
                    QJsonObject recipesJson;
                    QJsonArray recipesArray;
                    for (auto &&i: existingRecipesArray)
                    {
                        recipesArray.push_back(i.toObject());
                    }
                    recipesArray.push_back(recipe->recipeToJson());
                    recipesJson.insert("recipes", recipesArray);

                    QJsonDocument finalDoc(recipesJson);
                    file.write(finalDoc.toJson());
                }
            }
        }
    }
}

QList<Recipe *> RecipeFavourite::loadRecipes()
{
    QString path;
    bool validPath = getFilePath(&path);
    if (validPath)
    {
        QFile file(path + this->fileName);
        if (QFileInfo::exists(path + this->fileName))
        {
            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QJsonObject oldJson = Scrapper::objectFromString(file.readAll());
                QJsonArray recipes = oldJson["recipes"].toArray();
                file.close();
                QList<Recipe*> recipeList;
                for(auto && i : recipes)
                {
                    Recipe* recipe = new Recipe(i.toObject());
                    recipeList.append(recipe);
                }
                return recipeList;
            }
        }
    }
    return QList<Recipe*>{};
}

bool RecipeFavourite::getFilePath(QString* path)
{
    QString standardPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QDir pathDirectory{standardPath + this->folderName};
    if(!pathDirectory.exists())
        pathDirectory.mkdir(pathDirectory.absolutePath());
    if (standardPath.isEmpty()) qFatal("Cannot determine settings storage location");
    *path = pathDirectory.absolutePath();
    return (pathDirectory.mkpath(pathDirectory.absolutePath())
            && QDir::setCurrent(pathDirectory.absolutePath()));
}

bool RecipeFavourite::isFavourite(int id)
{
    QString path;
    bool validPath = getFilePath(&path);
    if (validPath)
    {
        QFile file(path + this->fileName);
        if (QFileInfo::exists(path + this->fileName))
        {
            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QJsonObject oldJson = Scrapper::objectFromString(file.readAll());
                QJsonArray recipes = oldJson["recipes"].toArray();
                file.close();
                for(auto && i : recipes)
                {
                    QJsonObject recipe = i.toObject();
                    if(recipe["id"].toInt() == id)
                        return true;
                }
                return false;
            }
        }
    }
    return false;
}

void RecipeFavourite::removeRecipe(int id)
{
    QString path;
    bool validPath = getFilePath(&path);
    if (validPath)
    {
        QFile file(path + this->fileName);
        if (QFileInfo::exists(path + this->fileName))
        {
            if (file.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QJsonObject oldJson = Scrapper::objectFromString(file.readAll());
                QJsonArray existingRecipesArray = oldJson["recipes"].toArray();
                file.close();

                if (file.open(QIODevice::WriteOnly | QIODevice::Truncate))
                {
                    QJsonObject recipesJson;
                    QJsonArray recipesArray;
                    for (auto &&i: existingRecipesArray)
                    {
                        QJsonObject recipe = i.toObject();
                        if(recipe["id"].toInt() == id)
                            continue;
                        recipesArray.push_back(recipe);
                    }
                    recipesJson.insert("recipes", recipesArray);

                    QJsonDocument finalDoc(recipesJson);
                    file.write(finalDoc.toJson());
                }
            }
        }
    }
}
