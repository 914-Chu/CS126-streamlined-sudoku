#pragma once
#include "iostream"
#include <vector>

using namespace std;

class SudokuBoard {

private:
    const unsigned int kSideLength = 9;
    const unsigned int kUnassignedCell = 0;
    vector<vector<int>> boardState;

public:
    SudokuBoard();
    ~SudokuBoard() {};

    vector<vector<int>> setUpBoard(const string&);
    bool isValidNumber(char);
    friend std::ostream& operator<<(std:: ostream&, const SudokuBoard&);
    friend std::istream& operator>>(std:: istream&, SudokuBoard&);
};

namespace solver{

}

