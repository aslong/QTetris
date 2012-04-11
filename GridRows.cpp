#include "GridRows.h"
#include <iostream>

GridRows::GridRows(int fullRowCapacity)
{
    rows = new QLinkedList<QLinkedList<Block *> *>();
    fullRowCount = fullRowCapacity;
}

int GridRows::numberRowsTracked()
{
    return rows->count();
}

bool GridRows::addBlock(int row, Block *blockToAdd)
{
    if (rows->count() <= row)
    {
        for (int i = rows->count(); i <= row; i++)
        {
            rows->append(new QLinkedList<Block *>());
        }
    }

    QLinkedList<Block *> *rowToAppend = getRowOfBlocks(row);
    (*rowToAppend) << blockToAdd;
    
    std::cout << "row count: " << rowToAppend->count() << "\n";
    return rowToAppend->count() == fullRowCount;
}

QLinkedList<Block *> *GridRows::getRowOfBlocks(int row)
{
    QLinkedList<QLinkedList<Block *> *>::iterator i = rows->begin();
    int currRow = 0;

    for (i = rows->begin(); currRow < row && i != rows->end(); i++)
    {
        currRow++;
    }

    return (*i);
}

void GridRows::removeRow(int row)
{
    QLinkedList<QLinkedList<Block *> *>::iterator i = rows->begin();
    int currRow = 0;

    for (i = rows->begin(); currRow < row && i != rows->end(); i++)
    {
        currRow++;
    }

    rows->erase(i);
}

GridRows::~GridRows()
{
    delete [] rows;
}
