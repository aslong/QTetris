#include <QtGui>
#include "Block.h"

#ifndef SQUARE_BLOCK
#define SQUARE_BLOCK
class SquareBlock : public Block
{
    public:
        SquareBlock(QPointF point);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        int numberRowsOfBlocks();
        int numberBlocksAtRow(int row);
    private:
        static const int BLOCK_WIDTH = (BLOCK_SIZE * 2);
        static const int BLOCK_HEIGHT = (BLOCK_SIZE * 2);
        static const QColor FILL_COLOR;
};
#endif
