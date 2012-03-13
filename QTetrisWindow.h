#include <QtGui>
#include "TetrisScene.h"
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
        TetrisScene *graphicsScene;
        QGraphicsView *graphicsView;
        TetrisGrid *gameGrid;
};
