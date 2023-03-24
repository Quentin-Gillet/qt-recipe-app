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
    {
        if (doc.isObject())
        {
            obj = doc.object();
        } else
        {
            qDebug() << "Document is not an object" << "\n";
        }
    } else
    {
        qDebug() << "Invalid JSON...\n" << in << "\n";
    }

    return obj;
}

Scrapper::Scrapper()
{
    manager = new QNetworkAccessManager();
}


QList<Recipe> Scrapper::getRandomRecipe(int count)
{
    //GENERATE URL WITH DEFINE API KEY AND BASE URL
    QString url = BASE_URL "random?number=" + QString::number(count) + "&apiKey=" API_KEY;
    QString response = makeRequest(url);
    QJsonObject obj = objectFromString(response);
    QJsonArray recipes = obj["recipes"].toArray();
    QList<Recipe> recipeList;
    for(auto && i : recipes)
    {
        Recipe recipe = Recipe(i.toObject());
        recipeList.append(recipe);
    }
    return recipeList;
}

QString Scrapper::makeRequest(const QString &url)
{
    QEventLoop loop;
    request.setUrl(url);
    QNetworkReply* reply = manager->get(request);
    connect(reply, &QNetworkReply::finished,&loop, &QEventLoop::quit);
    loop.exec();
    //Error checking for reply
    if (reply->error() == QNetworkReply::NoError)
    {
        return reply->readAll();
    } else
    {
        qDebug() << "Error connecting to API..." << "\n";
        qDebug() << reply->errorString() << "\n";
    }
    return "";
}
