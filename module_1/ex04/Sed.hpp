#ifndef SED_H
#define SED_H

#include <cstdlib>
#include <fstream>
#include <iostream>

class Sed {
public:
    Sed(std::string filename, std::string s1, std::string s2);

    bool openFile(std::string filename);
    bool writeFile(std::string filename);

private:
    std::fstream infile;
    std::ofstream outfile;
    std::string s1;
    std::string s2;
};

void printError(std::string msg);

#endif
