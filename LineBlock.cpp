#include "LineBlock.h"

LineBlock::LineBlock(QPointF point)
    :Block(point)
{
    
}

QRectF LineBlock::boundingRect() const
{
    return (QRectF(x(), y(), BLOCK_WIDTH, BLOCK_HEIGHT));
}

void LineBlock::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    painter->drawRect(x(),y(), BLOCK_WIDTH, BLOCK_HEIGHT);
    for (int i = 1; i < BLOCK_WIDTH / BLOCK_SIZE; i++)
    {
        painter->drawLine(x() + (BLOCK_SIZE * i), y(), x() + BLOCK_SIZE * i, y() + BLOCK_HEIGHT);
    }
}
