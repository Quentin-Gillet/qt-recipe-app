//
// Created by Quentin Gillet on 23/03/2023.
//

#include "FileDownloader.h"

FileDownloader::FileDownloader(QObject *parent) :
        QObject(parent){}

void FileDownloader::fileDownloaded(QNetworkReply *pReply)
{
    m_DownloadedData = pReply->readAll();
    //emit a signal
    pReply->deleteLater();
    emit downloaded();
}

QByteArray FileDownloader::downloadedData() const
{
    return m_DownloadedData;
}

void FileDownloader::downloadFile(const QUrl &imageUrl)
{
    connect(&m_WebCtrl, &QNetworkAccessManager::finished,
            this, &FileDownloader::fileDownloaded);

    QNetworkRequest request(imageUrl);
    m_WebCtrl.get(request);
}
