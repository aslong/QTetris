#include <QtGui>

#ifndef GAME_BORDER
#define GAME_BORDER
class GameBorder : public QGraphicsItem
{
    public:
        GameBorder(QPointF newPosition);
        void setPosition(QPointF newPosition);
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    private:
        QPointF position;
};
#endif
