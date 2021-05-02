#include <float.h>  // FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX
#include <limits.h> // CHAR_MIN, CHAR_MAX, ..., LONG_MIN, LONG_MAX
#include <stdio.h>  // printf
#include <stdlib.h> // EXIT_SUCCESS

void printLimits() {

	// %s  : string
	// %c  : character

	// %d  : decimal integer
	// %u  : unsigned decimal integer
	// %zu : size_t
	// %hd : short decimal integer
	// %ld : long decimal integer

	// %f  : floating point number
	// %e  : exponential floating point number

	printf( "type\tsize\tmin\t\t\tmax\n" );
	printf( "------------------------------------------------------------\n" );
	printf( "%s\t%zu\n",               "bool",   sizeof(bool)                       );
	printf( "%s\t%zu\t%d\t\t\t%d\n",   "char",   sizeof(char),   CHAR_MIN, CHAR_MAX );
	printf( "%s\t%zu\t%hd\t\t\t%hd\n", "short",  sizeof(short),  SHRT_MIN, SHRT_MAX );
	printf( "%s\t%zu\t%d\t\t%d\n",     "int",    sizeof(int),    INT_MIN,  INT_MAX  );
	printf( "%s\t%zu\t%ld\t%ld\n",     "long",   sizeof(long),   LONG_MIN, LONG_MAX );
	printf( "%s\t%zu\t%e\t\t%e\n",     "float",  sizeof(float),  FLT_MIN,  FLT_MAX  );
	printf( "%s\t%zu\t%e\t\t%e\n",     "double", sizeof(double), DBL_MIN,  DBL_MAX  );
}

int main() {
	printLimits();
	return EXIT_SUCCESS;
}
