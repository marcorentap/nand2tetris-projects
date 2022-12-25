#ifndef CODEWRITER_H
#define CODEWRITER_H

#include <fstream>
#include <string>

class CodeWriter {
    private:
        std::ofstream& file_;
        std::string fileName_;
    public:
        CodeWriter(std::ofstream& file) : file_(file) {};
        void setFileName(std::string fileName);
        void writeArithmetic(std::string command);
        void writePushPop(std::string command, std::string segment, std::string index);
        void close();
};
#endif
