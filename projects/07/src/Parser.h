#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

// For docs, see section 7.3.3, page 144
// Or really, the entire chapter
enum class CommandType {
    C_ARITHMETIC,
    C_PUSH,
    C_POP,
    C_LABEL,
    C_GOTO,
    C_IF,
    C_FUNCTION,
    C_RETURN,
    C_CALL
};

class Parser {
    private:
        std::ifstream& file_;
        std::string line_buffer;
        std::vector<std::string> tokens;
        std::unordered_map<std::string, CommandType> command_types_ = {
            {"add", CommandType::C_ARITHMETIC},
            {"sub", CommandType::C_ARITHMETIC},
            {"neg", CommandType::C_ARITHMETIC},
            {"eq", CommandType::C_ARITHMETIC},
            {"gt", CommandType::C_ARITHMETIC},
            {"lt", CommandType::C_ARITHMETIC},
            {"and", CommandType::C_ARITHMETIC},
            {"or", CommandType::C_ARITHMETIC},
            {"not", CommandType::C_ARITHMETIC},

            {"push", CommandType::C_PUSH},
            {"pop", CommandType::C_POP},

            {"goto", CommandType::C_GOTO},
            {"if", CommandType::C_IF},
            {"label", CommandType::C_LABEL},
            {"function", CommandType::C_FUNCTION},
            {"call", CommandType::C_CALL},
            {"return", CommandType::C_RETURN}
        };

    public:
        Parser(std::ifstream& file) : file_(file) {};
        bool hasMoreCommands();
        void advance();
        CommandType commandType();
        std::string arg1();
        int arg2();
};
#endif
