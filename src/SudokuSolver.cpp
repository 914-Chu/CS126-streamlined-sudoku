#include "SudokuSolver.h"
#include "iostream"
#include <vector>

using namespace std;

ostream& operator<< (ostream& output, const SudokuBoard& board) {

    for(const auto &row : board.boardState_){
        for(const auto &element : row){
            output << element << "|";
        }
        output << endl;
        for(unsigned int i = 0; i < board.kSideLength; i ++){
            output << "__ ";
        }
        output<< endl;
    }
    return output;
}

istream& operator>> (istream& input, SudokuBoard& board) {
    string line;
    input >> line;
    board.boardState = board.setUpBoard(line);
    return input;
}

vector<vector<int>> SudokuBoard::setUpBoard(const string &str) {

    vector<vector<int>> state(kSideLength, vector<int>(kSideLength, 0));
    for(unsigned int row = 0; row < kSideLength; row++){
        for(unsigned int col = 0; col < kSideLength; col++){
            char character = str[static_cast<unsigned int>(kSideLength * row + col)];
            if(isdigit(character) && character != '0'){
                int num = character - '0';
                state[row][col] = num;
            }
        }
    }
    return state;
}

void SudokuBoard::setNumber(Cell current, int value) {
    boardState_[current.getRow()][current.getCol()] = value;
}

Cell::Cell(int row, int col) {

    this->row_ = row;
    this->col_ = col;
}

Cell Cell::getNextCell(Cell current) {

    int row = current.getRow();
    int col = current.getCol();

    row ++;
    col ++;

    if(row >= kSideLength){
        row = -1;
    }else if(col >= kSideLength){
        col = 0;
    }
    Cell next(row, col);
    return next;
}

namespace solver{

bool solve(SudokuBoard board){

    Cell start(0,0);
    return solve(board, start);
}

bool solve(SudokuBoard board, Cell current){

    if(current.getRow() == -1){
        return true;
    }else if()
}

}
