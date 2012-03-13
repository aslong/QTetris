#include "TetrisGrid.h"
#include "Block.h"
#include <stdlib.h>
#include <iostream>

TetrisGrid::TetrisGrid(QGraphicsScene *scene)
{
    gameScene = scene;
    QPen pen;
    pen.setWidth(3);
    pen.setBrush(Qt::blue);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    gameBorder = gameScene->addRect(QRectF(0, 0, 320, 480), pen);
}

void TetrisGrid::play()
{
    currentBlock = new Block(QPointF(5,6));
    gameScene->addItem(currentBlock);
    currentBlock->drop();

    timer = new QTimeLine();
    timer->setFrameRange(0, 60);
    timer->setCurveShape(QTimeLine::LinearCurve);

    dropBlockTimer = new QTimeLine(5000);
    dropBlockTimer->setFrameRange(0, 100);
    dropBlockTimer->setCurveShape(QTimeLine::LinearCurve);
        
    QObject::connect(timer, SIGNAL(finished()), this, SLOT(restartTimer()));
    QObject::connect(timer, SIGNAL(frameChanged(int)), this, SLOT(gameLoop(int)));
    QObject::connect(dropBlockTimer, SIGNAL(finished()), this, SLOT(dropBlock()));
    timer->start();
    dropBlockTimer->start();
}
void TetrisGrid::dropBlock()
{
    currentBlock = new Block(QPointF((rand() % 150), 6));
    gameScene->addItem(currentBlock);
    currentBlock->drop();
    dropBlockTimer->start();
}

void TetrisGrid::gameLoop(int step)
{
}

void TetrisGrid::restartTimer()
{
    timer->start();
}

void TetrisGrid::leftKeyPressed()
{
    std::cout << "Left Press from grid\n";
    currentBlock->moveLeft(1);
}

void TetrisGrid::rightKeyPressed()
{
    std::cout << "Right Press from grid\n";
    currentBlock->moveRight(1);
}
