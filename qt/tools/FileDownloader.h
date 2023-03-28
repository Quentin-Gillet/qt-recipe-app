//
// Created by Quentin Gillet on 23/03/2023.
//

#ifndef COOKING_APP_FILE_DOWNLOADER_H
#define COOKING_APP_FILE_DOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class FileDownloader : public QObject
{
Q_OBJECT
public:
    explicit FileDownloader(QObject *parent = nullptr);
    void downloadFile(const QUrl &imageUrl);
    [[nodiscard]] QByteArray downloadedData() const;

private:
    QNetworkAccessManager m_WebCtrl;
    QByteArray m_DownloadedData;

signals:
    void downloaded();

private slots:
    void fileDownloaded(QNetworkReply *pReply);
};

#endif
