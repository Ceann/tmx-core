#ifndef TMX_IMAGE_H
#define TMX_IMAGE_H

#include <string>

#include "pugixml.hpp"

namespace tmx {
	class Image {
	private:
		std::string mSource;
		std::string mTrans;
		unsigned int mWidth;
		unsigned int mHeight;
	public:
		void init(pugi::xml_node imageNode);

		std::string getSource();
		std::string getTrans();
		unsigned int getWidth();
		unsigned int getHeight();

		void setSource(std::string source);
		void setTrans(std::string trans);
		void setWidth(unsigned int width);
		void setHeight(unsigned int height);
	};
};

#endif