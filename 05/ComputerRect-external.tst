// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/05/ComputerRect-external.tst

load Computer.hdl,
output-file ComputerRect-external.out,
compare-to ComputerRect-external.cmp,
output-list time%S1.4.1;

// Load a program written in the Hack machine language.
// The program draws a rectangle of width 16 pixels and 
// length RAM[0] at the top left of the screen.
ROM32K load custom_fill.hack;

repeat 1000000 {
    tick, tock, output;
}
