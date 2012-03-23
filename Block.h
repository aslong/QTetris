#include <QtGui>

#ifndef BLOCK
#define BLOCK
class Block : public QGraphicsItem
{
    public:
        Block(const QPointF startPosition);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void moveLeft(int spaces);
        void moveRight(int spaces);
        void moveUp(int spaces);
        void moveDown(int spaces);
        void rotate();
    private:
        QTimeLine *timer;
        QGraphicsItemAnimation *animation;
    protected:
        static const int BLOCK_SIZE = 10;
        bool rotateBlock;
};
#endif
