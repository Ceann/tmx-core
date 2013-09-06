#ifndef TMX_IMAGELAYER_H
#define TMX_IMAGELAYER_H

#include <map>
#include <string>
#include <vector>

#include "TMX_Image.h"

#include "pugixml.hpp"

namespace tmx {
	class Imagelayer {
	private:
		std::string mName;
		float mOpacity;
		bool mVisible;

		std::map <std::string, std::string> mProperties;

		std::vector <Image> mImage;
	public:
		void init(pugi::xml_node imagelayerNode);
		void tell();

		std::string getName();
		float getOpacity();
		bool getVisible();

		void setName(std::string name);
		void setOpacity(float opacity);
		void setVisible(bool visible);
	};
};

#endif