#include <iostream>
#include <fstream>
#include <sstream>
#include "SudokuSolver.h"
/*
 * Write your sudoku program! Do not put all of your code in main.cpp;
 * make new files as necessary.
 *
 * Make sure that the correct .cpp and .h/.hpp files are available to the
 * sudoku and testing executables as necessary.
 * CLion should prompt you to add the right info to the CMakeLists.txt
 * whenever you create new .cpp files.
 */

bool isValidFile(string);
using namespace std;
using namespace solver;

int main(int argc, char *argv[]) {

    const string kSPFVersion = "#spf1.0";
    string fileName;
    string line;
    vector<string> fileContent;

    cout <<"Please enter your file name. A default file will be used if entry is invalid." << endl;
    cin >> fileName;
    if(!isValidFile(fileName)){
        fileName = argv[0];
    }
    ifstream spfFile(fileName);
    if(spfFile.is_open()){
        while(getline(spfFile,line)){
            fileContent.push_back(line);
        }
    }
    if(fileContent[0] == kSPFVersion){
        fileContent.erase(fileContent.begin());
        for(const auto& str : fileContent){
            if(str.length() == 81) {
                SudokuBoard board;
                istringstream stream(str);
                stream >> board;
                if(solve(board)){
                    cout << board;
                }else{
                    cout << "Unsolvable puzzle" << endl;
                }
            }
        }
    }

    return EXIT_SUCCESS;
}

bool isValidFile(string fileName){
    ifstream test(fileName);
    return test.is_open();
}