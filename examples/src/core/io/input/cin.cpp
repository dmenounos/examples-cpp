#include <iostream>
#include <string>

using namespace std;

int main() {

	// Read a string

	string name;
	int valid_name = false;

	while (!valid_name) {
		cout << "What is your name?\n";
		cin >> name;

		if (!name.empty()) {
			valid_name = true;
		}
	}

	// Read another string

	string age;
	int valid_age = false;

	while (!valid_age) {
		cout << "What is your age?\n";
		cin >> age;

		if (!age.empty()) {
			valid_age = true;
		}
	}

	cout << "Hello '" << name << "', your age is '" << age << "'.\n";
	return 0;
}
