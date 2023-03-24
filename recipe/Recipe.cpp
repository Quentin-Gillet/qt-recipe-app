//
// Created by Quentin Gillet on 12/03/2023.
//

#include "Recipe.h"

Recipe::Recipe(const QJsonObject &recipeJson)
{
    this->vegetarian = recipeJson["vegetarian"].toBool();
    this->vegan = recipeJson["vegan"].toBool();
    this->veryPopular = recipeJson["veryPopular"].toBool();
    this->title = recipeJson["title"].toString().toStdString();
    this->image = recipeJson["image"].toString().toStdString();
    this->servings = recipeJson["servings"].toInt();
    this->readyInMinutes = recipeJson["readyInMinutes"].toInt();
    this->instructions = recipeJson["instructions"].toString().toStdString();
    //dishTypes from json array
    QJsonArray dishTypesJson = recipeJson["dishTypes"].toArray();
    for (auto && i : dishTypesJson)
    {
        this->dishTypes.append(i.toString());
    }

    QJsonArray ingredientsJson = recipeJson["extendedIngredients"].toArray();
    for (int i = 0; i < ingredientsJson.size(); i++)
    {
        QJsonObject ingredientJson = ingredientsJson[i].toObject();
        Ingredient ingredient(ingredientJson);
        this->ingredients.append(ingredient);
    }
}

Recipe::~Recipe()
{
    this->dishTypes.clear();
    this->ingredients.clear();
}
