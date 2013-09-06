#include "TMX_Terrain.h"

std::string tmx::Terrain::getName() {
	return mName;
}

int tmx::Terrain::getTile() {
	return mTile;
}

void tmx::Terrain::setName(std::string name) {
	mName = name;
}

void tmx::Terrain::setTile(int tile) {
	mTile = tile;
}