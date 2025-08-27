#include <iostream>
#include <string>

using namespace std;

bool ppe(const string& s) {
	int depth = 0;

	for (char ch : s) {
		if (ch == '(') {
			++depth; // count how many opening ( there are
		} else if (ch == ')') { 
			if (depth == 0) return false; // closed without a matching open (
			--depth; // this will decrement depth on seeing a )
		}
	}

	return depth == 0; // if depth is 0 at the end of the string then all opens ('s are closed off with )'s
}


int main() {

	string s;

	s = "i(re)(w)";

	cout << "ppe(\"" << s << "\") -> " << ppe(s) << '\n';

	s = ") ( ()";

	cout << "ppe(\"" << s << "\") -> " << ppe(s) << '\n';

	s = "( ()";

	cout << "ppe(\"" << s << "\") -> " << ppe(s) << '\n';

	s = "(() (()))";

	cout << "ppe(\"" << s << "\") -> " << ppe(s) << '\n';
}
