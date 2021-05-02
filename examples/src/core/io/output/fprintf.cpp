#include <stdio.h>

int main() {

	const char* str = "A string ..";
	int integer = 12345;
	double real = 1.2345;

	fprintf(stdout, "String  : %s\n", str);
	fprintf(stdout, "Integer : %d\n", integer);
	fprintf(stdout, "Real    : %f\n", real);
	fprintf(stdout, "Real with 2 digits : %.2f\n", real);

	return 0;
}
