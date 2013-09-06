#ifndef TMX_POINT_H
#define TMX_POINT_H

namespace tmx {
	class Point {
	private:
		int mX;
		int mY;
	public:
		int getX();
		int getY();

		void setX(int x);
		void setY(int y);
	};
};

#endif