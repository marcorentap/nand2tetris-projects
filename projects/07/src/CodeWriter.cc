#include "CodeWriter.h"

void CodeWriter::setFileName(std::string fileName) {
    fileName_ = fileName;
}

void CodeWriter::writeArithmetic(std::string command) {
    file_ << command << std::endl;
}

void CodeWriter::writePushPop(std::string command, std::string segment, std::string index) {
    file_ << command << " " << segment << " " << index << std::endl;
}

void CodeWriter::close() {
    file_.close();
}
