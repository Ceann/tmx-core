#include <iostream>

#include "TMX.h"

void tmx::importProperties(pugi::xml_node node, std::map<std::string, std::string> propMap) {
	for(pugi::xml_node prop = node.child("properties").child("property"); prop; prop = prop.next_sibling("property")) {
		propMap.insert(std::pair<std::string, std::string>(prop.attribute("name").as_string(), prop.attribute("value").as_string()));
	}
}