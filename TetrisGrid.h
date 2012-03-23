#include <QtGui>
#include "Block.h"
#include "GameBorder.h"
#include "BlockFactory.h"

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
        BlockFactory *blockFactory;
        Block *currentBlock;
        bool blockWithinGameBorder(Block *block);
        void dropNewBlock();
        void setupGameLoop();
        static const int HORIZONTAL_BLOCK_GRID_SIZE = (Block::BLOCK_SIZE / 2);
        static const int VERTICAL_BLOCK_GRID_SIZE = (Block::BLOCK_SIZE / 2);
};
#endif
