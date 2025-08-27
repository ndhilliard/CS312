#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class WordDeque {
private:
	string str;

public:

	// default constructor
	WordDeque() : str("") {}

	// copy constructor
	WordDeque(const WordDeque& rhs) : str(rhs.str) {}

	// assignment overload
	WordDeque& operator=(const WordDeque& rhs) {
		if (this != &rhs) str = rhs.str;
		return *this;
	}

	//deconstructor
	~WordDeque() {}

	//add to front if letter
	void first(char c) {
		if (isalpha(static_cast<unsigned char>(c)))
			str.insert(str.begin(), c);
	}

	// add to back if letter
	void last(char c) {
		if (isalpha(static_cast<unsigned char>(c)))
			str.push_back(c);
	}

	// peek front
	char first() const {
		return str.empty() ? '\0' : str.front();
	}
	// peek back
	char last() const {
		return str.empty() ? '\0' : str.back();
	}


	void erase(bool fromFront) {
		if (str.empty()) return; 

		if (fromFront) str.erase(str.begin());
		
		else str.pop_back();
	}

	bool empty() const { return str.empty(); }

	// print str
	void print() const { cout << '[' << str << "]\n"; }
};

int main() {

	WordDeque word;

	cout << boolalpha;

	word.first('a'); word.print(); // [a]
	word.last('B'); word.print(); // [aB]
	word.first('1'); word.print(); // this is ignored b/c non letter

	cout << "first(): " << word.first() << "\n"; // should be a
	cout << "last(): " << word.last() << "\n"; // should be B
	cout << "empty(): " << word.empty() << "\n"; // comes back false

	word.erase(true); word.print(); // remove front B
	word.erase(false); word.print(); // remove back

	cout << "empty(): " << word.empty() << "\n"; // should be true
	cout << "first() on empty: " << (word.first() == '\0') << "\n";
	cout << "last() on empty: " << (word.last() == '\0') << "\n";

	return 0;
}