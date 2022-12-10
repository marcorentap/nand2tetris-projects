#include "../src/assembler.h"
#include <iostream>
using namespace std;
using namespace NAND2Tetris::Assembler;

int main() {
    ifstream inFile("test/test files/pong/Pong.asm");
    ofstream outFile("test/test files/pong/Pong_test.hack");

    Assembler assembler(inFile, outFile);
    assembler.assemble();
    inFile.close();
    outFile.close();

    ifstream outputFile("test/test files/pong/Pong_test.hack");
    ifstream testFile("test/test files/pong/Pong.hack");
    string outString, testString;
    int lineCounter = 1;
    while(outputFile.peek() != EOF && testFile.peek() != EOF) {
        getline(outputFile, outString);
        getline(testFile, testString);
        cout << "OUT: " << outString << "\tTEST: " << testString;
        if(outString != testString) {
            cout << "\tERROR: Line " << lineCounter << endl;
            lineCounter++;
        } else {
            cout << "\tSUCCESS" << endl;
        }
    }
    return 0;
}