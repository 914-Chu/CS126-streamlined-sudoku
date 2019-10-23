#pragma once
#include "iostream"
#include <vector>

using namespace std;

/*
 * Keep track of each cell's location within a 9*9 board.
 */

class Cell {

private:
    const unsigned int kSideLength = 9;
    unsigned int row_,
                 col_;
public:
    //default constructor
    Cell(){};
    //constructor takes in arguments to create new Cell
    Cell(unsigned int,unsigned int);
    //destructor
    ~Cell(){};
    //get row's index
    unsigned int getRow() {return row_;};
    //get column's index
    unsigned int getCol() {return col_;};
    //get input cell's following cell
    //Cell(1,2) -> Cell(1,3) : Cell(1,8) -> Cell(2,0)
    Cell getNextCell(Cell);
};

/*
 * Stores a single Sudoko game.
 */

class SudokuBoard {

private:
    const unsigned int kSideLength = 9;
    const unsigned int kSubSideLength = 3;
    const unsigned int kUnassignedCell = 0;
    const char kZero = '0';
    vector<vector<int>> boardState_;

public:
    //default constructor
     SudokuBoard();
    //destructor
    ~SudokuBoard() {};
    //takes in the board state to set up the board in 2d vector
    void setUpBoard(const string&);
    //set the passed value to the passed location
    void setValue(Cell,int);
    //get value at certain location, takes in a Cell object
    int getValue(Cell);
    //@overload int getValue(unsigned int row, unsigned int col)
    int getValue(unsigned int, unsigned int);
    //return current board state
    vector<vector<int>> getBoardState(){return boardState_;};
    //@overload output operator
    friend std::ostream& operator<<(std:: ostream&, const SudokuBoard&);
    //@overload input operator
    friend std::istream& operator>>(std:: istream&, SudokuBoard&);
};

namespace solver{

    const unsigned int kSideLength = 9;
    const unsigned int kSubSideLength = 3;
    const unsigned int kUnassignedCell = 0;

    //method to start the solve method recursion.
    bool solve(SudokuBoard);
    //@overload bool solve(SudokuBoard board, Cell current)
    bool solve(SudokuBoard,Cell);
    //check if passed value is valid if put at certain location
    bool isValidValue(SudokuBoard, Cell, int);
    //find the location of the top left corner cell of the sub box that the passed cell is located.
    // here -> _ _ _
    //         _ _ _
    //         _ _ _
    Cell findTopLeftCornerCell(Cell);
}

