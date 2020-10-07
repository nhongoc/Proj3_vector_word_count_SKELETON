#include "../includes/fileio.h"
using namespace std;

bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode = std::ios_base::in) {
	myfile.open(myFileName.c_str(), mode);
	if (!myfile.is_open()) {
		return false;
	}
	return true;
}

void closeFile(std::fstream& myfile) {
	if (myfile.is_open()) {
		myfile.close();
	}
}

int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename) {
	ofstream myOutputfile;
	myOutputfile.open(outputfilename);
	if (!myOutputfile.is_open()) {
		return constants::FAIL_FILE_DID_NOT_OPEN;
	}
	for (unsigned int i = 0; i < entries.size(); i++) {
		myOutputfile << entries[i].word << " " << entries[i].number_occurences << endl;
	}
	myOutputfile.close();
	return constants::SUCCESS;
}
