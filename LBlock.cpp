#include "LBlock.h"

/*
 * rotateBlock = false
 *           * 
 *         ***
 *
 * rotateBlock = true
 *         *
 *         *
 *         * *
 *
 * */
LBlock::LBlock(QPointF point)
    :Block(point)
{
}

QRectF LBlock::boundingRect() const
{
    if (rotateBlock)
    {
        return QRectF(x(), y(), BLOCK_HEIGHT, BLOCK_WIDTH);
    }

    return QRectF(x(), y(), BLOCK_WIDTH, BLOCK_HEIGHT);
}

QPainterPath LBlock::shape() const
{
    QPainterPath path;

    if (rotateBlock)
    {
        path.addRect(x(), y(), BLOCK_SIZE - 1, BLOCK_WIDTH);
        path.addRect(x() + BLOCK_SIZE + 1, 1 + y() + (BLOCK_SIZE * 2), BLOCK_SIZE - 1, BLOCK_SIZE - 1);
    }
    else
    {
        path.addRect(x() + (BLOCK_SIZE * 2) + 1, y(), BLOCK_SIZE - 1, BLOCK_SIZE);
        path.addRect(x(), y() + BLOCK_SIZE + 1, BLOCK_WIDTH, BLOCK_SIZE - 1);
    }
    return path;
}


void LBlock::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    int blockWidth = rotateBlock ? +BLOCK_HEIGHT : +BLOCK_WIDTH;
    int blockHeight = rotateBlock ? +BLOCK_WIDTH : +BLOCK_HEIGHT;
    if (rotateBlock) 
    {
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_WIDTH); 
        painter->drawRect(x() + BLOCK_SIZE, y() + (BLOCK_SIZE * 2), BLOCK_SIZE, BLOCK_SIZE); 
    }
    else
    { 
        painter->drawRect(x() + (BLOCK_SIZE * 2), y(), BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x(), y() + BLOCK_SIZE, blockWidth, BLOCK_SIZE);
    }
    for (int i = 1; i < BLOCK_WIDTH / BLOCK_SIZE; i++)
    {
        int newStartX = rotateBlock ? x() : x() + (BLOCK_SIZE * i);
        int newStartY = rotateBlock ? y() + (BLOCK_SIZE * i) : y() + BLOCK_SIZE;
        int newEndX = rotateBlock ? x() + BLOCK_SIZE : x() + (BLOCK_SIZE * i);
        int newEndY = rotateBlock ? y() + (BLOCK_SIZE * i) : y() + BLOCK_HEIGHT;
        painter->drawLine(newStartX, newStartY, newEndX, newEndY);
    }
}
