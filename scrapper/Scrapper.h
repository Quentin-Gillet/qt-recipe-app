//
// Created by Quentin Gillet on 12/03/2023.
//

#ifndef COOKING_PROJECT_SCRAPPER_H
#define COOKING_PROJECT_SCRAPPER_H

#include "../recipe/Recipe.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>
#include <vector>

#define API_KEY "fed97457eab24db9b9e334767d0cf434"
#define BASE_URL "https://api.spoonacular.com/recipes/"

class Scrapper: public QObject
{
public:
    QList<Recipe> getRandomRecipe(int count = 9);
    QList<Recipe> searchRecipe(QString& search, int count = 9);
    static QJsonObject objectFromString(const QString& in);
    Scrapper();
private:
    QString makeRequest(const QString& url);

    QNetworkAccessManager* manager;
    QNetworkRequest request;
};

#endif //COOKING_PROJECT_SCRAPPER_H
