#include "MCell.h"

MCell::MCell() {
	m_right = false;
	m_down = false;

}

bool MCell::right() {
	return m_right;
}

bool MCell::down() {
	return m_down;
}
