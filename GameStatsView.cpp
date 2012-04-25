#include "GameStatsView.h"

GameStatsView::GameStatsView(TetrisScene *newGameScene, QPointF newOrigin)
{
    gameScene = newGameScene;
    origin = newOrigin;
    scoreKeeper = &TetrisScoreKeeper::getInstance();
    blockFactory = &BlockFactory::getInstance();
    QObject::connect(scoreKeeper, SIGNAL(scoreChanged(int)), this, SLOT(updateScore(int)));
    QObject::connect(blockFactory, SIGNAL(nextBlockChanged(Block *)), this, SLOT(updateNextBlock(Block *)));
    scoreText = new QGraphicsSimpleTextItem();
    scoreText->setPos(origin.x() + 10, origin.y() + 10);
    scoreText->setText("Score\n0");
    gameScene->addItem(scoreText);

    QGraphicsSimpleTextItem *nextBlockText = new QGraphicsSimpleTextItem();
    nextBlockText->setPos(origin.x() + 10, origin.y() + 65);
    nextBlockText->setText("Next Block");
    gameScene->addItem(nextBlockText);

    nextBlock = NULL;
}

void GameStatsView::updateScore(int newScore)
{
    QString result;
    QTextStream(&result) << "Score\n" << newScore;
    scoreText->setText(result);
    scoreText->update();
}

void GameStatsView::updateNextBlock(Block *newNextBlock)
{
    if (nextBlock)
    {
        gameScene->removeItem(nextBlock);
    }

    newNextBlock->setPos(origin.x() + 5, origin.y() + 45);
    gameScene->addItem(newNextBlock);
    nextBlock = newNextBlock;
}
