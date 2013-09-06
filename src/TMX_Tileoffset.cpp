#include "pugixml.hpp"

#include "TMX_Tileoffset.h"

void tmx::Tileoffset::init(pugi::xml_node tileoffsetNode) {
	setX(tileoffsetNode.attribute("x").as_int());
	setY(tileoffsetNode.attribute("y").as_int());
}

int tmx::Tileoffset::getX() {
	return mX;
}

int tmx::Tileoffset::getY() {
	return mY;
}

void tmx::Tileoffset::setX(int x) {
	mX = x;
}

void tmx::Tileoffset::setY(int y) {
	mY = y;
}