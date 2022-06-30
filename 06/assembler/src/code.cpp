#include "code.h"
#include <stdexcept>

namespace NAND2Tetris::Assembler {
    std::bitset<3> Code::dest(std::string mnemonic) {
        if(mnemonic == "") {
            return 0b000;
        } else if(mnemonic == "M") {
            return 0b001;
        } else if(mnemonic == "D") {
            return 0b010;
        } else if(mnemonic == "MD") {
            return 0b011;
        } else if(mnemonic == "A") {
            return 0b100;
        } else if(mnemonic == "AM") {
            return 0b101;
        } else if(mnemonic == "AD") {
            return 0b110;
        } else if(mnemonic == "AMD") {
            return 0b111;
        } else {
            throw std::invalid_argument("Invalid dest mnemonic");
        }
    };

    std::bitset<7> Code::comp(std::string mnemonic) {
        if(mnemonic == "0") {
            return 0b0101010;
        } else if(mnemonic == "1") {
            return 0b0111111; 
        } else if(mnemonic == "-1") {
            return 0b0111010; 
        } else if(mnemonic == "D") {
            return 0b0001100; 
        } else if(mnemonic == "A") {
            return 0b0110000; 
        } else if(mnemonic == "!D") {
            return 0b0001101; 
        } else if(mnemonic == "!A") {
            return 0b0110001; 
        } else if(mnemonic == "-D") {
            return 0b0001111; 
        } else if(mnemonic == "-A") {
            return 0b0110011; 
        } else if(mnemonic == "D+1") {
            return 0b0011111; 
        } else if(mnemonic == "A+1") {
            return 0b0110111; 
        } else if(mnemonic == "D-1") {
            return 0b0001110; 
        } else if(mnemonic == "A-1") {
            return 0b0110010; 
        } else if(mnemonic == "D+A") {
            return 0b0000010; 
        } else if(mnemonic == "D-A") {
            return 0b0010011; 
        } else if(mnemonic == "A-D") {
            return 0b0000111; 
        } else if(mnemonic == "D&A") {
            return 0b0000000; 
        } else if(mnemonic == "D|A") {
            return 0b0010101;
        }
        
        else if(mnemonic == "M") {
            return 0b1110000;
        } else if(mnemonic == "!M") {
            return 0b1110001;
        } else if(mnemonic == "-M") {
            return 0b1110011;
        } else if(mnemonic == "M+1") {
            return 0b1110111;
        } else if(mnemonic == "M-1") {
            return 0b1110010;
        } else if(mnemonic == "D+M") {
            return 0b1000010;
        } else if(mnemonic == "D-M") {
            return 0b1010011;
        } else if(mnemonic == "M-D") {
            return 0b1000111;
        } else if(mnemonic == "D&M") {
            return 0b1000000;
        } else if(mnemonic == "D|M") {
            return 0b1010101;

        } else {
            throw std::invalid_argument("Invalid comp mnemonic");
        }
    };

    std::bitset<3> Code::jump(std::string mnemonic) {
        if(mnemonic == "") {
            return 0b000;
        } else if(mnemonic == "JGT") {
            return 0b001;
        } else if(mnemonic == "JEQ") {
            return 0b010;
        } else if(mnemonic == "JGE") {
            return 0b011;
        } else if(mnemonic == "JLT") {
            return 0b100;
        } else if(mnemonic == "JNE") {
            return 0b101;
        } else if(mnemonic == "JLE") {
            return 0b110;
        } else if(mnemonic == "JMP") {
            return 0b111;
        } else {
            throw std::invalid_argument("Invalid jump mnemonic");
        }
    };
}