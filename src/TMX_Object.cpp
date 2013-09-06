#include <string>

#include "TMX_Object.h"

void tmx::Object::init(pugi::xml_node objectNode) {
	setName(objectNode.attribute("name").as_string());
	setType(objectNode.attribute("type").as_string());
	setX(objectNode.attribute("x").as_uint());
	setY(objectNode.attribute("y").as_uint());
	setWidth(objectNode.attribute("width").as_uint());
	setHeight(objectNode.attribute("height").as_uint());
	setRotation(objectNode.attribute("rotation").as_uint());
	setGid(objectNode.attribute("gid").as_uint());
	if(objectNode.child("ellipse")) {
		setObjectType(ELLIPSE);
	} else if (objectNode.child("polyline")) {
		setObjectType(POLYLINE);
	} else if (objectNode.child("polygon")) {
		setObjectType(POLYGON);
	} else {
		setObjectType(RECT);
	}
}

// ACCESSORS

std::string tmx::Object::getName() {
	return mName;
}

std::string tmx::Object::getType() {
	return mType;
}

unsigned int tmx::Object::getX() {
	return mX;
}

unsigned int tmx::Object::getY() {
	return mY;
}

unsigned int tmx::Object::getWidth() {
	return mWidth;
}

unsigned int tmx::Object::getHeight() {
	return mHeight;
}

unsigned int tmx::Object::getRotation() {
	return mRotation;
}

unsigned int tmx::Object::getGid() {
	return mGid;
}

bool tmx::Object::getVisible() {
	return mVisible;
}

tmx::objecttype tmx::Object::getObjectType() {
	return mObjectType;
}

// MUTATORS

void tmx::Object::setName(std::string name) {
	mName = name;
}

void tmx::Object::setType(std::string type) {
	mType = type;
}

void tmx::Object::setX(int x) {
	mX = x;
}

void tmx::Object::setY(int y) {
	mY = y;
}

void tmx::Object::setWidth(unsigned int width) {
	mWidth = width;
}

void tmx::Object::setHeight(unsigned int height) {
	mHeight = height;
}

void tmx::Object::setRotation(unsigned int rotation) {
	mRotation = rotation % 360;
}

void tmx::Object::setGid(unsigned int gid) {
	mGid = gid;
}

void tmx::Object::setVisible(bool visible) {
	mVisible = visible;
}

void tmx::Object::setObjectType(tmx::objecttype type) {
	mObjectType = type;
}