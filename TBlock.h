#include <QtGui>
#include "Block.h"

#ifndef T_BLOCK
#define T_BLOCK
class TBlock : public Block
{
    public:
        TBlock(QPointF point);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QPainterPath shape() const;
    private:
        static const int BLOCK_WIDTH = (BLOCK_SIZE*3);
        static const int BLOCK_HEIGHT = (BLOCK_SIZE * 2);
        static const QColor FILL_COLOR;
};
#endif
