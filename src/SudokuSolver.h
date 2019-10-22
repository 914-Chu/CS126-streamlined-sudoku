#pragma once
#include "iostream"
#include <vector>

using namespace std;

class Cell {

private:
    const int kSideLength = 9;
    int row_,
            col_;
public:
    Cell(){};
    Cell(int,int);
    ~Cell(){};
    int getRow() {return row_;};
    int getCol() {return col_;};
    Cell getNextCell(Cell);
};


class SudokuBoard {

private:
    const unsigned int kSideLength = 9;
    const unsigned int kUnassignedCell = 0;
    vector<vector<int>> boardState_;

public:
    SudokuBoard() {};
    ~SudokuBoard() {};

    vector<vector<int>> setUpBoard(const string&);
    void setNumber(Cell,int);
    friend std::ostream& operator<<(std:: ostream&, const SudokuBoard&);
    friend std::istream& operator>>(std:: istream&, SudokuBoard&);
};

namespace solver{

    bool solve(SudokuBoard);
    bool solve(SudokuBoard,Cell);
}

