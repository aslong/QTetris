#include "ZBlock.h"

/*
 * rotateBlock = false
 *          * * 
 *            * *         
 *
 * rotateBlock = true
 *           * 
 *         * *
 *         *   
 *
 * */
const QColor ZBlock::FILL_COLOR = Qt::darkGray;

ZBlock::ZBlock(QPointF point)
    :Block(point)
{
}

QRectF ZBlock::boundingRect() const
{
    if (angle == 90 || angle == 270)
    {
        return QRectF(x(), y(), BLOCK_HEIGHT, BLOCK_WIDTH);
    }

    return QRectF(x(), y(), BLOCK_WIDTH, BLOCK_HEIGHT);
}

QPainterPath ZBlock::shape() const
{
    QPainterPath path;

    if (angle == 0 || angle == 180)
    {
        path.addRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + (BLOCK_SIZE * 2) + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
    }
    else
    {
        path.addRect(x() + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + 1, y() + (BLOCK_SIZE * 2) + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
    }

    return path;
}

void ZBlock::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    if (angle == 0 || angle == 180)
    {
        
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + (BLOCK_SIZE * 2), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        
        painter->fillRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + (BLOCK_SIZE * 2) + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
    }
    else
    {
        painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x(), y() + (BLOCK_SIZE * 2), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);

        painter->fillRect(x() + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1, y() + (BLOCK_SIZE * 2) + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
    }
}
