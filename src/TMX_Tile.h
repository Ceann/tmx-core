#ifndef TMX_TILE_H
#define TMX_TILE_H

#include <string>

#include "pugixml.hpp"

namespace tmx {

	class Tile {
	private:
		unsigned int mID;
		std::string mTerrain;
	public:
		void init(pugi::xml_node tileset);

		unsigned int getID();
		std::string getTerrain();

		void setID(unsigned int id);
		void setTerrain(std::string terrain);
	};

};

#endif