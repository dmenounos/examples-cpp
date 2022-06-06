#ifndef RECT_HPP
#define RECT_HPP

class Rect {

	int mWidth;
	int mHeight;

public:
	Rect(int width, int height);

	int getWidth() const;
	void setWidth(int width);

	int getHeight() const;
	void setHeight(int height);
};

#endif
