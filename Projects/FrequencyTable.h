#ifndef FREQUENCYTABLE_H
#define FREQUENCYTABLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
#include "Object.h"
#include "Pair.h"

class FrequencyTable : public aap::Object {

private:
	Pair* table;
	int size;

public:

	FrequencyTable() : table(nullptr), size(0) {}

	~FrequencyTable() {
		delete[] table;
		table = nullptr;
	}

	void loadFile(const std::string& filename) {

		delete[] table;
		table = nullptr;
		size = 0;

		std::ifstream in(filename);
		if (!in) return;

		int freq[256] = { 0 };

		char orderList[256] = { 0 };
		bool seen[256] = { false };
		int orderCount = 0;

		char ch;
		while (in.get(ch)) {

			if (std::isalpha(ch)) {
				ch = std::tolower(ch);
			}

			unsigned char c = static_cast<unsigned char>(ch);
			if (c <= 32 || c == 127) {
				continue;
			}

			freq[c]++;

			if (!seen[c]) {
				seen[c] = true;
				orderList[orderCount++] = c;
			}
		}

		in.close();

		size = orderCount;
		table = new Pair[size];

		for (int i = 0; i < size; i++) {
			unsigned char c = static_cast<unsigned char>(orderList[i]);
			std::string key(1, c);
			table[i] = Pair(key, freq[c]);
		}

		int maxFreq = 0;
		for (int i = 0; i < size; i++) {
			int f = table[i].getValue();
			if (f > maxFreq) {
				maxFreq = f;
			}
		}

		int* countArr = new int[maxFreq + 1];
		for (int i = 0; i <= maxFreq; i++) {
			countArr[i] = 0;
		}

		for (int i = 0; i < size; i++) {
			int f = table[i].getValue();
			countArr[f]++;
		}

		for (int i = 1; i < maxFreq; i++) {
			countArr[i] += countArr[i - 1];
		}

		Pair* sorted = new Pair[size];

		for (int i = size - 1; i >= 0; i--) {
			int f = table[i].getValue();
			int pos = countArr[f] - 1;
			sorted[pos] = table[i];
			countArr[f]--;
		}

		delete[] countArr;
		delete[] table;
		table = sorted;
	}

	int getSize() const {
		return size;
	}

	Pair* getTable() const {
		return table;
	}

	std::string toString() const override {
		std::stringstream out;

		for (int i = 0; i < size; i++) {
			out << table[i];
			if (i < size - 1) {
				out << " ";
			}
		}

		return out.str();
	}


};
#endif // !FREQUENCYTABLE_H
