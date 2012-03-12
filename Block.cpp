#include "Block.h"

Block::Block()
{
}

QRectF Block::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void Block::paint(QPainter *painter, 
                const QStyleOptionGraphicsItem *option,
                QWidget *widget)
{
    painter->drawRect(0,0, 10, 10);
}
