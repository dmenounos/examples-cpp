#include <utils/utils.hpp>

using namespace utils;

int main(int argc, char* argv[]) {
	log_set_level(LOG_LEVEL_TRACE);

	string trimmed;

	LOG_M(" ");
	trimmed = trim_string("lala");

	LOG_M(" ");
	trimmed = trim_string(" lala ");

	LOG_M(" ");
	trimmed = trim_string("\t lala \t");

	LOG_M(" ");
	trimmed = trim_string("mama lala kaka");

	LOG_M(" ");
	trimmed = trim_string("  mama lala kaka  ");

	LOG_M(" ");
	return 0;
}
