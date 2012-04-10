#include "Block.h"

const QColor Block::FILL_COLOR = Qt::red;

Block::Block(const QPointF startPosition)
{
    setPos(startPosition);
    angle = 0;
    rotateBlock = false;
}

int Block::numberRowsOfBlocks()
{
    return 1;
}

int Block::numberBlocksAtRow(int row)
{
    if (row == 0)
    {
        return 1;
    }

    return 0;
}

QRectF Block::boundingRect() const
{
    return QRectF(x() + 1, y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1);
}

void Block::paint(QPainter *painter, 
                const QStyleOptionGraphicsItem *option,
                QWidget *widget)
{
    painter->drawRect(x(),y(), BLOCK_SIZE, BLOCK_SIZE);
    painter->fillRect(x() + 1,y() + 1, BLOCK_SIZE - 1, BLOCK_SIZE - 1, FILL_COLOR);
    
}

void Block::moveRight(int spaces)
{
    setX(x() + spaces);
}

void Block::moveLeft(int spaces)
{
    setX(x() - spaces);
}

void Block::moveUp(int spaces)
{
    setY(y() - spaces);
}

void Block::moveDown(int spaces)
{
    setY(y() + spaces);
}

void Block::rotate()
{
    prepareGeometryChange();
    rotateBlock = !rotateBlock;
    if (angle == 270) 
    {
        angle = 0;
    }
    else
    {
        angle += 90;
    }
}
