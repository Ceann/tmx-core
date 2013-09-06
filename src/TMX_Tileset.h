#ifndef TMX_TILESET_H
#define TMX_TILESET_H

#include <map>
#include <string>
#include <vector>

#include "TMX_Tileoffset.h"
#include "TMX_Image.h"
#include "TMX_Terraintypes.h"
#include "TMX_Tile.h"

namespace tmx {
	class Tileset {
	private:
		int mFirstgid;
		std::string mSource;
		std::string mName;
		unsigned int mTileWidth;
		unsigned int mTileHeight;
		unsigned int mSpacing;
		unsigned int mMargin;

		std::map <std::string, std::string> mProperties;

		Tileoffset mTileOffset;
		Image mImage;
		Terraintypes mTerrainTypes;
		std::vector <Tile> mTile;

	public:
		void init(pugi::xml_node tilesetNode);
		void tmx::Tileset::tell();

		int getFirstGid();
		std::string getSource();
		std::string getName();
		unsigned int getTileWidth();
		unsigned int getTileHeight();
		unsigned int getSpacing();
		unsigned int getMargin();
		Tileoffset getTileoffset();
		Image getImage();
		Terraintypes getTerrainTypes();
		Tile getTile(unsigned int index);

		void setFirstGid(int gid);
		void setSource(std::string source);
		void setName(std::string name);
		void setTileWidth(unsigned int tileWidth);
		void setTileHeight(unsigned int tileHeight);
		void setSpacing(unsigned int spacing);
		void setMargin(unsigned int margin);
	};
};

#endif