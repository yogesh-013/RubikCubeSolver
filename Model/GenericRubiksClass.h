//
// Created by Yogesh Paneru on 26-06-2025.
//
#include<bits/stdc++.h>

using namespace std ;
#ifndef GENERICRUBIKSCLASS_H
#define GENERICRUBIKSCLASS_H

class GenericRubiksClass {
    public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum class COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum class MOVE {
        L, LPRIME, L2,
        R, RPRIME, R2,
        U, UPRIME, U2,
        D, DPRIME, D2,
        F, FPRIME, F2,
        B, BPRIME, B2
    };

    /*
     * Returns the color of the cell at (row, col) in face.
     * If Rubik's Cube face is pointing at you, then the row numbering starts from the
     * top to bottom, and column numbering starts from the left to right.
     * The rows and columns are 0-indexed.
     * @param Face, row, and column index
     */
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    /*
     * Returns the first letter of the given COLOR
     * Eg: For COLOR::GREEN, it returns 'G'
     */
    static char getColorLetter(COLOR color);

    /*
     * Returns true if the Rubik Cube is solved, otherwise returns false.
     */
    virtual bool isSolved() const = 0;

    /*
     * Returns the move in the string format.
     */
    static string getMove(MOVE ind);

    /*
     * Print the Rubik Cube in Planar format.
     *
     * The cube is laid out as follows.
     *
     * The sides:
     *    U
     *  L F R B
     *    D
     *
     * Color wise:
     *
     *          W W W
     *          W W W
     *          W W W
     *
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *  G G G   R R R   B B B   O O O
     *
     *          Y Y Y
     *          Y Y Y
     *          Y Y Y
     *
     * Row and Column Numberings:
     * rx -> row numbering
     * cx -> column numbering
     * bx -> both row and column numbering
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     *  b0 c1 c2   b0 c1 c2   b0 c1 c2   b0 c1 c2
     *  r1  .  .   r1  .  .   r1  .  .   r1  .  .
     *  r2  .  .   r2  .  .   r2  .  .   r2  .  .
     *
     *             b0 c1 c2
     *             r1  .  .
     *             r2  .  .
     *
     */
    void print() const;

    /*
     * Randomly shuffle the cube with 'times' moves and returns the moves performed.
     */
    vector<MOVE> randomShuffleCube(unsigned int times);

    /*
     * Perform moves on the Rubik Cube
     */
    GenericRubiksClass &move(MOVE ind);

    /*
     * Invert a move
     */
    GenericRubiksClass &invert(MOVE ind);

    /*
     * Rotational Moves on the Rubik Cubes
     *
     * F, F’, F2,
     * U, U’, U2,
     * L, L’, L2,
     * D, D’, D2,
     * R, R’, R2,
     * B, B’, B2
     */

    virtual GenericRubiksClass &f() = 0;

    virtual GenericRubiksClass &fPrime() = 0;

    virtual GenericRubiksClass &f2() = 0;

    virtual GenericRubiksClass &u() = 0;

    virtual GenericRubiksClass &uPrime() = 0;

    virtual GenericRubiksClass &u2() = 0;

    virtual GenericRubiksClass &l() = 0;

    virtual GenericRubiksClass &lPrime() = 0;

    virtual GenericRubiksClass &l2() = 0;

    virtual GenericRubiksClass &r() = 0;

    virtual GenericRubiksClass &d() = 0;

    virtual GenericRubiksClass &dPrime() = 0;

    virtual GenericRubiksClass &d2() = 0;

    virtual GenericRubiksClass &rPrime() = 0;

    virtual GenericRubiksClass &r2() = 0;

    virtual GenericRubiksClass &b() = 0;

    virtual GenericRubiksClass &bPrime() = 0;

    virtual GenericRubiksClass &b2() = 0;

    string getCornerColorString(uint8_t ind) const;

    uint8_t getCornerIndex(uint8_t ind) const;

    uint8_t getCornerOrientation(uint8_t ind) const;
};



#endif //GENERICRUBIKSCLASS_H
