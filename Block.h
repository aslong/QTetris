#include <QtGui>

#ifndef BLOCK
#define BLOCK
class Block : public QGraphicsItem
{
    public:
        Block(const QPointF startPosition);
        Block(const QPointF startPosition, QColor color);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void moveLeft(int spaces);
        void moveRight(int spaces);
        void moveUp(int spaces);
        void moveDown(int spaces);
        virtual void rotate();
        virtual int numberRowsOfBlocks();
        virtual int numberBlocksAtRow(int row);
        virtual QList<Block *> getBlocksAtRow(int row);
        static const int BLOCK_SIZE = 20;
    private:
        QTimeLine *timer;
        QGraphicsItemAnimation *animation;
        QColor fillColor;
        void init(const QPointF startPosition, QColor color);
    protected:
        bool rotateBlock;
        int angle;
        static const QColor FILL_COLOR; // Default value if not specified
};
#endif
