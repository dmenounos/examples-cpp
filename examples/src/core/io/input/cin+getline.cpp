#include <iostream> // cout, cin
#include <limits>   // numeric_limits
#include <string>   // string, getline

using namespace std;

int main() {

	string str1;
	string str2;
	string str3;

	cout << "Enter a string:\n";
	cin >> str1;

	// The cin (above) puts the \n character back to the input stream.
	// This is a problem when used together with getline (below).
	// The getline does not discard whitespace and the \n left over 
	// works as an automatic and surprising empty input.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter another string:\n";
	getline(cin, str2);

	// Interestingly the above issue does not happen after subsequent calls to 
	// getline. Thus we do not have to consume the stream here.

	cout << "Enter yet another string:\n";
	getline(cin, str3);

	cout << "You typed '" << str1 << "' and '" << str2 << "' and '" << str3 << "'.\n";
	return 0;
}
