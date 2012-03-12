#include <QtGui>
#include "TetrisGrid.h"

class QTetrisWindow : public QMainWindow
{
    Q_OBJECT

    public :
        QTetrisWindow();
        void start();
    private slots:
        void quit();
    private:
        QGraphicsScene *graphicsScene;
        QGraphicsView *graphicsView;
        TetrisGrid *gameGrid;
};
