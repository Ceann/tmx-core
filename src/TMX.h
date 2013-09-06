#ifndef TMX_H
#define TMX_H

#include <map>

// #include "TMX_Tilemap.h"

#include "pugixml.hpp"

namespace tmx {
	void importProperties(pugi::xml_node node, std::map<std::string, std::string> propMap);
};

#endif