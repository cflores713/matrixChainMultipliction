#include <iostream>
#include <vector>
#include "scalars.h"
using namespace std;

int main() {

    /// Put the numbers from the questions in the array P and the criteria in the string variable "condition.".
    vector<int>  P = {6, 2, 8, 1, 7, 9};
    string condition = "min";

    Scalars arr(P, condition);
    arr.giveDimensions();
    while(arr.diagonalize()){
        arr.print();
    }
    arr.parenthesisation();

    cout << "Hello, World!" << endl;
    return 0;
}


