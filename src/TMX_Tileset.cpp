#include <iostream>
#include <stdexcept>

#include "TMX_Tileset.h"

void tmx::Tileset::init(pugi::xml_node tilesetNode) {
	setFirstGid(tilesetNode.attribute("firstgid").as_int());
	setSource(tilesetNode.attribute("source").as_string());
	setName(tilesetNode.attribute("name").as_string());
	setTileWidth(tilesetNode.attribute("tilewidth").as_uint());
	setTileHeight(tilesetNode.attribute("tileheight").as_uint());
	setSpacing(tilesetNode.attribute("spacing").as_uint());
	setMargin(tilesetNode.attribute("margin").as_uint());

	for(pugi::xml_node prop = tilesetNode.child("properties").first_child(); prop; prop = prop.next_sibling()) {
		mProperties.insert(std::pair<std::string, std::string>(prop.attribute("name").as_string(), prop.attribute("value").as_string()));
	}

	mTileOffset.init(tilesetNode.child("tileoffset"));

	mImage.init(tilesetNode.child("image"));

	mTerrainTypes.init(tilesetNode.child("terraintypes"));

	for(pugi::xml_node tile = tilesetNode.child("tile"); tile; tile = tile.next_sibling("tile")) {
		tmx::Tile tempTile;
		tempTile.setID(tile.attribute("id").as_uint());
		tempTile.setTerrain(tile.attribute("terrain").as_string());
		mTile.push_back(tempTile);
	}
}

void tmx::Tileset::tell() {
	std::cout << "Name: " << getName() << "\n"
			  << "Source: " << getSource() << "\n"
			  << "First gID: " << getFirstGid() << "\n"
			  << "Tile Width: " << getTileWidth() << "\n"
			  << "Tile Height: " << getTileHeight() << "\n"
			  << "Spacing: " << getSpacing() << "\n"
			  << "Margin: " << getMargin() << std::endl;
}

// ACCESSORS

int tmx::Tileset::getFirstGid() {
	return mFirstgid;
}

std::string tmx::Tileset::getSource() {
	return mSource;
}

std::string tmx::Tileset::getName() {
	return mName;
}

unsigned int tmx::Tileset::getTileWidth() {
	return mTileWidth;
}

unsigned int tmx::Tileset::getTileHeight() {
	return mTileHeight;
}

unsigned int tmx::Tileset::getSpacing() {
	return mSpacing;
}

unsigned int tmx::Tileset::getMargin() {
	return mMargin;
}

tmx::Tileoffset tmx::Tileset::getTileoffset() {
	return mTileOffset;
}

tmx::Image tmx::Tileset::getImage() {
	return mImage;
}

tmx::Terraintypes tmx::Tileset::getTerrainTypes() {
	return mTerrainTypes;
}

tmx::Tile tmx::Tileset::getTile(unsigned int index) {
	if(index > mTile.size()) {
		throw std::out_of_range("Requested tile is out of range.");
	}
	return mTile[index];
}

// MUTATORS

void tmx::Tileset::setFirstGid(int gid) {
	mFirstgid = gid;
}

void tmx::Tileset::setSource(std::string source) {
	mSource = source;
}

void tmx::Tileset::setName(std::string name) {
	mName = name;
}

void tmx::Tileset::setTileWidth(unsigned int tileWidth) {
	mTileWidth = tileWidth;
}

void tmx::Tileset::setTileHeight(unsigned int tileHeight) {
	mTileHeight = tileHeight;
}

void tmx::Tileset::setSpacing(unsigned int spacing) {
	mSpacing = spacing;
}

void tmx::Tileset::setMargin(unsigned int margin) {
	mMargin = margin;
}