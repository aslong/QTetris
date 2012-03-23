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
    private:
        enum BlockTypes { LINE, LSHAPED, JSHAPED, TSHAPED };
};
#endif
