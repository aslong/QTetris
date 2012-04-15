#include "TetrisGrid.h"
#include <stdlib.h>
#include <iostream>
#include "LineBlock.h"
#include "LBlock.h"

TetrisGrid::TetrisGrid(QGraphicsScene *scene, QPointF newOrigin)
{
    gameScene = scene;
    origin = newOrigin;
    QPen pen;
    pen.setWidth(1);
    pen.setBrush(Qt::blue);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    gameBorder = new GameBorder(origin);
    gameScene->addItem(gameBorder);
    maxHeightBorder = gameScene->addLine(origin.x(), 300, origin.x() + gameBorder->boundingRect().width(), 300);
    blockFactory = new BlockFactory();
    scoreKeeper = &TetrisScoreKeeper::getInstance();
    gridRows = new GridRows(gameBorder->boundingRect().width() / Block::BLOCK_SIZE);
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
    if (!this->blockNotColliding(currentBlock)) 
    {
        currentBlock->moveUp(1);
        if (currentBlock->collidesWithItem(maxHeightBorder, Qt::IntersectsItemShape))
        {
            std::cout << "Game Over!\n";
            std::cout << "Total Score: " << scoreKeeper->getCurrentScore() << "\n";
            timer->setPaused(true);
        }
        else
        {
            int rowPos = gameBorder->boundingRect().height() - currentBlock->mapToScene(currentBlock->boundingRect().bottomLeft()).y();
            int row = (int)(rowPos / Block::BLOCK_SIZE);
            QList<int> rowsToRemove;
            for (int i = 0; i < currentBlock->numberRowsOfBlocks(); i++)
            {
                QList<Block *> rowOfBlocks = currentBlock->getBlocksAtRow(i);
                for (int j = 0; j < currentBlock->numberBlocksAtRow(i); j++)
                {
                    gameScene->addItem(rowOfBlocks[j]);
                    int filledRow = gridRows->addBlock(row + i, rowOfBlocks[j]);
                    if (filledRow)
                    {
                        rowsToRemove.append(row + i);
                    }

                    std::cout << "Row pos " << row + i << "x" << j << " -  row filled: " << filledRow << "\n";
                }
            }

            scoreKeeper->scoreRows(rowsToRemove.count());
            std::cout << "Removed " << rowsToRemove.count() << " rows\n";

            for (int i = rowsToRemove.count() - 1; i >= 0; i--)
            {
                QLinkedList<Block *> * blocksToRemove = gridRows->getRowOfBlocks(rowsToRemove[i]);
                QLinkedList<Block *>::iterator iter;
                for (iter = blocksToRemove->begin(); iter != blocksToRemove->end(); iter++)
                {
                    gameScene->removeItem(*iter);
                }

                for (int shiftIndex = gridRows->numberRowsTracked() - 1; shiftIndex > i; shiftIndex--)
                {
                    QLinkedList<Block *> *blocksToShift = gridRows->getRowOfBlocks(shiftIndex);
                    QLinkedList<Block *>::iterator shiftIter;
                    for (shiftIter = blocksToShift->begin(); shiftIter != blocksToShift->end(); shiftIter++)
                    {
                        (*shiftIter)->moveDown(Block::BLOCK_SIZE / 2);
                    }
                } 

                gridRows->removeRow(rowsToRemove[i]);
            }

            gameScene->removeItem(currentBlock);

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
    currentBlock = blockFactory->nextShape(QPointF(origin.x() + 1, origin.y() + 1));
    gameScene->addItem(currentBlock);
    updateNextBlock();
}

void TetrisGrid::updateNextBlock()
{
    nextBlock = blockFactory->peekNextShape();

    gameScene->addItem(nextBlock);
}

QRectF TetrisGrid::boundingRect() const
{
    return gameBorder->boundingRect();
}

bool TetrisGrid::blockNotColliding(Block *block) 
{
    QList<QGraphicsItem *> items = gameScene->collidingItems(currentBlock);
    QList<QGraphicsItem *>::iterator iter;
    for (iter = items.begin(); iter != items.end(); iter++)
    {
        if ((*iter) != gameBorder && (*iter) != maxHeightBorder && (*iter) != nextBlock) 
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
    if (!blockNotColliding(currentBlock))
    {
        currentBlock->moveRight(HORIZONTAL_BLOCK_GRID_SIZE);
    }
}

void TetrisGrid::rightKeyPressed()
{
    std::cout << "Right Press from grid\n";
    currentBlock->moveRight(HORIZONTAL_BLOCK_GRID_SIZE);
    if (!blockNotColliding(currentBlock))
    {
        currentBlock->moveLeft(HORIZONTAL_BLOCK_GRID_SIZE);
    }
}

void TetrisGrid::downKeyPressed()
{
    std::cout << "Down Press from grid\n";
    currentBlock->moveDown(VERTICAL_BLOCK_GRID_SIZE);
    if (!blockNotColliding(currentBlock))
    {
        currentBlock->moveUp(VERTICAL_BLOCK_GRID_SIZE);
    }

}

void TetrisGrid::rotationKeyPressed()
{
    std::cout << "Rotation Press from grid\n";
    currentBlock->rotate();
    if (!blockNotColliding(currentBlock))
    {
        currentBlock->rotate();
    }
}

void TetrisGrid::dropKeyPressed()
{
    std::cout << "Pressed drop from grid\n";
    while(blockNotColliding(currentBlock))
    {
        currentBlock->moveDown(VERTICAL_BLOCK_GRID_SIZE);
    }
    currentBlock->moveUp(VERTICAL_BLOCK_GRID_SIZE);
}

void TetrisGrid::pauseKeyPressed()
{
    if (timer->state() == QTimeLine::Running)
    {
        std::cout << "Pausing game from grid\n";
        timer->setPaused(true);
        std::cout << "Paused\n";
    }
    else
    {
        std::cout << "Resuming game from grid\n";
        timer->setPaused(false);
        std::cout << "Resumed\n";
    }
}
