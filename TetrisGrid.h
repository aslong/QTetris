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
        bool blockWithinGameBorder(Block *block);
        void leftKeyPressed();
        void rightKeyPressed();
    public slots:
        void dropBlock();
        void gameLoop(int step);
        void restartTimer();
    private:
        QGraphicsScene *gameScene;
        GameBorder *gameBorder;
        QTimeLine *timer;
        QTimeLine *dropBlockTimer;
        Block *currentBlock;
};
#endif
