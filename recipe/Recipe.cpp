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
    this->veryHealthy = recipeJson["veryHealthy"].toBool();
    this->isFavourite = recipeFavourite.isFavourite(this->id);

    QJsonArray ingredientsJson = recipeJson["extendedIngredients"].toArray();
    for (int i = 0; i < ingredientsJson.count(); i++)
    {
        QJsonObject ingredientJson = ingredientsJson[i].toObject();
        Ingredient* ingredient = new Ingredient(ingredientJson);
        this->ingredients.append(ingredient);
    }

    QJsonArray instructionsJson = recipeJson["analyzedInstructions"].toArray();
    for (int i = 0; i < instructionsJson.count(); i++)
    {
        QJsonObject instructionJson = instructionsJson[i].toObject();
        Instruction* ingredient = new Instruction(instructionJson);
        this->instructions.append(ingredient);
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
    recipeJson.insert("veryHealthy", this->veryHealthy);

    QJsonArray ingredientsJson;
    for(int i = 0; i < this->ingredients.count(); i++)
    {
        QJsonObject ingredientJson = this->ingredients[i]->ingredientToJson();
        ingredientsJson.push_back(ingredientJson);
    }
    recipeJson.insert("extendedIngredients", ingredientsJson);

    QJsonArray instructionsJson;
    for(int i = 0; i < this->instructions.count(); i++)
    {
        QJsonObject instructionJson = this->instructions[i]->instructionToJson();
        instructionsJson.push_back(instructionJson);
    }
    recipeJson.insert("analyzedInstructions", instructionsJson);

    return recipeJson;
}

QString Recipe::getInstructionString()
{
    QString instructionsString;

    for(int i = 0; i < this->instructions.count(); i++)
    {
        Instruction* instruction = this->instructions[i];
        if(!instruction->name.isEmpty())
        {
            instructionsString.append("<b> " + QString::number(i + 1) + " - " + instruction->name + "</b>");
            instructionsString.append("<blockquote>");
        }
        for(int j = 0; j < instruction->instructionSteps.count(); j++)
        {
            instructionsString.append("-> " + instruction->instructionSteps[j] + "<br/>");
        }
        if(!instruction->name.isEmpty())
            instructionsString.append("</blockquote>");
    }

    return instructionsString;
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

