#include "LineBlock.h"

const QColor LineBlock::FILL_COLOR = Qt::cyan;

LineBlock::LineBlock(QPointF point)
    :Block(point)
{
    
}

QRectF LineBlock::boundingRect() const
{
    if (angle == 90 || angle == 270) 
    {
        return (QRectF(x(), y(), BLOCK_HEIGHT, BLOCK_WIDTH));
    }

    return (QRectF(x(), y(), BLOCK_WIDTH, BLOCK_HEIGHT));
}

void LineBlock::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    if (angle == 0 || angle == 180)
    {
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + (BLOCK_SIZE * 2), y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + (BLOCK_SIZE * 3), y(), BLOCK_SIZE, BLOCK_SIZE);
    }
    else
    {
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x(), y() + (BLOCK_SIZE * 2), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x(), y() + (BLOCK_SIZE * 3), BLOCK_SIZE, BLOCK_SIZE);
    }
}
