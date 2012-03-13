#include <QtGui>

class TetrisGrid : public QObject
{
    Q_OBJECT

    public:
        TetrisGrid(QGraphicsScene *scene);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); 
        void play();
    public slots:
        void gameLoop(int step);
        void restartTimer();
    private:
        QGraphicsScene *gameScene;
        QGraphicsRectItem *gameBorder;
        QTimeLine *timer;
};
