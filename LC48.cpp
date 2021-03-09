#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int> >& matrix) {
        if(matrix.size()==1)return;
        int size = matrix.size();
        //  traverse
        for(int i = 0; i < size; i++){
            for(int j = 0;j < i; j++){
                if(i != j)
                    std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        // vertical rotate
        for(int i = 0; i < size; i++){
            for(int j = 0;j < size / 2;j++){
                if(j!=size - j -1)
                    std::swap(matrix[i][j], matrix[i][size - j - 1]);
            }
        }
        return;
    }
