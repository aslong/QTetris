#include <QtGui>
#include "Block.h"

#ifndef S_BLOCK
#define S_BLOCK
class SBlock : public Block
{
    public:
        SBlock(QPointF point);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QPainterPath shape() const;
        int numberRowsOfBlocks();
        int numberBlocksAtRow(int row);
        QList<Block *> getBlocksAtRow(int row);
    private:
        static const int BLOCK_WIDTH = (BLOCK_SIZE*3);
        static const int BLOCK_HEIGHT = (BLOCK_SIZE * 2);
        static const QColor FILL_COLOR;
};
#endif
