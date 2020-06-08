#include<iostream>
#include<iomanip>
using namespace std ;

const int D = 9 ;

bool canPlace(int board[D][D], int n, int currNum, int row, int col){
    for(int i=0; i<n; i++){
        if(board[row][i]==currNum) return false ;
        if(board[i][col]==currNum) return false ;
    }
    int startRow = row-row%3 ;
    int startCol = col-col%3 ;
    for(int i=startRow; i<startRow+3; i++){
        for(int j=startCol; j<startCol+3; j++){
            if(board[i][j] == currNum) return false ;
        }
    }
    return true ;
}

bool solveSudoku(int board[D][D], int n, int row, int col){
    if(col == n){
        return solveSudoku(board,n,row+1,0) ;
    }
    if(row == n){
        return true ;
    }
    if(board[row][col] != 0) return solveSudoku(board,n,row,col+1) ;
    for(int currNum = 1; currNum <= n; currNum++){
        if(canPlace(board,n,currNum,row,col)){
            board[row][col] = currNum ;
            bool success = solveSudoku(board,n,row,col+1) ;
            if(success) return true ;
            board[row][col] = 0 ;
        }
    }
    return false ;
}

void print(int board[D][D], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << setw(3) << board[i][j] ;
        }
        cout << endl ;
    }
}

int main(){
    int n ;
    cin >> n ;
    int board[D][D] = {
                      {3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}
    } ;
    if(solveSudoku(board,n,0,0)){
        print(board,n) ;
    }
    else {
        cout << "Bro! Solve it yourself" ;
    }
}