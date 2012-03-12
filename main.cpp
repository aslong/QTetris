#include <QtGui>
#include "QTetrisWindow.h"

int main (int argv, char **args) 
{
   QApplication app(argv, args); 
   QTetrisWindow *gameWindow = new QTetrisWindow();
   gameWindow->show();
   gameWindow->start();

   return app.exec();
}
