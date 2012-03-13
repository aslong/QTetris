#include <QtGui>
#include "Block.h"

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
    public slots:
        void dropBlock();
        void gameLoop(int step);
        void restartTimer();
    private:
        QGraphicsScene *gameScene;
        QGraphicsRectItem *gameBorder;
        QTimeLine *timer;
        QTimeLine *dropBlockTimer;
        Block *currentBlock;
};
#endif
