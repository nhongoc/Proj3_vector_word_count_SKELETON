#include "../includes/array_functions.h"
using namespace std;

void clear(std::vector<constants::entry>  &entries) {
	entries.clear();
}

int getSize(std::vector<constants::entry>  &entries) {
	return entries.size();
}

std::string getWordAt(std::vector<constants::entry>  &entries, int i) {
	return entries[i].word;
}

int getNumbOccurAt(std::vector<constants::entry>  &entries,int i) {
	return entries[i].number_occurences;
}

bool processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream) {
	if (!myfstream.is_open()) {
		return false;
	}
	string line;
	while (!myfstream.eof()) {
		getline(myfstream, line);
		KP::processLine(entries, line);
	}
	return true;
}

void processLine(std::vector<constants::entry>  &entries,std::string &myString) {
	string word = "";
	for (char x: myString) {
		if (x != constants::CHAR_TO_SEARCH_FOR || !ispunct(x)) {
			word += x;
		}
		else {
			KP::processToken(entries, word);
		}
	}
}

void processToken(std::vector<constants::entry>  &entries,std::string &token) {
	constants::entry newEntry;
	string wordUpper = token;
	for (int i = 0; i < wordUpper.length(); i++) {
		wordUpper[i] = toupper(wordUpper[i]);
	}
	for (constants::entry entry: entries) {
		if (entry.word_uppercase == wordUpper) {
			entry.number_occurences += 1;
		}
		else {
			newEntry.word = token;
			newEntry.word_uppercase = wordUpper;
			newEntry.number_occurences = 1;
			entries.push_back(newEntry);
		}
	}
}

void sort(std::vector<constants::entry>  &entries, constants::sortOrder so) {
	switch(so) {
	case constants::ASCENDING:
		std::sort(entries.begin(), entries.end());
		break;
	case constants::DESCENDING:
		std::sort(entries.begin(), entries.end());
		std::reverse(entries.begin(), entries.end());
		break;
	case constants::NONE:
		break;
	case constants::NUMBER_OCCURRENCES:
		std::sort(entries.begin(), entries.end());
		break;
	}
}
