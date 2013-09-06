#ifndef TMX_DATA_H
#define TMX_DATA_H

#include <string>
#include <vector>

#include "pugixml.hpp"

namespace tmx {
	class Data {
	private:
		std::string mEncoding;
		std::string mCompression;
		std::vector <unsigned int> mGid;

	public:
		void init(pugi::xml_node dataNode);

		std::string getEncoding();
		std::string getCompression();
		unsigned int getGid(unsigned int index);

		void setEncoding(std::string encoding);
		void setCompression(std::string compression);
	};
};

#endif