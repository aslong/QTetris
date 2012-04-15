#include "GameStatsView.h"
#include <iostream>

GameStatsView::GameStatsView(TetrisScene *newGameScene, QPointF newOrigin)
{
    gameScene = newGameScene;
    origin = newOrigin;
    scoreKeeper = &TetrisScoreKeeper::getInstance();
    QObject::connect(scoreKeeper, SIGNAL(scoreChanged(int)), this, SLOT(updateScore(int)));
}

void GameStatsView::updateScore(int newScore)
{
    std::cout << "Current score from statsView: " << newScore << "\n";
}
