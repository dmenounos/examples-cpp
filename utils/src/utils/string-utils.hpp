#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include "utils.hpp"

namespace utils {

	vector<string> split_string(const string& input_string, char delimeter = ' ');

	string trim_string(const string& input_string);

}

#endif // STRING_UTILS_HPP
