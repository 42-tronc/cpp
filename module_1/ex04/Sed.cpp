#include "Sed.hpp"

Sed::Sed(std::string filename, std::string s1, std::string s2) {
    if (s1.empty()) {
        printError("s1 cannot be empty");
        return;
    }
    this->s1 = s1;
    this->s2 = s2;

    if (!openFile(filename)) {
        printError("could not open file");
        exit(1);
    }

    std::string newFilename = filename + ".replace";
    if (!writeFile(newFilename)) {
        printError("could not write to file");
        exit(1);
    }
}

bool Sed::openFile(std::string filename) {
    infile.open(filename.c_str());
    if (!infile.is_open()) return false;

    return true;
}

bool Sed::writeFile(std::string filename) {
    outfile.open(filename.c_str());
    if (!outfile.is_open()) return false;

    while (!infile.eof()) {
        std::string str;
        getline(infile, str);

        while (str.find(s1) != std::string::npos) {
            size_t pos = str.find(s1);

            str.erase(pos, s1.length());
            str.insert(pos, s2);
        }
        outfile << str << std::endl;
    }

    return true;
}

void printError(std::string msg) {
    std::cerr << "\e[31;1mError: \e[22m" << msg << "\e[0m" << std::endl;
}
