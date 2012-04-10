#include <QtGui>
#include "Block.h"

#ifndef Z_BLOCK
#define Z_BLOCK
class ZBlock : public Block
{
    public:
        ZBlock(QPointF point);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QPainterPath shape() const;
    private:
        static const int BLOCK_WIDTH = (BLOCK_SIZE*3);
        static const int BLOCK_HEIGHT = (BLOCK_SIZE * 2);
        static const QColor FILL_COLOR;
};
#endif
