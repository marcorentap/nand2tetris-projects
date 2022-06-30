#include "assembler.h"
#include <iostream>

namespace NAND2Tetris::Assembler {
    bool isNumber(const std::string& s) {
        std::string::const_iterator iterator = s.begin();
        while(iterator != s.end()) {
            if(!std::isdigit(*iterator)) {
                return false;
            }
            iterator++;
        }
        return true;
    }

    AssemblerL::AssemblerL(std::ifstream &in, std::ofstream &out) : inFile(in), outFile(out) {
        parser = new Parser(inFile);
    }

    void AssemblerL::assemble() {
        while(parser->hasMoreCommands()) {
            std::string binaryCode = "";
            parser->advance();
            if (parser->commandType() == Parser::A_COMMAND) {
                binaryCode.append("0");
                std::string bSymbol = std::bitset<15>(stoi(parser->symbol())).to_string();
                binaryCode.append(bSymbol);
            } else if (parser->commandType() == Parser::C_COMMAND){
                binaryCode.append("111");
                binaryCode.append(code.comp(parser->comp()).to_string());
                binaryCode.append(code.dest(parser->dest()).to_string());
                binaryCode.append(code.jump(parser->jump()).to_string());
            } else {
                throw std::runtime_error("Symbol-less assembler is incompatible with L-Commands");
            }

            outFile << binaryCode << std::endl;
        }
    }

    Assembler::Assembler(std::ifstream &in, std::ofstream &out) : inFile(in), outFile(out), symboltable(SymbolTable()){
        parser = new Parser(inFile);
    }

    void Assembler::assemble() {
        // First pass, generate symbol table
        int ROMAddr = 0;
        while(parser->hasMoreCommands()) {
            parser->advance();
            if(parser->commandType() == Parser::A_COMMAND
            || parser->commandType() == Parser::C_COMMAND) {
                ROMAddr++;
            } else {
                symboltable.addEntry(parser->symbol(), ROMAddr);
            }
        }

        inFile.clear(); // Clear EOF bit
        inFile.seekg(0); // Back to beginning of file
        int RAMAddr = 16;
        while(parser->hasMoreCommands()) {
            std::string binaryCode = "";
            parser->advance();
            if (parser->commandType() == Parser::A_COMMAND) {
                binaryCode.append("0");
                std::string bSymbol;

                if(isNumber(parser->symbol())) {
                    bSymbol = std::bitset<15>(stoi(parser->symbol())).to_string();
                } else {
                    if(!symboltable.contains(parser->symbol())) {
                        symboltable.addEntry(parser->symbol(), RAMAddr);
                        RAMAddr++;
                    }
                    bSymbol = std::bitset<15>(symboltable.getAddress(parser->symbol())).to_string();
                }
                binaryCode.append(bSymbol);
            } else if (parser->commandType() == Parser::C_COMMAND){
                binaryCode.append("111");
                binaryCode.append(code.comp(parser->comp()).to_string());
                binaryCode.append(code.dest(parser->dest()).to_string());
                binaryCode.append(code.jump(parser->jump()).to_string());
            }

            if(parser->commandType() != Parser::L_COMMAND) {
                outFile << binaryCode << std::endl;
            }
        }

    }
}