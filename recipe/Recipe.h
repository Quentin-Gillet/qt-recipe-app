//
// Created by Quentin Gillet on 12/03/2023.
//

#ifndef COOKING_PROJECT_RECIPE_H
#define COOKING_PROJECT_RECIPE_H

#include <string>
#include <vector>
#include "Ingredient.h"

class Recipe
{
public:
    bool vegetarian;
    bool vegan;
    bool veryPopular;

    QString title;
    QString image;
    int servings;
    int readyInMinutes;
    QStringList dishTypes;
    QString instructions;

    QList<Ingredient> ingredients;

    explicit Recipe(const QJsonObject &recipeJson);
    ~Recipe();
};


#endif //COOKING_PROJECT_RECIPE_H
