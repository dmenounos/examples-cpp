#ifndef LOG_HPP
#define LOG_HPP

#include <stdio.h>

#define LOG_LEVEL_EMPTY 0
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_AUDIT 2
#define LOG_LEVEL_DEBUG 3
#define LOG_LEVEL_TRACE 4

int log_get_level();
void log_set_level(int log_level);

// Log message
#define LOG_M(...) \
if (log_get_level() != LOG_LEVEL_EMPTY) { \
	fprintf(stdout, __VA_ARGS__); \
	fprintf(stdout, "\n"); \
} \

// Log error message
#define LOG_E(...) \
if (log_get_level() >= LOG_LEVEL_ERROR) { \
	fprintf(stdout, "!!! "); \
	fprintf(stdout, __VA_ARGS__); \
	fprintf(stdout, "\n"); \
} \

// Log audit message
#define LOG_A(...) \
if (log_get_level() >= LOG_LEVEL_AUDIT) { \
	fprintf(stdout, "=== "); \
	fprintf(stdout, __VA_ARGS__); \
	fprintf(stdout, "\n"); \
} \

// Log debug message
#define LOG_D(...) \
if (log_get_level() >= LOG_LEVEL_DEBUG) { \
	fprintf(stdout, ">>> "); \
	fprintf(stdout, __VA_ARGS__); \
	fprintf(stdout, "\n"); \
} \

// Log trace message
#define LOG_T(...) \
if (log_get_level() >= LOG_LEVEL_TRACE) { \
	fprintf(stdout, "~~~ "); \
	fprintf(stdout, __VA_ARGS__); \
	fprintf(stdout, "\n"); \
} \

#endif /* LOG_HPP */
