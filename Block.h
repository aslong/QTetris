#include <QtGui>

#ifndef BLOCK
#define BLOCK
class Block : public QGraphicsRectItem
{
    public:
        Block(const QPointF startPosition);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void drop();
        void moveLeft(int spaces);
        void moveRight(int spaces);
    private:
        QTimeLine *timer;
        QGraphicsItemAnimation *animation;
};
#endif
