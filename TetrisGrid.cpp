#include "TetrisGrid.h"
#include "Block.h"
#include <stdlib.h>

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
    Block *block = new Block(QPointF(5,6));
    Block *block2 = new Block(QPointF(18,9));
    gameScene->addItem(block);
    gameScene->addItem(block2);
    block->drop();
    block2->drop();

    timer = new QTimeLine();
    timer->setFrameRange(0, 60);
    timer->setCurveShape(QTimeLine::LinearCurve);
        
    QObject::connect(timer, SIGNAL(finished()), this, SLOT(restartTimer()));
    QObject::connect(timer, SIGNAL(frameChanged(int)), this, SLOT(gameLoop(int)));
    timer->setCurveShape(QTimeLine::LinearCurve);
    timer->start();
}

void TetrisGrid::gameLoop(int step)
{
    if (step % 60) {
        Block *blockTemp = new Block(QPointF((rand() % 150), 6));
        gameScene->addItem(blockTemp);
        blockTemp->drop();
    }
}

void TetrisGrid::restartTimer()
{
    timer->start();
}
