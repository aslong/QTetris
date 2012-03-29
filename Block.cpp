#include "Block.h"

const QColor Block::FILL_COLOR = Qt::red;

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
    painter->fillRect(x() + 1,y() + 1, BLOCK_SIZE + 2, BLOCK_SIZE + 2, FILL_COLOR);
    
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
