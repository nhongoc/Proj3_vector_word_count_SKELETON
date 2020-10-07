#include "../includes/fileio.h"
#include "../includes/utilities.h"
using namespace std;

bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode) {
	myfile.open(myFileName.c_str(), mode);
	return does_file_exist(myFileName);
}

void closeFile(std::fstream& myfile) {
	if (myfile.is_open()) {
		myfile.close();
	}
}

int writetoFile(std::vector<constants::entry>  &entries, const std::string &outputfilename) {
	fstream myOutputfile;
	openFile(myOutputfile, outputfilename, std::ios_base::out);
	for (unsigned int i = 0; i < entries.size(); i++) {
		myOutputfile << entries[i].word << " " << intToString(entries[i].number_occurences) << endl;
	}
	closeFile(myOutputfile);
	return constants::SUCCESS;
}
