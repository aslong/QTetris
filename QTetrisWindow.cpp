#include "QTetrisWindow.h"


QTetrisWindow::QTetrisWindow()
{
    setWindowTitle(tr("QTetris"));
    graphicsScene = new TetrisScene();
    graphicsScene->setSceneRect(QRectF(0,0,320,480));
    graphicsScene->setFocus(Qt::ActiveWindowFocusReason);

    gameGrid = new TetrisGrid(graphicsScene);
    graphicsScene->setGameGrid(gameGrid);

    graphicsView = new QGraphicsView(graphicsScene);
    graphicsView->setSceneRect(QRectF(0, 0, 320, 480));
    graphicsView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
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
