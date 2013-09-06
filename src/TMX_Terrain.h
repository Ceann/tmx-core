#ifndef TMX_TERRAIN_H
#define TMX_TERRAIN_H

#include <string>

namespace tmx {
	class Terrain {
	private:
		std::string mName;
		int mTile;
	public:
		std::string getName();
		int getTile();

		void setName(std::string name);
		void setTile(int tile);
	};
};

#endif