#include "TMX_Data.h"

#include "pugixml.hpp"

void tmx::Data::init(pugi::xml_node dataNode) {
	setEncoding(dataNode.attribute("encoding").as_string());
	setCompression(dataNode.attribute("compression").as_string());
	mGid.push_back(dataNode.attribute("gid").as_uint());
}

std::string tmx::Data::getEncoding() {
	return mEncoding;
}

std::string tmx::Data::getCompression() {
	return mCompression;
}

unsigned int tmx::Data::getGid(unsigned int index) {
	if(mGid.size() < index) {
		throw std::out_of_range("Requested gID out of range.");
	}
	return mGid[index];
}

void tmx::Data::setEncoding(std::string encoding) {
	mEncoding = encoding;
}

void tmx::Data::setCompression(std::string compression) {
	mCompression = compression;
}