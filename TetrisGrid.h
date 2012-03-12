#include <QtGui>

class TetrisGrid : public QGraphicsItem
{
    public:
        TetrisGrid(QGraphicsScene *scene);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); 
        void play();
    private:
        QGraphicsScene *gameScene;
};
