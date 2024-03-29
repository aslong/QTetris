#include "BlockFactory.h"
#include <stdlib.h>
#include <time.h>
#include "Block.h"
#include "LineBlock.h"
#include "LBlock.h"
#include "JBlock.h"
#include "TBlock.h"
#include "SquareBlock.h"
#include "SBlock.h"
#include "ZBlock.h"

BlockFactory::BlockFactory()
{
    previousShapes = new QQueue<int>(); 
    nextBlock = NULL;
}

Block * BlockFactory::nextShape()
{
    Block *blockToReturn;
    if (!nextBlock)
    {
         nextBlock = generateNextShape();
    }

    blockToReturn = nextBlock;
    nextBlock = generateNextShape();
    emit nextBlockChanged(nextBlock);

    return blockToReturn;
}

Block * BlockFactory::generateNextShape()
{
    srand(time(NULL));
    int random = rand() % 7; 

    if (previousShapes->count() > 1)
    {
        int beforePreviousNumber = previousShapes->dequeue();
        int previousNumber = previousShapes->dequeue();

        if (previousNumber == beforePreviousNumber)
        {
            while (random == previousNumber)
            {
                random = rand() % 7;
            }
        }

        previousShapes->enqueue(previousNumber);
    }

    previousShapes->enqueue(random);

    // Default to 0,0. Code manipulating block will set
    // position to what is needed.
    QPointF point = QPointF(0, 0);

    switch (random)
    {
        case LINE:
           return new LineBlock(point); 
        case LSHAPED:
           return new LBlock(point);
        case SQUARESHAPED:
           return new SquareBlock(point);
        case JSHAPED:
           return new JBlock(point);
        case TSHAPED:
           return new TBlock(point);
        case SSHAPED:
           return new SBlock(point);
        case ZSHAPED:
           return new ZBlock(point);
        default:
           return new Block(point);
    }
}

Block * BlockFactory::peekNextShape()
{
    return nextBlock;
}

BlockFactory::~BlockFactory()
{
    delete previousShapes;
    if (nextBlock)
    {
        delete nextBlock;
    }
}
