#include <iostream>

#include "TMX_Tile.h"

void tmx::Tile::init(pugi::xml_node tileset) {
	for(pugi::xml_node tile = tileset.child("tile"); tile; tile = tile.next_sibling("tile")) {
			tmx::Tile tempTile;
			tempTile.setID(tile.attribute("id").as_uint());
			tempTile.setTerrain(tile.attribute("terrain").as_string());
			std::cout << "\t\t Tile #" << tempTile.getID() << " acquired.\n";
			// mTile.push_back(tempTile);
		}
}

unsigned int tmx::Tile::getID() {
	return mID;
}

std::string tmx::Tile::getTerrain() {
	return mTerrain;
}

void tmx::Tile::setID(unsigned int id) {
	mID = id;
}

void tmx::Tile::setTerrain(std::string terrain) {
	mTerrain = terrain;
}