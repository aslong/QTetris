#include <QtGui>
#include "Block.h"
#include "GameBorder.h"

#ifndef TETRIS_GRID
#define TETRIS_GRID
class TetrisGrid : public QObject
{
    Q_OBJECT

    public:
        TetrisGrid(QGraphicsScene *scene);
        QRectF boundingRect() const;
        void play();
        void leftKeyPressed();
        void rightKeyPressed();
        void downKeyPressed();
        void rotationKeyPressed();
    public slots:
        void gameLoop(int step);
        void restartTimer();
    private:
        QGraphicsScene *gameScene;
        GameBorder *gameBorder;
        QGraphicsLineItem *maxHeightBorder;
        QTimeLine *timer;
        QTimeLine *dropBlockTimer;
        Block *currentBlock;
        bool blockWithinGameBorder(Block *block);
        void dropNewBlock();
        void setupGameLoop();
};
#endif
