#include "TetrisScene.h"
#include <iostream>

void TetrisScene::setGameGrid(TetrisGrid *gameGridArg)
{
    gameGrid = gameGridArg;
}

void TetrisScene::keyPressEvent(QKeyEvent *keyEvent)
{
    std::cout << "Pressing key " << keyEvent->key() << "\n";

    if (keyEvent->key() == Qt::Key_Left)
    {
        gameGrid->leftKeyPressed();
    }

    if (keyEvent->key() == Qt::Key_Right)
    {
        gameGrid->rightKeyPressed();
    }

    if (keyEvent->key() == Qt::Key_Down)
    {
        gameGrid->downKeyPressed();
    }

}
