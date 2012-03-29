#include "LineBlock.h"

const QColor LineBlock::FILL_COLOR = Qt::cyan;

LineBlock::LineBlock(QPointF point)
    :Block(point)
{
    
}

QRectF LineBlock::boundingRect() const
{
    if (rotateBlock) 
    {
        return (QRectF(x(), y(), BLOCK_HEIGHT, BLOCK_WIDTH));
    }

    return (QRectF(x(), y(), BLOCK_WIDTH, BLOCK_HEIGHT));
}

void LineBlock::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    int blockWidth = rotateBlock ? +BLOCK_HEIGHT : +BLOCK_WIDTH;
    int blockHeight = rotateBlock ? +BLOCK_WIDTH : +BLOCK_HEIGHT;
    painter->drawRect(x(),y(), blockWidth, blockHeight);
    painter->fillRect(x() + 1,y() + 1, blockWidth - 2, blockHeight - 2, FILL_COLOR);
    for (int i = 1; i < BLOCK_WIDTH / BLOCK_SIZE; i++)
    {
        int newStartX = rotateBlock ? x() : x() + (BLOCK_SIZE * i);
        int newStartY = rotateBlock ? y() + (BLOCK_SIZE * i) : y();
        int newEndX = rotateBlock ? x() + BLOCK_HEIGHT : x() + BLOCK_SIZE * i;
        int newEndY = rotateBlock ? y() + BLOCK_SIZE * i : y() + BLOCK_HEIGHT;
        painter->drawLine(newStartX, newStartY, newEndX, newEndY);
    }
}
