#include "SudokuSolver.h"
#include "iostream"
#include <cstdlib>
#include <vector>

using namespace std;

SudokuBoard::SudokuBoard() {

}

std::ostream& operator<< (std::ostream& output, const SudokuBoard& board) {

    for(const auto &row : board.boardState){
        for(const auto &element : row){
            output << element << "|";
        }
        output << endl;
        for(int i = 0; i < board.kSideLength; i ++){
            output << "__ ";
        }
        output<< endl;
    }
    return output;
}

std::istream& operator>> (std::istream& input, SudokuBoard& board) {
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
            if(isdigit(character)){
                int num = character - '0';
                state[row][col] = num;
            }
        }
    }
    return state;
}



