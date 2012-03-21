#include <QtGui>

#ifndef BLOCK
#define BLOCK
class Block : public QGraphicsItem
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
    protected:
        static const int BLOCK_SIZE = 10;
};
#endif
