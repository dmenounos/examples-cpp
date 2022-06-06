#include <utils/utils.hpp>

using namespace utils;

void print_vector(const vector<string>& vector) {
	LOG_D("print_vector");

	for (size_t i = 0; i < vector.size(); ++i) {
		LOG_A("%2zu: '%s'", i, vector[i].c_str());
	}
}

int main(int argc, char* argv[]) {
	log_set_level(LOG_LEVEL_TRACE);

	vector<string> splits;

	LOG_M(" ");
	splits = split_string("lala");
	print_vector(splits);

	LOG_M(" ");
	splits = split_string(" lala ");
	print_vector(splits);

	LOG_M(" ");
	splits = split_string("  lala  ");
	print_vector(splits);

	LOG_M(" ");
	splits = split_string("mama lala kaka");
	print_vector(splits);

	LOG_M(" ");
	splits = split_string("  mama lala kaka  ");
	print_vector(splits);

	LOG_M(" ");
	return 0;
}
