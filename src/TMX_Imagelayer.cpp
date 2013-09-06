#include <iostream>

#include "TMX_Imagelayer.h"

#include "pugixml.hpp"

void tmx::Imagelayer::init(pugi::xml_node imagelayerNode) {
	setName(imagelayerNode.attribute("name").as_string());
	setOpacity(imagelayerNode.attribute("opacity").as_float());
	setVisible(imagelayerNode.attribute("visible").as_bool());

	for(pugi::xml_node image = imagelayerNode.child("image"); image; image = image.next_sibling("image")) {
		tmx::Image tempImage;
		tempImage.init(image);

		mImage.push_back(tempImage);
	}

	for(pugi::xml_node prop = imagelayerNode.child("properties").child("property"); prop; prop = prop.next_sibling("property")) {
		mProperties.insert(std::pair<std::string, std::string>(prop.attribute("name").as_string(), prop.attribute("value").as_string()));
	}
}

void tmx::Imagelayer::tell() {
	std::cout << "Name: " << getName() << "\n"
			  << "Opacity: " << getOpacity() << "\n"
			  << "Visible: " << getVisible() << std::endl;
}

// ACCESSORS

std::string tmx::Imagelayer::getName() {
	return mName;
}

float tmx::Imagelayer::getOpacity() {
	return mOpacity;
}

bool tmx::Imagelayer::getVisible() {
	return mVisible;
}

// MUTATORS

void tmx::Imagelayer::setName(std::string name) {
	mName = name;
}

void tmx::Imagelayer::setOpacity(float opacity) {
	mOpacity = opacity;
}

void tmx::Imagelayer::setVisible(bool visible) {
	mVisible = visible;
}