#include "Maze.h"
using namespace std;

Maze::Maze(int n, int m) {
	m_field = new MCell[n * m];
	height = m;
	width = n;
}

Maze::~Maze() {
	delete m_field;
}

const MCell& Maze::cell(int i, int j) const {
	return m_field[i * width + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2) {
	auto c = cell(min(i1, i2), min(j1, j2));
	if (i1 == i2 && abs(j1 - j2) < 2)
		return c.down();
	else if (j1 == j2 && abs(i1 - i2) < 2)
		return c.right();
	else
		return false;
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2) {
	if (i1 == i2 && abs(j1 - j2) < 2) {
		m_field[i1 * width + min(j1, j2)].m_down = true;
		return m_field[i1 * width + min(j1, j2)].down();
	}
	else if (j1 == j2 && abs(i1 - i2) < 2) {
		m_field[min(i1, i2) * width + j1].m_right = true;
		return m_field[min(i1, i2) * width + j1].right();
	}
	else
		return false;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2) {
	if (i1 == i2 && abs(j1 - j2) < 2){
		m_field[i1 * width + min(j1, j2)].m_down = false;
		return m_field[i1 * width + min(j1, j2)].down();
	}
	else if (j1 == j2 && abs(i1 - i2) < 2) {
		m_field[min(i1, i2) * width + j1].m_right = false;
		return m_field[min(i1, i2) * width + j1].right();
	}
	else
		return false;
}

void Maze::printMaze() {
	auto c = new char[width * height];

	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++) {
			if (this->hasConnection(i, j, i + 1, j)) {
				if (i == 0 && j == 0)
					c[i * width + j] = '0';
				c[(i + 1) * width + j] = char(191);
			}
			else if (this->hasConnection(i, j, i, j + 1))
				c[i * width + (j + 1)] = char(192);
			else
				c[i * width + j] = '0';
		}

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			cout << c[i * width + j];
		}
		cout << endl;
	}

}

