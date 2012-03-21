#include <QtGui>

#ifndef GAME_BORDER
#define GAME_BORDER
class GameBorder : public QGraphicsItem
{
    public:
        QRectF boundingRect() const;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif
