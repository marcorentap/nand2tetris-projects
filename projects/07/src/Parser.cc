#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Parser.h"

#define LINE_BUFFER_SIZE 4096

bool Parser::hasMoreCommands() {
    return !file_.eof();
}

void Parser::advance() {
    line_buffer.clear();
    tokens.clear();
    if (hasMoreCommands()) {
        // Reset current line info
        std::getline(file_, line_buffer);

        // Remove comments
        auto slashIdx = line_buffer.find('/');
        if (slashIdx != std::string::npos) {
            line_buffer = line_buffer.substr(0, slashIdx);
        }

        // Extract tokens
        std::istringstream line_is(line_buffer);
        if (line_buffer.size() != 0) {
            std::string token;
            while (line_is >> token) {
                tokens.push_back(token);
            }

            std::cout << "HERE" << std::endl;
        } else {
            // Ignore empty line, after removing comments
            advance();
        }
    }
}

CommandType Parser::commandType() {
    return command_types_.find(tokens[0])->second;
}

std::string Parser::arg1() {
    if (commandType() == CommandType::C_ARITHMETIC)
        return tokens[0];
    else
        return tokens[1];
}

int Parser::arg2() {
    return std::stoi(tokens[2]);
}
