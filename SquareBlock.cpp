#include "SquareBlock.h"

const QColor SquareBlock::FILL_COLOR = Qt::green;

SquareBlock::SquareBlock(QPointF point)
    :Block(point)
{
}

int SquareBlock::numberRowsOfBlocks()
{
    return 2;
}
        
int SquareBlock::numberBlocksAtRow(int row)
{
    return 2;
}

QList<Block *> SquareBlock::getBlocksAtRow(int row)
{
    QList<Block *> rowOfBlocks;

    if (row == 0)
    {
        rowOfBlocks << new Block(QPointF(x(), y() + BLOCK_SIZE / 2), FILL_COLOR);
        rowOfBlocks << new Block(QPointF(x() + BLOCK_SIZE / 2, y() + BLOCK_SIZE / 2), FILL_COLOR);
    }
    else
    {
        rowOfBlocks << new Block(QPointF(x(), y()), FILL_COLOR);
        rowOfBlocks << new Block(QPointF(x() + BLOCK_SIZE / 2, y()), FILL_COLOR);
    }

    return rowOfBlocks;
}

QRectF SquareBlock::boundingRect() const
{
    return QRectF(x() + 1, y() + 1, BLOCK_WIDTH - 1, BLOCK_HEIGHT - 1);
}

void SquareBlock::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE); 
    painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
    painter->drawRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
    painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE);

    painter->fillRect(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR); 
    painter->fillRect(x() + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
    painter->fillRect(x() + BLOCK_SIZE + 1, y() + BLOCK_SIZE + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
    painter->fillRect(x() + BLOCK_SIZE + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
}
