//
// Created by Quentin Gillet on 25/03/2023.
//

#include "Tools.h"

void Tools::ClearLayout(QLayout *layout)
{
    if (layout == nullptr)
        return;
    QLayoutItem *item;
    while((item = layout->takeAt(0))) {
        if (item->layout()) {
            ClearLayout(item->layout());
            item->layout()->deleteLater();
        }
        if (item->widget()) {
            item->widget()->deleteLater();
        }
        delete item;
    }
}
