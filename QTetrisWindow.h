#include <QtGui>
#include "TetrisScene.h"
#include "TetrisGrid.h"

class QTetrisWindow : public QMainWindow
{
    Q_OBJECT

    public :
        QTetrisWindow();
        void start();
        static int const HORIZONTAL_SPACES = 10;
        static int const VERTICAL_SPACES = 20;
    private slots:
        void quit();
    private:
        TetrisScene *graphicsScene;
        QGraphicsView *graphicsView;
        TetrisGrid *gameGrid;
};
