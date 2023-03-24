//
// Created by Quentin Gillet on 23/03/2023.
//

#ifndef COOKINGAPP_FILEDOWNLOADER_H
#define COOKINGAPP_FILEDOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class FileDownloader : public QObject
{
Q_OBJECT
public:
    explicit FileDownloader(QUrl imageUrl, QObject *parent = 0);
    virtual ~FileDownloader();
    QByteArray downloadedData() const;

signals:
    void downloaded();

private slots:
    void fileDownloaded(QNetworkReply* pReply);
private:
    QNetworkAccessManager m_WebCtrl;
    QByteArray m_DownloadedData;
};

#endif //COOKINGAPP_FILEDOWNLOADER_H
