#include "iostream"
#include <fstream>


std::string replaceString(std::string str, const std::string& oldStr, const std::string& newStr) {
    size_t pos = 0;
    while ((pos = str.find(oldStr, pos)) != std::string::npos) {
        str.erase(pos, oldStr.length());
        str.insert(pos, newStr);
        pos += newStr.length();
    }
		return str;
}

int main(int argc, char **argv)
{
	if(argc != 4)
	{
		std::cout << "WRONG ARGUMENTS" << std::endl;
		exit(1);
	}
	std::ifstream readFile(argv[1]);
	if(!readFile.is_open())
	{
		std::cout << "WRONG FILE NAME" << std::endl;
		exit(1);
	}
	std::string ext=".replace";
	std::ofstream writeFile(argv[1]+ext);
	std::string line;
	while (std::getline(readFile, line)) {
		writeFile << replaceString(line, argv[2], argv[3]);
		writeFile << std::endl;
	}
	return (0);
}