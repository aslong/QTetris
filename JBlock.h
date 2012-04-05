#include <QtGui>
#include "Block.h"

#ifndef J_BLOCK
#define J_BLOCK
class JBlock : public Block
{
    public:
        JBlock(QPointF point);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QPainterPath shape() const;
    private:
        static const int BLOCK_WIDTH = (BLOCK_SIZE*3);
        static const int BLOCK_HEIGHT = (BLOCK_SIZE * 2);
        static const QColor FILL_COLOR;
};
#endif