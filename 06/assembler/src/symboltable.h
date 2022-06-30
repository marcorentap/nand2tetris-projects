#ifndef NAND2TETRIS_SYMBOLTABLE_H
#define NAND2TETRIS_SYMBOLTABLE_H
#include <unordered_map>

namespace NAND2Tetris::Assembler {
    class SymbolTable {
        private:
            std::unordered_map<std::string, int> table;
        public:
            SymbolTable();
            void addEntry(std::string, int);
            bool contains(std::string);
            int getAddress(std::string);
    };
}

#endif