#include "SquareBlock.h"

SquareBlock::SquareBlock(QPointF point)
    :Block(point)
{
}

QRectF SquareBlock::boundingRect() const
{
    return QRectF(x(), y(), BLOCK_WIDTH, BLOCK_HEIGHT);
}

void SquareBlock::paint(QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget)
{
    painter->drawRect(x(), y(), BLOCK_SIZE, BLOCK_SIZE); 
    painter->drawRect(x(), y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
    painter->drawRect(x() + BLOCK_SIZE, y() + BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
    painter->drawRect(x() + BLOCK_SIZE, y(), BLOCK_SIZE, BLOCK_SIZE);
}
