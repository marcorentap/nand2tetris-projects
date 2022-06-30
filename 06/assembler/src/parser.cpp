#include <algorithm>
#include <cctype>
#include "parser.h"
#include <iostream>

namespace NAND2Tetris::Assembler {
Parser::Parser(std::ifstream &f) : file(f) {
    command.resize(buffer_size);
}

std::string Parser::getCommand() {
    return command;
}

bool Parser::hasMoreCommands() {
    return file.peek() != EOF;
}

void Parser::advance() {
    if(hasMoreCommands()) {
        std::getline(file, command);
        // Strip whitespaces
        command.erase(remove_if(command.begin(), command.end(), ::isspace), command.end());
        // Strip comments
        size_t comment_pos = command.find("//");
        if(comment_pos != std::string::npos) {
            command.erase(comment_pos, command.length() - comment_pos);
        }
        // Skip empty lines
        if(command.length() == 0) {
            advance();
        }
    }
}

Parser::CommandType Parser::commandType() {
    switch(command[0]) {
        case '@':
            return A_COMMAND;
        case '(':
            return L_COMMAND;
        default:
            return C_COMMAND;
    }
}

std::string Parser::symbol() {
    switch (commandType()) {
        case(A_COMMAND):
            return command.substr(1, command.size() - 1);
        case(L_COMMAND):
            return command.substr(1, command.size() - 2);
        default:
            throw std::logic_error("Invalid command type.");
            break;
    }
}

/*
 * dest=comp;jump
 * If dest is empty, the "=" is omitted
 * If jump is empty, the ";" is omitted
 */

std::string Parser::dest() {
    size_t eq = command.find('=');
    if(eq != std::string::npos) {
        return command.substr(0, eq);
    } else {
        return "";
    }
}

std::string Parser::comp() {
    size_t eq = command.find('=');
    size_t semi = command.find(';');
    
    if(eq != std::string::npos) {
        return command.substr(eq + 1, command.length() - eq - 1);
    } else if (semi != std::string::npos) {
        return command.substr(0, semi);
    } else {
        return "";
    }
}

std::string Parser::jump() {
    size_t semi = command.find(';');
    
    if (semi != std::string::npos) {
        return command.substr(semi + 1, command.length() - semi - 1);
    } else {
        return "";
    }
}
};