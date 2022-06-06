#include <stdio.h>  // stdout, stdin, fprintf, fscanf, ...
#include <limits.h> // INT_MIN, INT_MAX, ...
#include <string.h> // strlen

#define STR_SIZE 80

int main() {

	char str1[STR_SIZE];
	char str2[STR_SIZE];
	char str3[STR_SIZE];

	fprintf(stdout, "Enter a string:\n");
	fscanf(stdin, "%s", str1);

	// The fscanf (above) puts the \n character back to the input stream.
	// This is a problem when used together with fgets (below).
	// The fgets does not discard whitespace and the \n left over 
	// works as an automatic and surprising empty input.
	for (int c; ((c = fgetc(stdin)) != '\n') && (c != EOF);) {}

	fprintf(stdout, "Enter another string:\n");
	fgets(str2, STR_SIZE, stdin);

	// The fgets also captures the \n character; remove it.
	str2[strlen(str2) - 1] = '\0';

	// Interestingly the above issue does not happen after subsequent calls to 
	// fgets. Thus we do not have to consume the stream here.

	fprintf(stdout, "Enter yet another string:\n");
	fgets(str3, STR_SIZE, stdin);

	// The fgets also captures the \n character; remove it.
	str3[strlen(str3) - 1] = '\0';

	fprintf(stdout, "You typed '%s' and '%s' and '%s'.\n", str1, str2, str3);
	return 0;
}
