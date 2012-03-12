#include <QtGui>

class Block : public QGraphicsRectItem
{
    public:
        Block();
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
