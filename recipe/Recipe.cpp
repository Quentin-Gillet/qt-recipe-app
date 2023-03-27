//
// Created by Quentin Gillet on 12/03/2023.
//

#include "Recipe.h"
#include "RecipeFavourite.h"

Recipe::Recipe(const QJsonObject &recipeJson)
{
    RecipeFavourite recipeFavourite;

    this->vegetarian = recipeJson["vegetarian"].toBool();
    this->vegan = recipeJson["vegan"].toBool();
    this->veryPopular = recipeJson["veryPopular"].toBool();
    this->title = recipeJson["title"].toString().split(",")[0];
    this->imageUrl = recipeJson["image"].toString();
    this->servings = recipeJson["servings"].toInt();
    this->readyInMinutes = recipeJson["readyInMinutes"].toInt();
    this->id = recipeJson["id"].toInt();
    this->instructions = recipeJson["instructions"].toString();
    this->isFavourite = recipeFavourite.isFavourite(this->id);

    QJsonArray ingredientsJson = recipeJson["extendedIngredients"].toArray();
    for (int i = 0; i < ingredientsJson.size(); i++)
    {
        QJsonObject ingredientJson = ingredientsJson[i].toObject();
        Ingredient* ingredient = new Ingredient(ingredientJson);
        this->ingredients.append(ingredient);
    }
}

QJsonObject Recipe::recipeToJson()
{
    QJsonObject recipeJson;
    recipeJson.insert("vegetarian", this->vegetarian);
    recipeJson.insert("vegan", this->vegan);
    recipeJson.insert("veryPopular", this->veryPopular);
    recipeJson.insert("title", this->title);
    recipeJson.insert("image", this->imageUrl);
    recipeJson.insert("servings", this->servings);
    recipeJson.insert("readyInMinutes", this->readyInMinutes);
    recipeJson.insert("id", this->id);

    QJsonArray ingredientsJson;
    for(int i = 0; i < this->ingredients.count(); i++)
    {
        QJsonObject ingredientJson = this->ingredients[i]->ingredientToJson();
        ingredientsJson.push_back(ingredientJson);
    }
    recipeJson.insert("extendedIngredients", ingredientsJson);

    return recipeJson;
}

void Recipe::startImageDownload(QObject* object, const char* slot)
{
    QUrl qUrl(this->imageUrl);
    fileDownloader = new FileDownloader(qUrl, this);

    connect(fileDownloader, &FileDownloader::downloaded,
            this, &Recipe::imageDownloaded);
    connect(this, SIGNAL(imageLoaded(QPixmap)),
            object, slot);
}

void Recipe::imageDownloaded()
{
    this->imagePixmap.loadFromData(fileDownloader->downloadedData());
    emit imageLoaded(this->imagePixmap);
}

Recipe::~Recipe()
{
    this->ingredients.clear();
}


