#include <QtGui>

class Block : public QGraphicsRectItem
{
    public:
        Block(const QPointF startPosition);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        void drop();
};
