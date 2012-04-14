#include <QtGui>
#include "Block.h"

#ifndef BLOCK_FACTORY
#define BLOCK_FACTORY
class BlockFactory : public QObject
{
    Q_OBJECT
    
    public:
        BlockFactory();
        Block * nextShape(QPointF point);
        Block * peekNextShape();
        ~BlockFactory();
    private:
        enum BlockTypes { LINE, LSHAPED, SQUARESHAPED, JSHAPED, TSHAPED, SSHAPED, ZSHAPED };
        Block * generateNextShape(QPointF point);
        QQueue<int> *previousShapes;
        Block *nextBlock;
};
#endif
