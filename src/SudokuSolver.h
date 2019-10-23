#pragma once
#include "iostream"
#include <vector>

using namespace std;

class Cell {

private:
    const unsigned int kSideLength = 9;
    unsigned int row_,
                 col_;
public:
    Cell(){};
    Cell(unsigned int,unsigned int);
    ~Cell(){};
    unsigned int getRow() {return row_;};
    unsigned int getCol() {return col_;};
    Cell getNextCell(Cell);
};


class SudokuBoard {

private:
    const unsigned int kSideLength = 9;
    const unsigned int kSubSideLength = 3;
    const unsigned int kUnassignedCell = 0;
    const char kZero = '0';
    vector<vector<int>> boardState_;

public:
     SudokuBoard();
    ~SudokuBoard() {};

    void setUpBoard(const string&);
    void setValue(Cell,int);
    int getValue(Cell);
    int getValue(unsigned int, unsigned int);
    vector<vector<int>> getBoardState(){return boardState_;};
    friend std::ostream& operator<<(std:: ostream&, const SudokuBoard&);
    friend std::istream& operator>>(std:: istream&, SudokuBoard&);
};

//std::ostream& operator<<(std:: ostream&, const SudokuBoard&);
//std::istream& operator>>(std:: istream&, SudokuBoard&);

namespace solver{

    const unsigned int kSideLength = 9;
    const unsigned int kSubSideLength = 3;
    const unsigned int kUnassignedCell = 0;

    bool solve(SudokuBoard);
    bool solve(SudokuBoard,Cell);
    bool isValidValue(SudokuBoard, Cell, int);
    Cell findTopLeftCornerCell(Cell);
}

