#include "Block.h"

Block::Block(const QPointF startPosition)
{
    setPos(startPosition);
    rotateBlock = false;
}

QRectF Block::boundingRect() const
{
    return QRectF(x(), y(), BLOCK_SIZE, BLOCK_SIZE);
}

void Block::paint(QPainter *painter, 
                const QStyleOptionGraphicsItem *option,
                QWidget *widget)
{
    painter->drawRect(x(),y(), BLOCK_SIZE, BLOCK_SIZE);
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
}
