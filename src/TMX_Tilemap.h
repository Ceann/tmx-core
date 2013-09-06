#ifndef TMX_TILEMAP_H
#define TMX_TILEMAP_H

#include <string>
#include <cstdint>
#include <map>
#include <vector>

#include "TMX_Image.h"
#include "TMX_Imagelayer.h"
#include "TMX_Layer.h"
#include "TMX_Objectgroup.h"
#include "TMX_Point.h"
#include "TMX_Tileset.h"

#include "pugixml.hpp"

namespace tmx {

	enum orientation {
		ORTHO,
		ISO,
		STAG
	};

	class Tilemap {
	private:
		std::string mVersion;
		orientation mOrientation;
		unsigned int mWidth;
		unsigned int mHeight;
		unsigned int mTileWidth;
		unsigned int mTileHeight;
		std::string mBackgroundColor;
	
		std::map <std::string, std::string> mProperties;
	
		std::vector <Tileset> mTileset;
		std::vector <Layer> mLayer;
		std::vector <Objectgroup> mObjectGroup;
		std::vector <Imagelayer> mImageLayer;
	public:
		Tilemap(const std::string file);

		std::string getVersion();
		std::string getOrientation();
		unsigned int getWidth();
		unsigned int getHeight();
		unsigned int getTileWidth();
		unsigned int getTileHeight();
		std::string getBackgroundColor();

		Tileset getTileset(int index);
		Layer getLayer(int index);
		Objectgroup getObjectgroup(int index);
		Imagelayer getImagelayer(int index);

		void setVersion(const std::string);
		void setOrientation(const std::string orientationString);
		void setWidth(unsigned int width);
		void setHeight(unsigned int height);
		void setTileWidth(unsigned int tileWidth);
		void setTileHeight(unsigned int tileHeight);
		void setBackgroundColor(std::string backgroundColor);

		void tell();
		void init(pugi::xml_node map);
	};
};
#endif