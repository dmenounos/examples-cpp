#include <stdio.h>
#include <string.h>

#define STR_SIZE 80

int main() {

	// Read a string

	char name[STR_SIZE];
	int valid_name = false;

	while (!valid_name) {
		fprintf(stdout, "What is your name?\n");
		fscanf(stdin, "%s", name);

		if (strlen(name) > 0) {
			valid_name = true;
		}
	}

	// Read another string

	char age[STR_SIZE];
	int valid_age = false;

	while (!valid_age) {
		fprintf(stdout, "What is your age?\n");
		fscanf(stdin, "%s", age);

		if (strlen(age) > 0) {
			valid_age = true;
		}
	}

	fprintf(stdout, "Hello '%s', your age is '%s'.\n", name, age);
	return 0;
}
