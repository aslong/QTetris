#include "TetrisGrid.h"

TetrisGrid::TetrisGrid(QGraphicsScene *scene)
{
    gameScene = scene;
}

QRectF TetrisGrid::boundingRect() const
{
    return QRectF(0, 0, 320, 480);
}

void TetrisGrid::play()
{
    QTimeLine *timer = new QTimeLine(5000);
    timer->setFrameRange(0, 100);
    timer->setCurveShape(QTimeLine::LinearCurve);

    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;
    QGraphicsRectItem *rect = gameScene->addRect(QRectF(0, 0, 10, 10));
    animation->setItem(rect);
    animation->setTimeLine(timer);

     for (int i = 0; i < 480; ++i)
      animation->setPosAt(i/480.0, QPointF(0,i));

    timer->start();
}

void TetrisGrid::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                        QWidget *widget)
{
    QPen pen;
    pen.setWidth(3);
    pen.setBrush(Qt::blue);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    painter->setPen(pen);
    painter->drawRect(0, 0, 320, 480);
}
