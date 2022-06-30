#ifndef NAND2TETRIS_PARSER_H
#define NAND2TETRIS_PARSER_H

#include <fstream>

#define BUFFER_SIZE 512

namespace NAND2Tetris::Assembler {
    class Parser {
        private:
            std::ifstream &file;
            const size_t buffer_size = BUFFER_SIZE / sizeof(char);
            std::string command = "";

        public:
            typedef enum {A_COMMAND, C_COMMAND, L_COMMAND} CommandType;
            Parser(std::ifstream&);
            bool hasMoreCommands();
            void advance();
            CommandType commandType();
            std::string getCommand();
            std::string symbol();
            std::string dest();
            std::string comp();
            std::string jump();
    };
}

#endif