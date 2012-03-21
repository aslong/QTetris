#include "GameBorder.h"


QRectF GameBorder::boundingRect() const
{
    return QRectF(0, 0, 320, 480);
}

void GameBorder::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    painter->drawRect(0, 0, 320, 480);
}
