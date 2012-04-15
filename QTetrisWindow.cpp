#include "QTetrisWindow.h"
#include "Block.h"

QTetrisWindow::QTetrisWindow()
{
    setWindowTitle(tr("QTetris"));
    graphicsScene = new TetrisScene();
    graphicsScene->setSceneRect(QRectF(0,0,305, 480));
    graphicsScene->setFocus(Qt::ActiveWindowFocusReason);

    gameGrid = new TetrisGrid(graphicsScene, QPointF(200, 0));
    graphicsScene->setGameGrid(gameGrid);

    graphicsView = new QGraphicsView(graphicsScene);
    graphicsView->setSceneRect(QRectF(0, 0, 505, 480));
    graphicsView->setAlignment(Qt::AlignRight | Qt::AlignTop);
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
