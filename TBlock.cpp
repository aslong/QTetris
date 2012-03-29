#include "TBlock.h"

/*
 * angle = 0 
 *          * 
 *         ***
 *
 * angle = 90
 *         *
 *         * *
 *         * 
 *
 * angle = 180
 *         * * *
 *           *
 *
 * angle = 270
 *           *
 *         * *
 *           *
 * */

const QColor TBlock::FILL_COLOR = Qt::yellow;

TBlock::TBlock(QPointF point)
    :Block(point)
{
    angle = 0;
}

QRectF TBlock::boundingRect() const
{
    if (angle == 90 || angle == 270)
    {
        return QRectF(x(), y(), BLOCK_HEIGHT, BLOCK_WIDTH);
    }

    return QRectF(x(), y(), BLOCK_WIDTH, BLOCK_HEIGHT);
}

QPainterPath TBlock::shape() const
{
    QPainterPath path;

    if (angle == 0)
    {
        path.addRect(x() + BLOCK_SIZE + 1, y(), BLOCK_SIZE - 2, BLOCK_SIZE - 1);
        path.addRect(x(), y() + BLOCK_SIZE + 1, BLOCK_WIDTH, BLOCK_SIZE - 1);
    }
    else if (angle == 90)
    {
        path.addRect(x(), y(), BLOCK_SIZE - 1, BLOCK_WIDTH);
        path.addRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 2);
    }
    else if (angle == 180)
    {
        path.addRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 2, BLOCK_SIZE - 1);
        path.addRect(x() + 1, y(), BLOCK_WIDTH, BLOCK_SIZE - 1);
    }
    else if (angle == 270)
    {
        path.addRect(x() + BLOCK_SIZE + 1, y(), BLOCK_SIZE - 1, BLOCK_WIDTH);
        path.addRect(x(), y() + BLOCK_SIZE + 1, BLOCK_SIZE, BLOCK_SIZE - 2);
    }

    return path;
}


void TBlock::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    if (angle == 0)
    { 
        painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_WIDTH, BLOCK_SIZE);
        painter->fillRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 2, BLOCK_SIZE - 2, FILL_COLOR); 
        painter->fillRect(x() + 1, y() + BLOCK_SIZE + 1, BLOCK_WIDTH - 2, BLOCK_SIZE - 2, FILL_COLOR);

        for (int i = 1; i < BLOCK_WIDTH / BLOCK_SIZE; i++)
        {
            int newStartX =  x() + (BLOCK_SIZE * i);
            int newStartY =  y() + BLOCK_SIZE;
            int newEndX =  x() + (BLOCK_SIZE * i);
            int newEndY =  y() + BLOCK_HEIGHT;
            painter->drawLine(newStartX, newStartY, newEndX, newEndY);
        }
    }
    else if (angle == 90) 
    {
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_WIDTH); 
        painter->drawRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE); 
        painter->fillRect(x() + 1, y() + 1, BLOCK_SIZE - 2, BLOCK_WIDTH - 2, FILL_COLOR); 
        painter->fillRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 2, BLOCK_SIZE - 2, FILL_COLOR); 

        for (int i = 1; i < BLOCK_WIDTH / BLOCK_SIZE; i++)
        {
            int newStartX = x();
            int newStartY = y() + (BLOCK_SIZE * i);
            int newEndX = x() + BLOCK_SIZE;
            int newEndY = y() + (BLOCK_SIZE * i);
            painter->drawLine(newStartX, newStartY, newEndX, newEndY);
        }
    }
    else if (angle == 180)
    {
        painter->drawRect(x(), y(), BLOCK_WIDTH, BLOCK_SIZE); 
        painter->drawRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        painter->fillRect(x(), y(), BLOCK_WIDTH - 2, BLOCK_SIZE - 2, FILL_COLOR); 
        painter->fillRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 2, BLOCK_SIZE - 2, FILL_COLOR);
        for (int i = 1; i < BLOCK_WIDTH / BLOCK_SIZE; i++)
        {
            int newStartX =  x() + (BLOCK_SIZE * i);
            int newStartY =  y();
            int newEndX =  x() + (BLOCK_SIZE * i);
            int newEndY =  y() + BLOCK_SIZE;
            painter->drawLine(newStartX, newStartY, newEndX, newEndY);
        }
    }
    else if (angle == 270)
    {
        painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_WIDTH); 
        painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE); 
        painter->fillRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 2, BLOCK_WIDTH - 2, FILL_COLOR); 
        painter->fillRect(x() + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 2, BLOCK_SIZE - 2, FILL_COLOR); 
        for (int i = 1; i < BLOCK_WIDTH / BLOCK_SIZE; i++)
        {
            int newStartX = x() + BLOCK_SIZE;
            int newStartY = y() + (BLOCK_SIZE * i);
            int newEndX = x() + BLOCK_HEIGHT;
            int newEndY = y() + (BLOCK_SIZE * i);
            painter->drawLine(newStartX, newStartY, newEndX, newEndY);
        }
    }
}

void TBlock::rotate()
{
    Block::rotate(); 
    if (angle == 270) 
    {
        angle = 0;
    }
    else
    {
        angle += 90;
    }
    
}
