#include "BlockFactory.h"
#include <stdlib.h>
#include "Block.h"
#include "LineBlock.h"
#include "LBlock.h"
#include "JBlock.h"
#include "TBlock.h"
#include "SquareBlock.h"
#include "SBlock.h"

BlockFactory::BlockFactory()
{
}

Block * BlockFactory::nextShape(QPointF point)
{
    int random = rand() % 6; 

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
        case SQUARESHAPED:
           return new SquareBlock(point);
        case SSHAPED:
           return new SBlock(point);
        default:
           return new Block(point);
    }
}
