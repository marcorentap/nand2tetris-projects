#include "symboltable.h"
#include <stdexcept>

namespace NAND2Tetris::Assembler {
    SymbolTable::SymbolTable() {
        table = std::unordered_map<std::string, int> {
            {"SP", 0}, {"LCL", 1}, {"ARG", 2}, {"THIS", 3}, {"THAT", 4},
            {"R0", 0}, {"R1", 1}, {"R2", 2}, {"R3", 3}, {"R4", 4},
            {"R5", 5}, {"R6", 6}, {"R7", 7}, {"R8", 8}, {"R9", 9},
            {"R10", 10}, {"R11", 11}, {"R12", 12}, {"R13", 13}, {"R14", 14},
            {"R15", 15}, {"SCREEN", 16384}, {"KBD", 24576}
        };
    }

    void SymbolTable::addEntry(std::string symbol, int address) {
        std::pair<std::string, int> entry(symbol, address);
        table.insert(entry);
    }

    bool SymbolTable::contains(std::string symbol) {
        return table.count(symbol) > 0;
    }

    int SymbolTable::getAddress(std::string symbol) {
        if(contains(symbol)) {
            std::unordered_map<std::string, int>::iterator entry = table.find(symbol);
            return entry->second;
        } else {
            throw std::invalid_argument("The symbol does not exist");
        }
    }
}