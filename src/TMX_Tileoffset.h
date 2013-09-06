#ifndef TMX_TILEOFFSET_H
#define TMX_TILEOFFSET_H

#include "pugixml.hpp"

namespace tmx {
	class Tileoffset {
		int mX;
		int mY;

	public:
		void init(pugi::xml_node);

		int getX();
		int getY();

		void setX(int x);
		void setY(int y);
	};
};

#endif