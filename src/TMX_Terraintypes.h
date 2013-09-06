#ifndef TMX_TERRAINTYPES_H
#define TMX_TERRAINTYPES_H

#include <vector>

#include "TMX.h"
#include "TMX_Terrain.h"

#include "pugixml.hpp"

namespace tmx {
	class Terraintypes {
	private:
		std::vector <Terrain> mTerrain;
	public:
		void init(pugi::xml_node terrainType);

		Terrain getTerrainType(int index);
	};
};

#endif