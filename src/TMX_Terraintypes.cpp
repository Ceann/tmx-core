#include <iostream>

#include "TMX_Terraintypes.h"
#include "pugixml.hpp"

void tmx::Terraintypes::init(pugi::xml_node terrainType) {
	for(pugi::xml_node terrain = terrainType.child("terrain"); terrain; terrain = terrain.next_sibling("terrain")) {
		tmx::Terrain tempTerrain;
		tempTerrain.setName(terrain.attribute("name").as_string());
		tempTerrain.setTile(terrain.attribute("tile").as_int());
		mTerrain.push_back(tempTerrain);
	}
}

tmx::Terrain tmx::Terraintypes::getTerrainType(int index) {
	if(index > mTerrain.size()) {
		throw std::out_of_range("Requested terrain type is out of range.");
	}
	return mTerrain[index];
}