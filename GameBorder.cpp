#include "GameBorder.h"

GameBorder::GameBorder(QPointF newPosition)
{
    position = newPosition;
}

QRectF GameBorder::boundingRect() const
{
    return QRectF(position.x(), position.y(), 305, 480);
}

void GameBorder::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    painter->drawRect(position.x(), position.y(), 305, 480);
}
