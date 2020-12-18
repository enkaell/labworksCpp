#include "MCell.h"
#include "Maze.h"
using namespace std;


int main()
{
    auto c = new Maze(5, 5);
    c->makeConnection(0, 0, 1, 0);
    c->makeConnection(1, 0, 1, 1);
    c->makeConnection(1, 1, 2, 1);
    c->makeConnection(2, 1, 2, 2);
    c->makeConnection(2, 2, 3, 2);
    c->makeConnection(3, 2, 3, 3);
    c->makeConnection(3, 3, 4, 3);
    c->makeConnection(4, 3, 4, 4);
    c->makeConnection(4, 4, 5, 4);
    c->printMaze();
}
