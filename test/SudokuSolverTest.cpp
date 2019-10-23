#include "catch.hpp"
#include "SudokuSolver.h"
#include <sstream>

TEST_CASE("Cell Class") {

    Cell cell_1(1,9);
    Cell cell_2(2,3);

    SECTION("getRow method") {
        REQUIRE(cell_1.getRow() == 1);
    }

    SECTION("getCol method") {
        REQUIRE(cell_1.getCol() == 9);
    }

    SECTION("getNextCell method") {
        Cell next_1 = cell_1.getNextCell(cell_1);
        Cell next_2 = cell_2.getNextCell(cell_2);
        REQUIRE(next_1.getRow() == 2 && next_1.getCol() == 0);
        REQUIRE(next_2.getCol() == 2 && next_2.getCol() == 4);
    }
}

//TEST_CASE("SudokuBoard Class") {
//
//    SudokuBoard board;
//    vector<vector<int>> state{{8,5,0,0,0,2,4,0,0},
//                              {7,2,0,0,0,0,0,0,9},
//                              {0,0,4,0,0,0,0,0,0},
//                              {0,0,0,1,0,7,0,0,2},
//                              {3,0,5,0,0,0,9,0,0},
//                              {0,4,0,0,0,0,0,0,0},
//                              {0,0,0,0,8,0,0,7,0},
//                              {0,1,7,0,0,0,0,0,0},
//                              {0,0,0,0,3,6,0,4,0}};
//    string diff = "___8_5____3__6___7_9___38___4795_3______71_9____2__5__1____248___9____5______6___";
//    string same = "85___24__72______9__4_________1_7__23_5___9___4___________8__7__17__________36_4_";
//
//    SECTION("setUpBoard method"){
//        board.setUpBoard(diff);
//        REQUIRE(!equal(state.begin(),state.end(),board.getBoardState()));
//        board.setUpBoard(same);
//        REQUIRE(equal(state.begin(),state.end(),board.getBoardState()));
//    }
//
//    SECTION("setValue and getValue methods"){
//        Cell cell(1,4);
//        board.setValue(cell, 4);
//        REQUIRE(board.getValue(cell) == 4);
//        REQUIRE(board.getValue(cell.getRow(),cell.getCol()) == 4);
//    }
//
//    SECTION("overload input operator"){
//        istringstream stream(same);
//        stream >> board;
//        REQUIRE(equal(state.begin(),state.end(),board.getBoardState()));
//    }
//
//    SECTION("overload output operator"){
//        cout << board;
//    }
//}
//
//TEST_CASE("solver namespace") {
//
//    using namespace solver;
//    SudokuBoard board;
//    string str = "85___24__72______9__4_________1_7__23_5___9___4___________8__7__17__________36_4_";
//    board.setUpBoard(str);
//
//    SECTION("isValidValue method"){
//        Cell cell(0,2);
//        REQUIRE(!isValidValue(board,cell,8));
//        REQUIRE(isValidValue(board,cell,1));
//    }
//
//    SECTION("findTopLeftCornerCell method") {
//        Cell cell(2,8);
//        Cell topLeftCornerCell(0,6);
//        Cell actual = findTopLeftCornerCell(cell);
//        REQUIRE(actual.getRow() == topLeftCornerCell.getRow()
//               && actual.getCol() == topLeftCornerCell.getCol());
//    }
//}

