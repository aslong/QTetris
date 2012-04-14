#include "JBlock.h"

/*
 * angle = 0
 *         *   
 *         ***
 *
 * angle = 270
 *         * 
 *         *
 *       * * 
 *
 * */


const QColor JBlock::FILL_COLOR = Qt::green;

JBlock::JBlock(QPointF point)
    :Block(point)
{
}

int JBlock::numberRowsOfBlocks()
{
    if (angle == 0 || angle == 180)
    {
        return 2;
    }
    else 
    {
        return 3;
    }
}

int JBlock::numberBlocksAtRow(int row)
{
    if (angle == 0)
    {
        if (row == 0)
        {
            return 3;
        }
        else
        {
            return 1;
        }
    }
    else if (angle == 90)
    {
        if (row == 0 || row == 1)
        {
            return 1;
        }
        else if (row == 2)
        {
            return 2;
        }
    }
    else if (angle == 180)
    {
        if (row == 0)
        {
            return 1;
        }
        else if (row == 1)
        {
            return 3;
        }
    }
    else if (angle == 270)
    {
        if (row == 0)
        {
            return 2;
        }
        else if (row == 1 || row == 2)
        {
            return 1;
        }
    }

    return 0;
}

QList<Block *> JBlock::getBlocksAtRow(int row)
{
    QList<Block *> rowOfBlocks;

    if (angle == 0)
    {
        if (row == 0)
        {
            rowOfBlocks << new Block(QPointF(x(), y() + BLOCK_SIZE / 2), FILL_COLOR);
            rowOfBlocks << new Block(QPointF(x() + BLOCK_SIZE / 2, y() + BLOCK_SIZE / 2), FILL_COLOR);
            rowOfBlocks << new Block(QPointF(x() + ((BLOCK_SIZE / 2) * 2), y() + BLOCK_SIZE / 2), FILL_COLOR);
        }
        else
        {
            rowOfBlocks << new Block(QPointF(x(), y()), FILL_COLOR);
        }
    }
    else if (angle == 90)
    {
        if (row == 0)
        {
            rowOfBlocks << new Block(QPointF(x(), y() + ((BLOCK_SIZE / 2) * 2)), FILL_COLOR);
        }
        else if (row == 1)
        {
            rowOfBlocks << new Block(QPointF(x(), y() + BLOCK_SIZE / 2), FILL_COLOR);
        }
        else
        {
            rowOfBlocks << new Block(QPointF(x(), y()), FILL_COLOR);
            rowOfBlocks << new Block(QPointF(x() + BLOCK_SIZE / 2, y()), FILL_COLOR);
        }
    }
    else if (angle == 180)
    {
        if (row == 0)
        {
            rowOfBlocks << new Block(QPointF(x() + ((BLOCK_SIZE / 2) * 2), y() + BLOCK_SIZE / 2), FILL_COLOR);
        }
        else
        {
            rowOfBlocks << new Block(QPointF(x(), y()), FILL_COLOR);
            rowOfBlocks << new Block(QPointF(x() + BLOCK_SIZE / 2, y()), FILL_COLOR);
            rowOfBlocks << new Block(QPointF(x() + ((BLOCK_SIZE / 2) * 2), y()), FILL_COLOR);
        }
    }
    else
    {
        if (row == 0)
        {
            rowOfBlocks << new Block(QPointF(x(), y() + ((BLOCK_SIZE / 2) * 2)), FILL_COLOR);
            rowOfBlocks << new Block(QPointF(x() + BLOCK_SIZE / 2, y() + ((BLOCK_SIZE / 2) * 2)), FILL_COLOR);
        }
        else if (row == 1)
        {
            rowOfBlocks << new Block(QPointF(x() + BLOCK_SIZE / 2, y() + BLOCK_SIZE / 2), FILL_COLOR);
        }
        else
        {
            rowOfBlocks << new Block(QPointF(x() + BLOCK_SIZE / 2, y()), FILL_COLOR);
        }
    }

    return rowOfBlocks;
}

QRectF JBlock::boundingRect() const
{
    if (angle == 90 || angle == 270)
    {
        return QRectF(x() + 1, y() + 1, BLOCK_HEIGHT - 1, BLOCK_WIDTH - 1);
    }

    return QRectF(x() + 1, y() + 1, BLOCK_WIDTH - 1, BLOCK_HEIGHT - 1);
}

QPainterPath JBlock::shape() const
{
    QPainterPath path;

    if (angle == 0)
    {
        path.addRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + (BLOCK_SIZE * 2) + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
    }
    else if (angle == 90)
    {
        path.addRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + 1, y() + (BLOCK_SIZE * 2) + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
    }
    else if (angle == 180)
    {
        path.addRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + (BLOCK_SIZE * 2) + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + (BLOCK_SIZE * 2) + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
    }
    else
    {
        path.addRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + BLOCK_SIZE + 1, y() + (BLOCK_SIZE * 2) + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
        path.addRect(x() + 1, 1 + y() + (BLOCK_SIZE * 2), BLOCK_SIZE - 1, BLOCK_SIZE - 1);
    }

    return path;
}


void JBlock::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    if (angle == 0)
    {
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x() + (BLOCK_SIZE * 2), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);

        painter->fillRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1, 1 + y() + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + BLOCK_SIZE + 1, 1 + y() + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + (BLOCK_SIZE * 2) + 1, 1 + y() + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
    }
    else if (angle == 90)
    {
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x(), y() + (BLOCK_SIZE * 2), BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE); 
        
        painter->fillRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1, y() + 1 + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1, y() + 1 + (BLOCK_SIZE * 2), BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1 + BLOCK_SIZE, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
    }
    else if (angle == 180)
    {
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x() + (BLOCK_SIZE * 2), y(), BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x() + (BLOCK_SIZE * 2), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE); 

        painter->fillRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1 + BLOCK_SIZE, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1 + (BLOCK_SIZE * 2), y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1 + (BLOCK_SIZE * 2), y() + 1 + BLOCK_SIZE, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
    }
    else 
    {
        painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_WIDTH); 
        painter->drawRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x() + BLOCK_SIZE, y() + (BLOCK_SIZE * 2), BLOCK_SIZE, BLOCK_SIZE); 
        painter->drawRect(x(), y() + (BLOCK_SIZE * 2), BLOCK_SIZE, BLOCK_SIZE); 

        painter->fillRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + BLOCK_SIZE + 1, y() + (BLOCK_SIZE * 2) + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
        painter->fillRect(x() + 1, 1 + y() + (BLOCK_SIZE * 2), BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 

    }
}
