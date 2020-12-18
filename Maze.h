#pragma once
#include <iostream>
#include <algorithm>
#include "MCell.h"

class Maze {
private:
	MCell* m_field;
	int width;
	int height;
public:
	Maze(int, int);
	~Maze();
	const MCell& cell(int, int) const;
	bool hasConnection(int, int, int, int);
	bool makeConnection(int, int, int, int);
	bool removeConnection(int, int, int, int);
	void printMaze();
};