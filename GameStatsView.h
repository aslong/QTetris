#include <QObject>
#include <QtGui>
#include "TetrisScene.h"
#include "TetrisScoreKeeper.h"
#include "BlockFactory.h"

#ifndef GAME_STATS_VIEW
#define GAME_STATS_VIEW
class GameStatsView : public QObject
{
    Q_OBJECT

    public:
        GameStatsView(TetrisScene *newGameScene, QPointF newOrigin);
    public slots:
        void updateScore(int newScore);
        void updateNextBlock(Block *nextBlock);
    private:
        TetrisScene *gameScene;
        TetrisScoreKeeper *scoreKeeper;
        BlockFactory *blockFactory;
        QPointF origin;
        QGraphicsSimpleTextItem *scoreText;
        Block *nextBlock;
};
#endif
