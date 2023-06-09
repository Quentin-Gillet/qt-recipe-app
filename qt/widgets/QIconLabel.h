//
// Created by Quentin Gillet on 26/03/2023.
//

#ifndef COOKING_APP_QICON_LABEL_H
#define COOKING_APP_QICON_LABEL_H


#include <QLabel>
#include <QWidget>
#include <QBoxLayout>

class QIconLabel: public QWidget
{
Q_OBJECT
public:
    explicit QIconLabel(const QString& text, QWidget* parent = nullptr);
    void setIcon(const QIcon& icon, int size);
private:
    QLabel* textLabel;
    QLabel* iconLabel;
};


#endif
