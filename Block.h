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
        virtual void rotate();
        static const int BLOCK_SIZE = 20;
    private:
        QTimeLine *timer;
        QGraphicsItemAnimation *animation;
    protected:
        bool rotateBlock;
        static const QColor FILL_COLOR;
};
#endif
