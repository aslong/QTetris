#include "BlockFactory.h"
#include <stdlib.h>
#include "Block.h"
#include "LineBlock.h"
#include "LBlock.h"
#include "JBlock.h"
#include "TBlock.h"

BlockFactory::BlockFactory()
{
}

Block * BlockFactory::nextShape(QPointF point)
{
//    return new JBlock(point);
    int random = rand() % 4; 

    switch (random)
    {
        case LINE:
           return new LineBlock(point); 
        case LSHAPED:
           return new LBlock(point);
        case JSHAPED:
           return new JBlock(point);
        case TSHAPED:
           return new TBlock(point);
        default:
           return new Block(point);
    }
}
