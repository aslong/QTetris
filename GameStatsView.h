#include <QObject>
#include <QtGui>
#include "TetrisScene.h"
#include "TetrisScoreKeeper.h"

#ifndef GAME_STATS_VIEW
#define GAME_STATS_VIEW
class GameStatsView : public QObject
{
    Q_OBJECT

    public:
        GameStatsView(TetrisScene *newGameScene, QPointF newOrigin);
    public slots:
        void updateScore(int newScore);
    private:
        TetrisScene *gameScene;
        TetrisScoreKeeper *scoreKeeper;
        QPointF origin;
        QGraphicsSimpleTextItem *scoreText;
};
#endif
