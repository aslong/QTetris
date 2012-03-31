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

const QColor LBlock::FILL_COLOR = Qt::blue;

LBlock::LBlock(QPointF point)
    :Block(point)
{
}

QRectF LBlock::boundingRect() const
{
    if (angle == 90 || angle == 270)
    {
        return QRectF(x(), y(), BLOCK_HEIGHT, BLOCK_WIDTH);
    }

    return QRectF(x(), y(), BLOCK_WIDTH, BLOCK_HEIGHT);
}

QPainterPath LBlock::shape() const
{
    QPainterPath path;

    if (angle == 0)
    {
        path.addRect(x() + (BLOCK_SIZE * 2) + 1, y(), BLOCK_SIZE - 1, BLOCK_SIZE);
        path.addRect(x(), y() + BLOCK_SIZE + 1, BLOCK_SIZE, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE + 1, BLOCK_SIZE, BLOCK_SIZE - 1);
        path.addRect(x() + (BLOCK_SIZE * 2), y() + BLOCK_SIZE + 1, BLOCK_SIZE, BLOCK_SIZE - 1);
    }
    else if (angle == 90)
    {
        path.addRect(x(), y(), BLOCK_SIZE - 1, BLOCK_SIZE);
        path.addRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE);
        path.addRect(x(), y() + (BLOCK_SIZE * 2), BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE, y() + (BLOCK_SIZE * 2) + 1, BLOCK_SIZE, BLOCK_SIZE - 1);
    }
    else if (angle == 180)
    {
        path.addRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE - 1);
        path.addRect(x() + (BLOCK_SIZE * 2), y(), BLOCK_SIZE, BLOCK_SIZE - 1);
        path.addRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE);
    }
    else
    {
        path.addRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE + 1, y(), BLOCK_SIZE - 1, BLOCK_SIZE);
        path.addRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE + 1, y() + (BLOCK_SIZE * 2), BLOCK_SIZE - 1, BLOCK_SIZE - 1);
    }
    return path;
}


void LBlock::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    if (angle == 0) 
    {
        painter->drawRect(x() + (BLOCK_SIZE * 2), y(), BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x() + (BLOCK_SIZE * 2), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE); 

        painter->fillRect(x() + (BLOCK_SIZE * 2) + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1 + BLOCK_SIZE, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1 + (BLOCK_SIZE * 2), y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
    }
    else if (angle == 90)
    { 
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x(), y() + (BLOCK_SIZE * 2), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + BLOCK_SIZE, y() + (BLOCK_SIZE * 2), BLOCK_SIZE, BLOCK_SIZE); 

        painter->fillRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1, y() + 1 + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1, y() + 1 + (BLOCK_SIZE * 2), BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1 + BLOCK_SIZE, y() + 1 + (BLOCK_SIZE * 2), BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
    }
    else if (angle == 180)
    {
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + (BLOCK_SIZE * 2), y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);

        painter->fillRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1 + BLOCK_SIZE, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1 + (BLOCK_SIZE * 2), y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1, y() + 1 + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
    }
    else
    {
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x() + BLOCK_SIZE, y() + (BLOCK_SIZE * 2), BLOCK_SIZE, BLOCK_SIZE); 

        painter->fillRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1 + BLOCK_SIZE, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1 + BLOCK_SIZE, y() + 1 + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1 + BLOCK_SIZE, y() + 1 + (BLOCK_SIZE * 2), BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
    }
}
