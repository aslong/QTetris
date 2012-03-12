#include "QTetrisWindow.h"
#include "Block.h"


QTetrisWindow::QTetrisWindow()
{
    setWindowTitle(tr("QTetris"));
    graphicsScene = new QGraphicsScene();

    gameGrid = new TetrisGrid(graphicsScene);
    graphicsScene->addItem(gameGrid);

    graphicsView = new QGraphicsView(graphicsScene);
    graphicsView->setSceneRect(QRect(0, 0, 400, 500));
    setCentralWidget(graphicsView);
    graphicsView->show();
}

void QTetrisWindow::start()
{
    gameGrid->play();
}

void QTetrisWindow::quit()
{
    qApp->quit();
}
