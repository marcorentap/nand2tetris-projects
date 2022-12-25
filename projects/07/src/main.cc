#include <fstream>
#include <ios>
#include <iostream>
#include "Parser.h"

int main() {
    std::string filename;
//std::getline(std::cin, filename);
    filename = "../StackArithmetic/SimpleAdd/SimpleAdd.vm";

    std::ifstream file(filename);
    Parser parser(file);
    while (parser.hasMoreCommands()) {
        parser.advance();
    }
    return 0;
}
