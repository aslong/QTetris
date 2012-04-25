#include <QtGui>
#include "Block.h"

#ifndef BLOCK_FACTORY
#define BLOCK_FACTORY
class BlockFactory : public QObject
{
    Q_OBJECT
    
    public:
        static BlockFactory& getInstance()
        {
            static BlockFactory instance;

            return instance;
        }
        Block * nextShape();
        Block * peekNextShape();
        ~BlockFactory();
    signals:
        void nextBlockChanged(Block *nextBlock);
    private:
        enum BlockTypes { LINE, LSHAPED, SQUARESHAPED, JSHAPED, TSHAPED, SSHAPED, ZSHAPED };
        Block * generateNextShape();
        QQueue<int> *previousShapes;
        Block *nextBlock;
        BlockFactory();
        BlockFactory(BlockFactory const&);
        void operator=(BlockFactory const&);
};
#endif
