#include <iostream>

#include "TMX.h"
#include "TMX_Terrain.h"
#include "TMX_Tile.h"
#include "TMX_Tilemap.h"
#include "pugixml.hpp"

tmx::Tilemap::Tilemap(const std::string file) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(file.c_str());
	pugi::xml_node map = doc.child("map");
	
	init(map);
	
	for(pugi::xml_node tileset = map.child("tileset"); tileset; tileset = tileset.next_sibling("tileset")) {
		tmx::Tileset tempTileset;
		tempTileset.init(tileset);
		mTileset.push_back(tempTileset);
	}

	for(pugi::xml_node layer = map.child("layer"); layer; layer = layer.next_sibling("layer")) {
		tmx::Layer tempLayer;
		tempLayer.init(layer);
		mLayer.push_back(tempLayer);
	}

	for(pugi::xml_node objectgroup = map.child("objectgroup"); objectgroup; objectgroup = objectgroup.next_sibling("objectgroup")) {
		tmx::Objectgroup tempObjectgroup;
		tempObjectgroup.init(objectgroup);
		mObjectGroup.push_back(tempObjectgroup);
	}

	for(pugi::xml_node imagelayer = map.child("imagelayer"); imagelayer; imagelayer = imagelayer.next_sibling("imagelayer")) {
		tmx::Imagelayer tempImagelayer;
		tempImagelayer.init(imagelayer);
		mImageLayer.push_back(tempImagelayer);
	}
}

void tmx::Tilemap::tell() {
	std::cout << "==MAP==" << "\n\n"
			  << "Version: " << getVersion() << "\n"
			  << "Orientation: " << getOrientation() << "\n"
			  << "Width: " << getWidth() << "\n"
			  << "Height: " << getHeight() << "\n"
			  << "Tile width: " << getTileWidth() << "\n"
			  << "Tile height: " << getTileHeight() << "\n"
			  << "Background color: " << getBackgroundColor() << "\n"
			  << "# of tilesets: " << mTileset.size() << "\n"
			  << "# of layers: " << mLayer.size() << "\n"
			  << "# of objectgroups: " << mObjectGroup.size() << "\n"
			  << "# of imagelayers: " << mImageLayer.size() << "\n\n"
			  << "==TILESETS==" << "\n" << std::endl;

	for(std::vector<Tileset>::size_type i = 0; i != mTileset.size(); ++i) {
		mTileset[i].tell();
	}

	std::cout << "\n==LAYERS==\n" << std::endl;

	for(std::vector<Layer>::size_type i = 0; i != mLayer.size(); ++i) {
		mLayer[i].tell();
	}

	std::cout << "\n==OBJECT GROUPS==\n" << std::endl;

	for(std::vector<Objectgroup>::size_type i = 0; i != mObjectGroup.size(); ++i) {
		mObjectGroup[i].tell();
	}

	std::cout << "\n==IMAGE LAYERS==\n" << std::endl;

	for(std::vector<Imagelayer>::size_type i = 0; i != mImageLayer.size(); ++i) {
		mImageLayer[i].tell();
	}
}

void tmx::Tilemap::init(pugi::xml_node map) {
	setVersion(map.attribute("version").as_string());
	setOrientation(map.attribute("orientation").as_string());
	setWidth(map.attribute("width").as_uint());
	setHeight(map.attribute("height").as_uint());
	setTileWidth(map.attribute("tilewidth").as_uint());
	setTileHeight(map.attribute("tileheight").as_uint());
	setBackgroundColor(map.attribute("backgroundcolor").as_string());
	importProperties(map, mProperties);
}

// ACCESSORS

std::string tmx::Tilemap::getVersion() {
	return mVersion;
}

std::string tmx::Tilemap::getOrientation() {
	if(mOrientation == ORTHO) {
		return "orthogonal";
	} else if (mOrientation == ISO) {
		return "isometric";
	} else if (mOrientation == STAG) {
		return "staggered";
	}
	return "ERROR";
}

unsigned int tmx::Tilemap::getWidth() {
	return mWidth;
}

unsigned int tmx::Tilemap::getHeight() {
	return mHeight;
}

unsigned int tmx::Tilemap::getTileWidth() {
	return mTileWidth;
}

unsigned int tmx::Tilemap::getTileHeight() {
	return mTileWidth;
}

std::string tmx::Tilemap::getBackgroundColor() {
	return mBackgroundColor;
}

tmx::Tileset tmx::Tilemap::getTileset(int index) {
	if(index >= mTileset.size() || index < 0) {
		throw std::out_of_range("Requested tileset out of range.");
	}
	return mTileset[index];
}

tmx::Layer tmx::Tilemap::getLayer(int index) {
	if(index >= mLayer.size() || index < 0) {
		throw std::out_of_range("Requested layer out of range.");
	}
	return mLayer[index];
}

tmx::Objectgroup tmx::Tilemap::getObjectgroup(int index) {
	if(index >= mObjectGroup.size() || index < 0) {
		throw std::out_of_range("Requested object group out of range.");
	}
	return mObjectGroup[index];
}

tmx::Imagelayer tmx::Tilemap::getImagelayer(int index) {
	if(index > mImageLayer.size() || index < 0) {
		throw std::out_of_range("Requested image layer out of range.");
	}
	return mImageLayer[index];
}

// MUTATORS

void tmx::Tilemap::setVersion(std::string version) {
	mVersion = version;
}

void tmx::Tilemap::setOrientation(const std::string orientationString) {
	if("orthogonal" == orientationString) {
		mOrientation = tmx::ORTHO;
	} else if("isometric" == orientationString) {
		mOrientation = tmx::ISO;
	} else if("staggered" == orientationString) {
		mOrientation = tmx::STAG;
	}
}

void tmx::Tilemap::setWidth(unsigned int width) {
	mWidth = width;
}

void tmx::Tilemap::setHeight(unsigned int height) {
	mHeight = height;
}

void tmx::Tilemap::setTileWidth(unsigned int tileWidth) {
	mTileWidth = tileWidth;
}

void tmx::Tilemap::setTileHeight(unsigned int tileHeight) {
	mTileHeight = tileHeight;
}

void tmx::Tilemap::setBackgroundColor(std::string backgroundColor) {
	mBackgroundColor = backgroundColor;
}