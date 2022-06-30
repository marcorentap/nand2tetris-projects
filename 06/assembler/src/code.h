#ifndef NAND2TETRIS_CODE_H
#define NAND2TETRIS_CODE_H

#include <bitset>
#include <string>

namespace NAND2Tetris::Assembler {
    class Code {
        public:
            std::bitset<3> dest(std::string);
            std::bitset<7> comp(std::string);
            std::bitset<3> jump(std::string);
    };
}

#endif