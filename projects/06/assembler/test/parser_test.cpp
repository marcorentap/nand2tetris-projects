#include <iostream>
#include "../src/parser.h"

using namespace std;
using namespace NAND2Tetris::Assembler;

int main() {
    ifstream file("test/test files/max/MaxL.asm");
    Parser parser = Parser(file);

    while(parser.hasMoreCommands()) {
        parser.advance();
        cout << parser.getCommand() << endl;
        cout << "commandType: " << parser.commandType() << endl;
        if(parser.commandType() == Parser::A_COMMAND
        || parser.commandType() == Parser::L_COMMAND) {
            cout << "symbol: " << parser.symbol() << endl;
        } else {
            cout << "dest: " << parser.dest() << endl;
            cout << "comp: " << parser.comp() << endl;
            cout << "jump: " << parser.jump() << endl;
        }
        cout << endl;
    }

    file.close();

    return 0;
}