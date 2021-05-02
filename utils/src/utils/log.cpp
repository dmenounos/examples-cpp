#include "log.hpp"

static int _log_level = LOG_LEVEL_EMPTY;

int log_get_level() {
	return _log_level;
}

void log_set_level(int log_level) {
	_log_level = log_level;
}
