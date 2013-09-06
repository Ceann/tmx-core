#ifndef TMX_OBJECTGROUP_H
#define TMX_OBJECTGROUP_H

#include <map>
#include <vector>

#include "TMX_Object.h"

#include "pugixml.hpp"

namespace tmx {
	class Objectgroup {
	private:
		std::string mName;
		std::string mColor;
		float mOpacity;
		bool mVisible;

		std::map<std::string, std::string> mProperties;

		std::vector<Object> mObject;

	public:
		void init(pugi::xml_node objectgroupNode);
		void tell();

		std::string getName();
		std::string getColor();
		float getOpacity();
		bool getVisible();

		void setName(std::string name);
		void setColor(std::string color);
		void setOpacity(float opacity);
		void setVisible(bool visible);
	};
};

#endif