#include "../includes/fileio.h"
#include "../includes/utilities.h"
using namespace std;

bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode) {
	myfile.open(myFileName, mode);
	if (myfile.is_open()) {
		return true;
	}
	return false;
}

void closeFile(std::fstream& myfile) {
	if (myfile.is_open()) {
		myfile.close();
	}
}

int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename) {
	fstream myOutputfile;
	openFile(myOutputfile, outputfilename, std::ios_base::out);
	if (!myOutputfile.is_open()) {
		return constants::FAIL_FILE_DID_NOT_OPEN;
	}
	if (entries.size() == 0) {
		return constants::FAIL_NO_ARRAY_DATA;
	}
	for (unsigned int i = 0; i < entries.size(); i++) {
		myOutputfile << entries[i].word << " " << intToString(entries[i].number_occurences) << endl;
	}
	closeFile(myOutputfile);
	return constants::SUCCESS;
}
