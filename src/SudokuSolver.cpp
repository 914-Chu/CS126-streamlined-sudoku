#include "SudokuSolver.h"
#include "iostream"
#include <vector>

using namespace std;


Cell::Cell(unsigned int row, unsigned int col) {

    this->row_ = row;
    this->col_ = col;
}

Cell Cell::getNextCell(Cell current) {

    unsigned int row = current.getRow();
    unsigned int col = current.getCol();

    row ++;
    col ++;

    if(col >= kSideLength){
        col = 0;
    }
    Cell next(row, col);
    return next;
}


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
    board.boardState_ = board.setUpBoard(line);
    return input;
}

vector<vector<int>> SudokuBoard::setUpBoard(const string &str) {

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
    return state;
}

void SudokuBoard::setValue(Cell current, int value) {
    boardState_[current.getRow()][current.getCol()] = value;
}

int SudokuBoard::getValue(Cell current) {
    return boardState_[current.getRow()][current.getCol()];
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
        for(int num = 0; num < kSideLength; num++){
            if(isValidValue(board, current, num)){
                board.setValue(current,num);
                return solve(board, current.getNextCell(current));
            }
        }
        return false;
    }
}

bool isValidValue(SudokuBoard board, Cell current, int value){

    for(unsigned int index = 0; index < kSideLength; index++){
        if(board.getValue(Cell(index,current.getCol())) == value ||
           board.getValue(Cell(current.getRow(), index)) == value){
            return false;
        }
    }
    Cell corner = findCornerCell(current);
    unsigned int edge_row_index = corner.getRow() + kSubSideLength;
    unsigned int edge_col_index = corner.getCol() + kSubSideLength;

    for(unsigned int row = corner.getRow(); row < edge_row_index; row++) {
        for(unsigned int col = corner.getCol(); col < edge_col_index; col++){
            if(board.getValue(Cell(row,col)) == value){
                return false;
            }
        }
    }
    return true;
}

Cell findCornerCell(Cell current){

    unsigned int row = current.getRow() / kSubSideLength * kSubSideLength;
    unsigned int col = current.getCol() / kSubSideLength * kSubSideLength;
    return Cell(row,col);
}

}
