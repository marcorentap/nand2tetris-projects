// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

(LOOP) // Infinite Loop
    @KBD
    D=M
    @WRITE_WHITE // Write white if KBD word is 0
    D;JEQ
    @WRITE_BLACK // Write black if KBD word is not 0
    D;JNE

    (WRITE_WHITE)
        @val
        M=0
        @WRITE
        0;JMP

    (WRITE_BLACK)
        @val
        M=-1
        @WRITE
        0;JMP

    (WRITE) // Write function
        @SCREEN
        D=A
        @index // Pixel word index
        M=D
        @i
        M=0
        (WRITE_LOOP) // Loop over all screen 8K memory map
            // Check if i < 8192 (8192 - i > 0)
            @8192
            D=A
            @i
            D=D-M
            @LOOP
            D;JLE

            // index = screen + i
            @SCREEN
            D=A
            @i
            D=D+M
            @index
            M=D

            // screen[i] index = val;
            @val
            D=M
            @index
            A=M
            M=D

            // i++
            @i
            M=M+1
            @WRITE_LOOP
            0;JMP
@LOOP
0;JMP