#include "SudokuSolver.h"
#include <iostream>
#include <vector>

using namespace std;


Cell::Cell(unsigned int row, unsigned int col) {

    this->row_ = row;
    this->col_ = col;
}

Cell Cell::getNextCell(Cell current) {

    unsigned int row = current.getRow();
    unsigned int col = current.getCol();

    col ++;
    if(col >= kSideLength){
        col = 0;
        row++;
    }

    Cell next(row, col);
    return next;
}

SudokuBoard::SudokuBoard() {
    vector<vector<int>> init(kSideLength, vector<int>(kSideLength, 0));
    boardState_ = init;
}

ostream& operator<< (ostream& output, const SudokuBoard& board) {

    for(unsigned int row = 0; row < board.kSideLength; row++){
        for(unsigned int col = 0; col < board.kSideLength; col++){
            if(col % board.kSubSideLength == 0){
                output << " | ";
            }else {
                output << "  ";
            }
            output << board.boardState_[row][col];
        }
        if(row % board.kSubSideLength == 2) {
            output << endl;
            for (unsigned int count = 0; count < board.kSubSideLength; count++) {
                output << " - - - - -";
            }
        }
        output << endl;
    }

    return output;
}

istream& operator>> (istream& input, SudokuBoard& board) {
    string line;
    input >> line;
    board.setUpBoard(line);
    return input;
}

void SudokuBoard::setUpBoard(const string &str) {

    vector<vector<int>> state(kSideLength, vector<int>(kSideLength, 0));
    for(unsigned int row = 0; row < kSideLength; row++){
        for(unsigned int col = 0; col < kSideLength; col++){
            char character = str[static_cast<unsigned int>(kSideLength * row + col)];
            if(isdigit(character)){
                int num = character - kZero;
                state[row][col] = num;
            }
        }
    }
    boardState_ = state;
}

void SudokuBoard::setValue(Cell current, int value) {
    boardState_[current.getRow()][current.getCol()] = value;
}

int SudokuBoard::getValue(Cell current) {
    return boardState_[current.getRow()][current.getCol()];
}

int SudokuBoard::getValue(unsigned int row, unsigned int col) {
    return boardState_[row][col];
}

namespace solver{

bool solve(SudokuBoard board){

    Cell start(0,0);
    return solve(board, start);
}

bool solve(SudokuBoard board, Cell current){

    if(current.getRow() >= kSideLength){
        return true;
    }else if(board.getValue(current) != kUnassignedCell){
        return solve(board, current.getNextCell(current));
    }else{
        for(int num = 1; num < kSideLength+1; num++){
            if(isValidValue(board, current, num)){
                board.setValue(current,num);
                if(solve(board, current.getNextCell(current))){
                    return true;
                }else {
                    board.setValue(current, kUnassignedCell);
                }
            }
        }
        return false;
    }
}

bool isValidValue(SudokuBoard board, Cell current, int value){

    for(unsigned int index = 0; index < kSideLength; index++){
        if(board.getValue(index,current.getCol()) == value ||
           board.getValue(current.getRow(), index) == value){
            return false;
        }
    }
    Cell corner = findTopLeftCornerCell(current);
    unsigned int edge_row_index = corner.getRow() + kSubSideLength;
    unsigned int edge_col_index = corner.getCol() + kSubSideLength;

    for(unsigned int row = corner.getRow(); row < edge_row_index; row++) {
        for(unsigned int col = corner.getCol(); col < edge_col_index; col++){
            if(board.getValue(row,col) == value){
                return false;
            }
        }
    }
    return true;
}

Cell findTopLeftCornerCell(Cell current){

    unsigned int row = current.getRow() / kSubSideLength * kSubSideLength;
    unsigned int col = current.getCol() / kSubSideLength * kSubSideLength;
    return Cell(row,col);
}

}
