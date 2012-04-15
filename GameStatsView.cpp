#include "GameStatsView.h"
#include <iostream>

GameStatsView::GameStatsView(TetrisScene *newGameScene, QPointF newOrigin)
{
    gameScene = newGameScene;
    origin = newOrigin;
    scoreKeeper = &TetrisScoreKeeper::getInstance();
    QObject::connect(scoreKeeper, SIGNAL(scoreChanged(int)), this, SLOT(updateScore(int)));
    scoreText = new QGraphicsSimpleTextItem();
    scoreText->setPos(origin.x() + 10, origin.y() + 10);
    scoreText->setText("Score: 0");
    gameScene->addItem(scoreText);
}

void GameStatsView::updateScore(int newScore)
{
    QString result;
    QTextStream(&result) << "Score: " << newScore;
    scoreText->setText(result);
    scoreText->update();
}
