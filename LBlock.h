#include <QtGui>
#include "Block.h"

#ifndef L_BLOCK
#define L_BLOCK
class LBlock : public Block
{
    public:
        LBlock(QPointF point);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QPainterPath shape() const;
    private:
        static const int BLOCK_WIDTH = (BLOCK_SIZE*3);
        static const int BLOCK_HEIGHT = (BLOCK_SIZE * 2);
};
#endif
