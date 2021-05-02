#include "utils.hpp"

namespace utils {

	vector<string> split_string(const string& input_string, char delimeter) {
		LOG_D("split_string '%s'", input_string.c_str());

		vector<string> result;

		size_t i = 0;
		size_t del_pos = input_string.find(delimeter, i);

		LOG_T("loop delimeter");

		while (del_pos != string::npos) {
			LOG_T("i: %zu del_pos: %zu", i, del_pos);

			if (i != del_pos) {
				string sub_string = input_string.substr(i, del_pos - i);
				LOG_A("sub_string(%zu, %zu) -> '%s'", i, del_pos - i, sub_string.c_str());
				result.push_back(sub_string);
			}

			i = del_pos + 1;
			del_pos = input_string.find(delimeter, i);
		}

		LOG_T("test remainder");

		if (i < input_string.length()) {
			LOG_T("i: %zu str_end: %zu", i, input_string.length());
			string sub_string = input_string.substr(i, input_string.length() - i);
			LOG_A("sub_string(%zu, %zu) -> '%s'", i, input_string.length() - i, sub_string.c_str());
			result.push_back(sub_string);
		}

		return result;
	}

	string trim_string(const string& input_string) {
		LOG_D("trim_string '%s'", input_string.c_str());

		size_t begPos = 0;
		size_t endPos = input_string.size();

		for (size_t i = 0; i < input_string.size(); i++) {
			const char& c = input_string[i];

			if (!isspace(c)) {
				begPos = i;
				break;
			}
		}

		LOG_T("begPos: %zu", begPos);

		for (size_t i = input_string.size(); i > 0; i--) {
			const char& c = input_string[i - 1];

			if (!isspace(c)) {
				endPos = i;
				break;
			}
		}

		LOG_T("endPos: %zu", endPos);

		string result = input_string.substr(begPos, endPos - begPos);

		LOG_A("result: '%s'", result.c_str());

		return result;
	}

}
