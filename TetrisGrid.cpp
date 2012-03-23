#include "TetrisGrid.h"
#include <stdlib.h>
#include <iostream>
#include "LineBlock.h"
#include "LBlock.h"

TetrisGrid::TetrisGrid(QGraphicsScene *scene)
{
    gameScene = scene;
    QPen pen;
    pen.setWidth(1);
    pen.setBrush(Qt::blue);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    gameBorder = new GameBorder();
    gameScene->addItem(gameBorder);
    maxHeightBorder = gameScene->addLine(0, 300, gameBorder->boundingRect().width(), 300);
    blockFactory = new BlockFactory();
}

void TetrisGrid::play()
{
    dropNewBlock();

    setupGameLoop();
}

void TetrisGrid::setupGameLoop()
{
    timer = new QTimeLine();
    timer->setFrameRange(0, 60);
    timer->setCurveShape(QTimeLine::LinearCurve);

    QObject::connect(timer, SIGNAL(finished()), this, SLOT(restartTimer()));
    QObject::connect(timer, SIGNAL(frameChanged(int)), this, SLOT(gameLoop(int)));
    timer->start();
}

void TetrisGrid::gameLoop(int step)
{
    currentBlock->moveDown(1);
    if (this->blockWithinGameBorder(currentBlock)) 
    {
        std::cout << "Contained in border\n";
    }
    else
    {
        currentBlock->moveUp(1);
        if (currentBlock->collidesWithItem(maxHeightBorder, Qt::IntersectsItemShape))
        {
            std::cout << "Game Over!\n";
            timer->setPaused(true);
        }
        else
        {
            std::cout << "Replacing currentBlock. Not within gameBorder\n";
            dropNewBlock();
        }
    }
}

void TetrisGrid::restartTimer()
{
    timer->start();
}

void TetrisGrid::dropNewBlock()
{
    //currentBlock = new LineBlock(QPointF((rand() % 150), 6));
    //currentBlock = new LBlock(QPointF((rand() % 150), 6));
    int horizontalSpaces = boundingRect().width() / HORIZONTAL_BLOCK_GRID_SIZE;
    int multiplier = rand() % horizontalSpaces;
    currentBlock = blockFactory->nextShape(QPointF(1,1));
    gameScene->addItem(currentBlock);
}

QRectF TetrisGrid::boundingRect() const
{
    return gameBorder->boundingRect();
}

bool TetrisGrid::blockWithinGameBorder(Block *block) 
{
    QList<QGraphicsItem *> items = gameScene->collidingItems(currentBlock);
    QList<QGraphicsItem *>::iterator iter;
    for (iter = items.begin(); iter != items.end(); iter++)
    {
        if ((*iter) != gameBorder && (*iter) != maxHeightBorder) 
        {
            return false;
        }
    }

    return currentBlock->collidesWithItem(gameBorder, Qt::ContainsItemShape);
}

void TetrisGrid::leftKeyPressed()
{
    std::cout << "Left Press from grid\n";
    currentBlock->moveLeft(HORIZONTAL_BLOCK_GRID_SIZE);
    if (!blockWithinGameBorder(currentBlock))
    {
        currentBlock->moveRight(HORIZONTAL_BLOCK_GRID_SIZE);
    }
}

void TetrisGrid::rightKeyPressed()
{
    std::cout << "Right Press from grid\n";
    currentBlock->moveRight(HORIZONTAL_BLOCK_GRID_SIZE);
    if (!blockWithinGameBorder(currentBlock))
    {
        currentBlock->moveLeft(HORIZONTAL_BLOCK_GRID_SIZE);
    }
}

void TetrisGrid::downKeyPressed()
{
    std::cout << "Down Press from grid\n";
    currentBlock->moveDown(VERTICAL_BLOCK_GRID_SIZE);
    if (!blockWithinGameBorder(currentBlock))
    {
        currentBlock->moveUp(VERTICAL_BLOCK_GRID_SIZE);
    }

}

void TetrisGrid::rotationKeyPressed()
{
    std::cout << "Rotation Press from grid\n";
    currentBlock->rotate();
    if (!blockWithinGameBorder(currentBlock))
    {
        currentBlock->rotate();
    }
}
