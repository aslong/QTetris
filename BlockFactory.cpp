#include "BlockFactory.h"
#include <stdlib.h>
#include "Block.h"
#include "LineBlock.h"
#include "LBlock.h"
#include "JBlock.h"

BlockFactory::BlockFactory()
{
}

Block * BlockFactory::nextShape(QPointF point)
{
    int random = rand() % 3; 

    switch (random)
    {
        case LINE:
           return new LineBlock(point); 
        case LSHAPED:
           return new LBlock(point);
        case JSHAPED:
           return new JBlock(point);
        default:
           return new Block(point);
    }
}
