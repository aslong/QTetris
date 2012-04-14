#include "TetrisScene.h"
#include <iostream>

void TetrisScene::setGameGrid(TetrisGrid *gameGridArg)
{
    gameGrid = gameGridArg;
}

void TetrisScene::keyPressEvent(QKeyEvent *keyEvent)
{
//    std::cout << "Pressing key " << keyEvent->key() << "\n";

    switch(keyEvent->key())
    {
        case Qt::Key_Left:
            gameGrid->leftKeyPressed();
            break;
        case Qt::Key_Right:
            gameGrid->rightKeyPressed();
            break;
        case Qt::Key_Down:
            gameGrid->downKeyPressed();
            break;
        case Qt::Key_R:
            gameGrid->rotationKeyPressed();
            break;
        case Qt::Key_D:
            gameGrid->dropKeyPressed();
            break;
        case Qt::Key_P:
            gameGrid->pauseKeyPressed();
            break;
    }
}
