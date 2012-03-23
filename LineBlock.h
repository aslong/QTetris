#include <QtGui>
#include "Block.h"

#ifndef LINE_BLOCK
#define LINE_BLOCK
class LineBlock : public Block
{
    public:
        LineBlock(QPointF point);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    private:
        static const int BLOCK_WIDTH = (BLOCK_SIZE * 4);
        static const int BLOCK_HEIGHT = BLOCK_SIZE;  
};
#endif
