#include "Block.h"

Block::Block(const QPointF startPosition)
{
    setPos(startPosition);
}

QRectF Block::boundingRect() const
{
    return QRectF(x(), y(), 10, 10);
}

void Block::paint(QPainter *painter, 
                const QStyleOptionGraphicsItem *option,
                QWidget *widget)
{
    painter->drawRect(x(),y(), 10, 10);
}

void Block::drop()
{
    QTimeLine *timer = new QTimeLine(15000);
    timer->setFrameRange(0, 100);
    timer->setCurveShape(QTimeLine::LinearCurve);

    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    animation->setItem(this);
    animation->setTimeLine(timer);

     for (int i = 0; i < 220; ++i)
      animation->setPosAt(i/480.0, QPointF(x(), y() + i));

    timer->start();
}
