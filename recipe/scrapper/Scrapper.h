//
// Created by Quentin Gillet on 12/03/2023.
//

#ifndef COOKING_PROJECT_SCRAPPER_H
#define COOKING_PROJECT_SCRAPPER_H

#include "../Recipe.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QEventLoop>
#include <QTimer>

#define API_KEY "f53f8f8706404344bde83f7abb700593"
#define BASE_URL "https://api.spoonacular.com/recipes/"

class Scrapper: public QObject
{
public:
    QList<Recipe*> getRandomRecipe(bool* success, int count = 9);
    QList<Recipe*> searchRecipe(bool* success, const QString& search, const QString& diet, int maxCalories, bool ignorePantry, int count = 9);
    static QJsonObject objectFromString(const QString& in);
    Scrapper();
private:
    QString makeRequest(const QString& url);

    QNetworkAccessManager* manager;
    QNetworkRequest request;
};

#endif //COOKING_PROJECT_SCRAPPER_H
