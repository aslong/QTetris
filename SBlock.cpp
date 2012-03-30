#include "SBlock.h"

/*
 * rotateBlock = false
 *          * * 
 *        * *
 *
 * rotateBlock = true
 *         *
 *         * *
 *           *
 *
 * */
SBlock::SBlock(QPointF point)
    :Block(point)
{
}

QRectF SBlock::boundingRect() const
{
    if (rotateBlock)
    {
        return QRectF(x(), y(), BLOCK_HEIGHT, BLOCK_WIDTH);
    }

    return QRectF(x(), y(), BLOCK_WIDTH, BLOCK_HEIGHT);
}

QPainterPath SBlock::shape() const
{
    QPainterPath path;

    if (rotateBlock)
    {
        path.addRect(x(), y(), BLOCK_SIZE - 1, BLOCK_SIZE);
        path.addRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE);
        path.addRect(x() + BLOCK_SIZE, y() + (BLOCK_SIZE * 2), BLOCK_SIZE - 1, BLOCK_SIZE);
    }
    else
    {
        path.addRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE);
        path.addRect(x() + (BLOCK_SIZE * 2), y(), BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x(), y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE);
    }
    return path;
}


void SBlock::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    painter->drawPath(shape());
}
