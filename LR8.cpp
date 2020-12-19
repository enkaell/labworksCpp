#include "MCell.h"
#include "Maze.h"
using namespace std;


int main()
{
    auto c = new Maze(5, 5);


    for (int i = 0; i < 5; i++) {
        c->makeConnection(i, i, i + 1, i);
        c->makeConnection(i + 1, i, i + 1, i + 1);
    }


    c->printMaze();
    return 0;
}
