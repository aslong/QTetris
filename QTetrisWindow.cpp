#include "QTetrisWindow.h"


QTetrisWindow::QTetrisWindow()
{
    setWindowTitle(tr("QTetris"));
    graphicsScene = new TetrisScene();
    graphicsScene->setFocus(Qt::ActiveWindowFocusReason);

    gameGrid = new TetrisGrid(graphicsScene);
    graphicsScene->setGameGrid(gameGrid);

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
