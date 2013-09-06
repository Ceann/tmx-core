#ifndef TMX_LAYER_H
#define TMX_LAYER_H

#include <iostream>
#include <map>
#include <string>

#include "TMX_Data.h"
#include "pugixml.hpp"

namespace tmx {
	class Layer {
	private:
		std::string mName;
		float mOpacity;
		bool mVisible;

		std::map <std::string, std::string> mProperties;

		Data mData;
	public:
		void init(pugi::xml_node layerNode);
		void tell();

		std::string getName();
		float getOpacity();
		bool getVisible();
		Data getData();

		void setName(std::string name);
		void setOpacity(float opacity);
		void setVisible(bool visible);
	};
};

#endif