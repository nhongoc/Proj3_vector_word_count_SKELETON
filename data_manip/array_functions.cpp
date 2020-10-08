#include <algorithm>
#include "../includes/array_functions.h"
#include "../includes/utilities.h"
#include "../includes/fileio.h"

using namespace std;

bool compareAscending(const constants::entry& entry1, const constants::entry& entry2) {
	return entry1.word < entry2.word;
}

bool compareDescending(const constants::entry& entry1, const constants::entry& entry2) {
	return entry1.word > entry2.word;
}

bool compareNumberOccurences(const constants::entry& entry1, const constants::entry& entry2) {
	return entry1.number_occurences > entry2.number_occurences;
}

void KP::clear(std::vector<constants::entry>  &entries) {
	entries.clear();
}

int KP::getSize(std::vector<constants::entry>  &entries) {
	return entries.size();
}

std::string KP::getWordAt(std::vector<constants::entry>  &entries, int i) {
	return entries[i].word;
}

int KP::getNumbOccurAt(std::vector<constants::entry>  &entries,int i) {
	return entries[i].number_occurences;
}

bool KP::processFile(std::vector<constants::entry>  &entries,std::fstream &myfstream) {
	if (myfstream.is_open()) {
		string line;
		while (!myfstream.eof()) {
			getline(myfstream, line);
			processLine(entries, line);
		}
		closeFile(myfstream);
		return true;
	}
	return false;
}

void KP::processLine(std::vector<constants::entry>  &entries,std::string &myString) {
	stringstream ss(myString);
	string word;
	while (getline(ss, word, constants::CHAR_TO_SEARCH_FOR)) {
		processToken(entries, word);
	}
}

void KP::processToken(std::vector<constants::entry>  &entries,std::string &token) {
	constants::entry newEntry;
	strip_unwanted_chars(token);
	string wordUpper = token;
	toUpper(wordUpper);
	for (unsigned int i = 0; i < entries.size(); i++) {
		if (entries[i].word_uppercase == wordUpper) {
			entries[i].number_occurences += 1;
			return;
		}
	}
	if (token != "") {
		newEntry.word = token;
		newEntry.number_occurences = 1;
		newEntry.word_uppercase = wordUpper;
		entries.push_back(newEntry);
	}
}

void KP::sort(std::vector<constants::entry>  &entries, constants::sortOrder so) {
	switch(so) {
	case constants::ASCENDING:
		sort(entries.begin(), entries.end(), compareAscending);
		break;
	case constants::DESCENDING:
		sort(entries.begin(), entries.end(), compareDescending);
		break;
	case constants::NONE:
		break;
	case constants::NUMBER_OCCURRENCES:
		sort(entries.begin(), entries.end(), compareNumberOccurences);
		break;
	}
}
