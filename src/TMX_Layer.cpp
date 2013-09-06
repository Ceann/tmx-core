#include <iostream>

#include "TMX.h"
#include "TMX_Layer.h"
#include "pugixml.hpp"

// ACCESSORS

void tmx::Layer::init(pugi::xml_node layerNode) {
	setName(layerNode.attribute("name").as_string());
	setOpacity(layerNode.attribute("opacity").as_float());
	setVisible(layerNode.attribute("visible").as_bool());

	tmx::importProperties(layerNode, mProperties);

	for(pugi::xml_node tile = layerNode.child("data").child("tile"); tile; tile = tile.next_sibling("tile")) {
			mData.init(tile.child("data"));
	}
}

void tmx::Layer::tell() {
	std::cout << "Name: " << getName() << "\n"
			  << "Opacity: " << getOpacity() << "\n"
			  << "Visible: " << getVisible() << std::endl;
}

std::string tmx::Layer::getName() {
	return mName;
}

float tmx::Layer::getOpacity() {
	return mOpacity;
}

bool tmx::Layer::getVisible() {
	return mVisible;
}

tmx::Data tmx::Layer::getData() {
	return mData;
}

// MUTATORS

void tmx::Layer::setName(std::string name) {
	mName = name;
}

void tmx::Layer::setOpacity(float opacity) {
	mOpacity = opacity;
}

void tmx::Layer::setVisible(bool visible) {
	mVisible = visible;
}