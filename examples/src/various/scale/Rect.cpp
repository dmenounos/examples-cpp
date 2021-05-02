#include "Rect.hpp"

Rect::Rect(int width, int height) {
	setWidth(width);
	setHeight(height);
}

int Rect::getWidth() const {
	return mWidth;
}

void Rect::setWidth(int width) {
	this->mWidth = width;
}

int Rect::getHeight() const {
	return mHeight;
}

void Rect::setHeight(int height) {
	this->mHeight = height;
}
