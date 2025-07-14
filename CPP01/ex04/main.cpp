#include <iostream>
#include <fstream>
#include <sstream>

static bool replaceInString(const std::string& s1, const std::string& s2, std::string& content) {
	if (s1.empty())
		return false;

	std::string result;
	size_t pos = 0;
	size_t found;

	while ((found = content.find(s1, pos)) != std::string::npos) {
		result.append(content, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(content, pos, content.length() - pos);
	content = result;
	return true;
}

int main(int argc, char** argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::ifstream ifs(filename.c_str());
	if (!ifs) {
		std::cerr << "Error: cannot open file '" << filename << "' for reading." << std::endl;
		return 1;
	}

	std::ostringstream oss;
	oss << ifs.rdbuf();
	std::string content = oss.str();

	if (!replaceInString(s1, s2, content)) {
		std::cerr << "Error: s1 is empty, cannot replace." << std::endl;
		return 1;
	}

	std::string outFilename = filename + ".replace";
	std::ofstream ofs(outFilename.c_str());
	if (!ofs) {
		std::cerr << "Error: cannot open file '" << outFilename << "' for writing." << std::endl;
		return 1;
	}

	ofs << content;

	return 0;
}
