#ifndef NAND2TETRIS_ASSEMBLER_H
#define NAND2TETRIS_ASSEMBLER_H

#include "parser.h"
#include "code.h"
#include "symboltable.h"

namespace NAND2Tetris::Assembler {
    class AssemblerL {
        private:
            Parser* parser;
            Code code;
            std::ifstream &inFile;
            std::ostream &outFile;

        public:
            AssemblerL(std::ifstream&, std::ofstream&);
            void assemble();
    };

    class Assembler {
        private:
            Parser* parser;
            Code code;
            SymbolTable symboltable;
            std::ifstream &inFile;
            std::ostream &outFile;

        public:
            Assembler(std::ifstream&, std::ofstream&);
            void assemble();
    };
}

#endif