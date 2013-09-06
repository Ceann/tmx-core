#include "TMX_Image.h"

void tmx::Image::init(pugi::xml_node node) {
	setSource(node.attribute("source").as_string());
	setTrans(node.attribute("trans").as_string());
	setWidth(node.attribute("width").as_uint());
	setHeight(node.attribute("height").as_uint());
}

std::string tmx::Image::getSource() {
	return mSource;
}

std::string tmx::Image::getTrans() {
	return mTrans;
}

unsigned int tmx::Image::getWidth() {
	return mWidth;
}

unsigned int tmx::Image::getHeight() {
	return mHeight;
}

void tmx::Image::setSource(std::string source) {
	mSource = source;
}

void tmx::Image::setTrans(std::string trans) {
	mTrans = trans;
}

void tmx::Image::setWidth(unsigned int width) {
	mWidth = width;
}

void tmx::Image::setHeight(unsigned int height) {
	mHeight = height;
}