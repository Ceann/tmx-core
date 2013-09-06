#include <iostream>

#include "TMX_Objectgroup.h"

#include "pugixml.hpp"

void tmx::Objectgroup::init(pugi::xml_node objectgroupNode) {
	setName(objectgroupNode.attribute("name").as_string());
	setColor(objectgroupNode.attribute("color").as_string());
	setOpacity(objectgroupNode.attribute("opacity").as_float());
	setVisible(objectgroupNode.attribute("visible").as_bool());

	for(pugi::xml_node prop = objectgroupNode.child("properties").child("property"); prop; prop = prop.next_sibling("properties")) {
		mProperties.insert(std::pair<std::string, std::string>(prop.attribute("name").as_string(), prop.attribute("value").as_string()));
	}

	for(pugi::xml_node object = objectgroupNode.child("object"); object; object = object.next_sibling("object")) {
		tmx::Object tempObject;
		tempObject.init(object);
		mObject.push_back(tempObject);
	}
}

void tmx::Objectgroup::tell() {
	std::cout << "Name: " << getName() << "\n"
			  << "Color: " << getColor() << "\n"
			  << "Opacity: " << getOpacity() << "\n"
			  << "Visible: " << getVisible() << std::endl;
}

// ACCESSORS

std::string tmx::Objectgroup::getName() {
	return mName;
}

std::string tmx::Objectgroup::getColor() {
	return mColor;
}

float tmx::Objectgroup::getOpacity() {
	return mOpacity;
}

bool tmx::Objectgroup::getVisible() {
	return mVisible;
}

// MUTATORS

void tmx::Objectgroup::setName(std::string name) {
	mName = name;
}

void tmx::Objectgroup::setColor(std::string color) {
	mColor = color;
}

void tmx::Objectgroup::setOpacity(float opacity) {
	mOpacity = opacity;
}

void tmx::Objectgroup::setVisible(bool visible) {
	mVisible = visible;
}