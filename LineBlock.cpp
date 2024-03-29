#include "LineBlock.h"

const QColor LineBlock::FILL_COLOR = Qt::cyan;

LineBlock::LineBlock(QPointF point)
    :Block(point)
{
    
}

int LineBlock::numberRowsOfBlocks()
{
    if (angle == 0 || angle == 180)
    {
        return 1;
    }
    else
    {
        return 4;
    }
}

int LineBlock::numberBlocksAtRow(int row)
{
    if (angle == 0 || angle == 180)
    {
        return 4;
    }
    else
    {
        return 1;
    }
}

QList<Block *> LineBlock::getBlocksAtRow(int row)
{
    QList<Block *> rowOfBlocks;

    if (angle == 0 || angle == 180)
    {
        rowOfBlocks << new Block(QPointF(x(), y()), FILL_COLOR);
        rowOfBlocks << new Block(QPointF(x() + BLOCK_SIZE / 2, y()), FILL_COLOR);
        rowOfBlocks << new Block(QPointF(x() + ((BLOCK_SIZE/2) * 2), y()), FILL_COLOR);
        rowOfBlocks << new Block(QPointF(x() + ((BLOCK_SIZE/2) * 3), y()), FILL_COLOR);
    }
    else
    {
        rowOfBlocks << new Block(QPointF(x(), y() + ((BLOCK_SIZE/2) * (3 - row))), FILL_COLOR);
    }

    return rowOfBlocks;
}

QRectF LineBlock::boundingRect() const
{
    if (angle == 90 || angle == 270) 
    {
        return (QRectF(x() + 1, y() + 1, BLOCK_HEIGHT - 1, BLOCK_WIDTH - 1));
    }

    return (QRectF(x() + 1, y() + 1, BLOCK_WIDTH - 1, BLOCK_HEIGHT - 1));
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

        painter->fillRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + (BLOCK_SIZE * 2) + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + (BLOCK_SIZE * 3) + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
    }
    else
    {
        painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x(), y() + (BLOCK_SIZE * 2), BLOCK_SIZE, BLOCK_SIZE);
        painter->drawRect(x(), y() + (BLOCK_SIZE * 3), BLOCK_SIZE, BLOCK_SIZE);

        painter->fillRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1, y() + (BLOCK_SIZE * 2) + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
        painter->fillRect(x() + 1, y() + (BLOCK_SIZE * 3) + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
    }
}
