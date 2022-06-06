#include <stdlib.h>
#include <stdio.h>

#include "Rect.hpp"

#define LOG(...) fprintf(stdout, __VA_ARGS__)
#define DEBUG(...) fprintf(stderr, __VA_ARGS__)

// Scale the min dimension up, such as the image covers the whole frame area.
// This will most probably crop non-visible areas around the max dimension.
#define SCALE_UP 0

// Scale the max dimension down, such as the whole image to fit inside the frame.
// This will most probably create empty borders around the min dimension.
#define SCALE_DOWN 1

/**
 * @param image the reference source element
 * @param frame the target element to match
 */
void scale(int scaleType, const Rect& image, const Rect& frame) {
	float imageRatio = (float) image.getWidth() / image.getHeight();
	float frameRatio = (float) frame.getWidth() / frame.getHeight();
	float ratio = 1;

	LOG("scale type: %s\n", scaleType == 0 ? "SCALE_UP (CROP)" : "SCALE_DOWN (BORDER)");
	LOG("image width: %4d, height: %4d, ratio: %f\n", image.getWidth(), image.getHeight(), imageRatio);
	LOG("frame width: %4d, height: %4d, ratio: %f\n", frame.getWidth(), frame.getHeight(), frameRatio);

	if (imageRatio > frameRatio) {
		LOG("image is wider than frame; ");

		switch (scaleType) {
		case SCALE_UP:
			LOG("scaling up image height\n");
			ratio = (float) frame.getHeight() / image.getHeight();
			break;

		case SCALE_DOWN:
			LOG("scaling down image width\n");
			ratio = (float) frame.getWidth() / image.getWidth();
			break;
		}
	} else if (imageRatio < frameRatio) {
		LOG("image is narrower than frame; ");

		switch (scaleType) {
		case SCALE_UP:
			LOG("scaling up image width\n");
			ratio = (float) frame.getWidth() / image.getWidth();
			break;

		case SCALE_DOWN:
			LOG("scaling down image height\n");
			ratio = (float) frame.getHeight() / image.getHeight();
			break;
		}
	}

	int width  = image.getWidth()  * ratio + 0.5f;
	int height = image.getHeight() * ratio + 0.5f;
	LOG("final width: %4d, height: %4d\n", width, height);
	LOG("\n");
}

int main(int argc, char* argv[]) {
	Rect image(800, 480);
	Rect frame_16_10(1280, 800);
	Rect frame_16_09(1280, 720);

	LOG("scale to 16/10 frame\n");
	scale(SCALE_UP, image, frame_16_10);

	LOG("scale to 16/10 frame\n");
	scale(SCALE_DOWN, image, frame_16_10);

	LOG("scale to 16/9 frame\n");
	scale(SCALE_UP, image, frame_16_09);

	LOG("scale to 16/9 frame\n");
	scale(SCALE_DOWN, image, frame_16_09);

	return EXIT_SUCCESS;
}
