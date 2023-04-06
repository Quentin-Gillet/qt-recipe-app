//
// Created by Quentin Gillet on 12/03/2023.
//

#include "Scrapper.h"

QJsonObject Scrapper::objectFromString(const QString &in)
{
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());

    // check validity of the document
    if (!doc.isNull())
        if (doc.isObject())
            obj = doc.object();
        else
            qDebug() << "Document is not an object" << "\n";
    else
        qDebug() << "Invalid JSON...\n" << in << "\n";

    return obj;
}

Scrapper::Scrapper()
{
    manager = new QNetworkAccessManager();
}

QList<Recipe *> Scrapper::searchRecipe(bool* success, const QString &search, const QString &diet, int maxCalories,
                                       bool ignorePantry, int count)
{
    QString dietParameter = !diet.compare("All") ? "" : "&diet=" + diet.toLower();
    QString maxCaloriesParameter = maxCalories == 0 ? "" : "&maxCalories=" + QString::number(maxCalories);
    QString url = BASE_URL "complexSearch?number=" + QString::number(count) + QString("&query=" + search)
                  + "&apiKey=" API_KEY
                  + dietParameter
                  + maxCaloriesParameter
                  + "&addRecipeInformation=true"
                  + "&ignorePantry=" + QString::number(ignorePantry)
                  + "&fillIngredients=true";
    QString response = makeRequest(url);
    if(response == "ERROR")
    {
      *success = false;
      return QList<Recipe*> {};
    }
    QJsonObject obj = objectFromString(response);
    QJsonArray recipes = obj["results"].toArray();
    QList<Recipe *> recipeList;
    for (auto &&i: recipes)
    {
        auto *recipe = new Recipe(i.toObject());
        recipeList.append(recipe);
    }
    *success = true;
    return recipeList;
}

QList<Recipe *> Scrapper::getRandomRecipe(bool* success, int count)
{
    //GENERATE URL WITH DEFINE API KEY AND BASE URL
    QString url = BASE_URL "random?number=" + QString::number(count) + "&apiKey=" API_KEY;
    QString response = makeRequest(url);
    if(response == "ERROR")
    {
      *success = false;
      return QList<Recipe*> {};
    }
    QJsonObject obj = objectFromString(response);
    QJsonArray recipes = obj["recipes"].toArray();
    QList<Recipe *> recipeList;
    for (auto &&i: recipes)
    {
        auto *recipe = new Recipe(i.toObject());
        recipeList.append(recipe);
    }
    *success = true;
    return recipeList;
}

QString Scrapper::makeRequest(const QString &url)
{
    QTimer timer;
    timer.setSingleShot(true);

    QEventLoop loop;
    request.setUrl(url);
    QNetworkReply *reply = manager->get(request);
    connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    timer.start(5000);
    loop.exec();

    if (timer.isActive()) {
      timer.stop();
        // Error checking for reply
        if (reply->error() == QNetworkReply::NoError) {
            return reply->readAll();
        } else {
            qDebug() << "Error connecting to API..." << "\n";
            qDebug() << reply->errorString() << "\n";
        }
    }else {
      disconnect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
      reply->abort();
    }
    return "ERROR";
}
