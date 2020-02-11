//
// Created by Carlos Flores on 2/9/20.
//

#ifndef MATRIXMULT_SCALARS_H
#define MATRIXMULT_SCALARS_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Scalars{
private:
    vector<int> dim;
    int size;
    int** arr;
    int distance;
    string condition;
    int*** parenthesis;

public:
    Scalars(vector<int> P, string c){
        size = P.size();
        condition = c;
        distance = 1;

        dim.push_back(0);
        for (const auto &i : P){
            dim.push_back(i);
        }

        arr = new int*[size];
        parenthesis = new int**[size];
        for(int i = 0 ; i < size ; i++){
            arr[i] = new int[size];
            parenthesis[i] = new int*[size];
            for (int j = 0 ; j < size ; j++){
                parenthesis[i][j] = new int[4];
            }
            arr[0][i] = i;
            for (int j = 0; j < i; j++){
                arr[i][j] = -1;
            }
        }

    }

    void giveDimensions(){
        for (int i = 1 ; i < size ; i++){
            cout << "Matrix " << i << " has a size of [" << dim[i] << "][" << dim[i+1] << "]" << endl;
        }
    }

    void setCondition(const string &x){
        condition = x;
    }

    bool diagonalize(){
        cout << endl;
        if (distance > 0 && distance < size-1 && size) {
            cout << "Round: " << distance << endl;
            for (int i = 1; i < size - distance ; i++) {
                int j = i + distance;
                calculate(i,j);
                if (distance > 1){
                    cout << endl;
                }
            }
            distance++;
            return true;
        }
        return false;
    }

    void print(){
        for(int i = 1 ; i < size ; i++){
            if (i == 0){
                cout << "   ";
            } else {
                cout << i << "| ";
            }

            for (int j = 1; j < size; j++){
                if (arr[i][j] == -1){
                    cout <<" [  ] ";
                } else if (arr[i][j] < 10){
                    cout <<"  " << arr[i][j] << "   ";
                } else if (arr[i][j] < 100){
                    cout <<"  " << arr[i][j] << "  ";
                } else if (arr[i][j]<1000){
                    cout <<" " << arr[i][j] << "  ";
                } else if (arr[i][j]<10000){
                    cout <<" " << arr[i][j] << " ";
                }else{}

            }
            cout << endl;
        }
    }

    void calculate(int i, int j){
        int minimum = INT_MAX, sum = 0, maximum = 0;

        for (int k = i; k < j; k++){

            arr[i][j] = dim[i] * dim[k+1] * dim[j+1] + arr[i][k] + arr[k+1][j];
            if (minimum > arr[i][j]){
                minimum = arr[i][j];

                parenthesis[i][j][0] = i;
                parenthesis[i][j][1] = k;
                parenthesis[i][j][2] = k+1;
                parenthesis[i][j][3] = j;
            }

            if (maximum < arr[i][j]){
                maximum = arr[i][j];
                parenthesis[i][j][0] = i;
                parenthesis[i][j][1] = k;
                parenthesis[i][j][2] = k+1;
                parenthesis[i][j][3] = j;
            }
            sum += arr[i][j];

            cout << "K = " << k << ", " << "S[" << i << "," << j << "] = (P" << i << "* P";
            cout << k+1 << "* P" << j+1 << ") + s[" << i << "," << k << "] + S[" << k+1 << ",";
            cout << j << "] =" << " (" << dim[i] << " * " << dim[k+1] << " * " << dim[j+1];
            cout << ") + " << arr[i][k] << " + " << arr[k+1][j] << " = " << arr[i][j] << endl;
        }

        if(condition == "max"){
            arr[i][j] = maximum;
            //cout << "Parenthesisation Pattern: S[" << parenthesis[i][j][0] << "," << parenthesis[i][j][1] << "] * S[" << parenthesis[i][j][2] << "," << parenthesis[i][j][3] << "]" << endl;
        } else if(condition == "min"){
            arr[i][j] = minimum;
            //cout << "Parenthesisation Pattern: S[" << parenthesis[i][j][0] << "," << parenthesis[i][j][1] << "] * S[" << parenthesis[i][j][2] << "," << parenthesis[i][j][3] << "]" << endl;
        } else {
            arr[i][j] = sum/distance;
        }

    }

    void parenthesisation(int i = 1, int j = 5){

        if (i == 1 && j == 5){
            cout << "Parenthesisation Pattern: for Matrix " << i  << " to Matrix " << j << " is:\n\t\tS[" << parenthesis[i][j][0] << "," << parenthesis[i][j][1] << "] * S[" << parenthesis[i][j][2] << "," << parenthesis[i][j][3] << "]" << endl;
        } else {
            cout << "Matrix " << i  << " to Matrix " << j << " is: S[" << parenthesis[i][j][0] << "," << parenthesis[i][j][1] << "] * S[" << parenthesis[i][j][2] << "," << parenthesis[i][j][3] << "]" << endl;
        }

        if (parenthesis[i][j][0] != parenthesis[i][j][1]){
            parenthesisation(parenthesis[i][j][0], parenthesis[i][j][1]);
        }

        if (parenthesis[i][j][2] !=  parenthesis[i][j][3]){
            parenthesisation(parenthesis[i][j][2], parenthesis[i][j][3]);
        }
    }

};


#endif //MATRIXMULT_SCALARS_H
