#pragma once

class MCell {
private:
	bool m_down;
	bool m_right;
	MCell();
public:
	bool down();
	bool right();
	friend class Maze;
};