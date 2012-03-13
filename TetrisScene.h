#include <QtGui>
#include "TetrisGrid.h"

#ifndef TETRIS_SCENE
#define TETRIS_SCENE
class TetrisScene : public QGraphicsScene
{
    public:
        void keyPressEvent(QKeyEvent *keyEvent);
        void setGameGrid(TetrisGrid *gameGridArg);
    private:
        TetrisGrid *gameGrid;
}; 
#endif
