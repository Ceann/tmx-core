#include <iostream>
#include "TMX_Tilemap.h"

int main(int argc, char** argv) {

	tmx::Tilemap aTilemap("template.tmx");

	std::cout << std::endl;
	aTilemap.tell();

	return 0;
}