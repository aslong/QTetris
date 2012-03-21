#include "Block.h"

Block::Block(const QPointF startPosition)
{
    setPos(startPosition);
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

void Block::drop()
{
    timer = new QTimeLine(15000);
    timer->setFrameRange(0, 1);
    timer->setCurveShape(QTimeLine::LinearCurve);

    animation = new QGraphicsItemAnimation;
    animation->setItem(this);
    animation->setTimeLine(timer);

    animation->setPosAt(1, QPointF(x(), 200));

    //timer->start();
}

void Block::moveRight(int spaces)
{

    timer->setPaused(true);
    setX(x() + spaces);
    drop();
}

void Block::moveLeft(int spaces)
{
    timer->setPaused(true);
    setX(x() - spaces);
    drop();
}

