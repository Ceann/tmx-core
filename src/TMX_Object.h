#ifndef TMX_OBJECT_H
#define TMX_OBJECT_H

#include <string>
#include <vector>

#include "TMX_Point.h"

#include "pugixml.hpp"

namespace tmx {
	enum objecttype {
		RECT,
		ELLIPSE,
		POLYGON,
		POLYLINE
	};
	
	class Object {
	private:
		std::string mName;
		std::string mType;

		unsigned int mX;
		unsigned int mY;

		unsigned int mWidth;
		unsigned int mHeight;
		unsigned int mRotation;
		unsigned int mGid;
		bool mVisible;

		objecttype mObjectType;
		std::vector<Point> points;
	public:
		void init(pugi::xml_node objectNode);

		std::string getName();
		std::string getType();
		unsigned int getX();
		unsigned int getY();
		unsigned int getWidth();
		unsigned int getHeight();
		unsigned int getRotation();
		unsigned int getGid();
		bool getVisible();
		objecttype getObjectType();

		void setName(std::string name);
		void setType(std::string type);
		void setX(int x);
		void setY(int y);
		void setWidth(unsigned int width);
		void setHeight(unsigned int height);
		void setRotation(unsigned int rotation);
		void setGid(unsigned int gid);
		void setVisible(bool visible);
		void setObjectType(objecttype type);
	};
};
#endif