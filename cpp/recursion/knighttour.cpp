#include<iostream>
#include<iomanip>
using namespace std ;
const int D = 8 ;

bool canPlace(int Board[D][D], int n, int r, int c){
    if( r>=0 && r<n && c>=0 && c<n && Board[r][c]==0 ){
        return true ;
    }
    return false ;
}

bool solveKnightTour(int Board[D][D], int n, int move_no, int curr_row, int curr_col){
    // base condition
    if(move_no == n*n) return true ;

    int row_dir[] = {2,1,-1,-2,-2,-1,1,2} ;
    int col_dir[] = {1,2,2,1,-1,-2,-2,-1} ;
    for(int i=0; i<8; i++){
        int next_row = curr_row + row_dir[i] ;
        int next_col = curr_col + col_dir[i] ;
        if(canPlace(Board,n,next_row,next_col)){
            Board[next_row][next_col] = move_no+1 ;
            bool isSuccess = solveKnightTour(Board,n,move_no+1,next_row,next_col);
            if(isSuccess) return true ;
            Board[next_row][next_col] = 0 ;
        }
    }
    return false ;
}

void print(int Board[D][D], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << setw(3) << Board[i][j] <<" " ;
        }
        cout << endl ;
    }
}

int main(){
    int n ;
    cin >> n ;
    int Board[D][D] = {0} ;
    Board[0][0] = 1 ;
    if(solveKnightTour(Board, n, 1, 0, 0)){
        print(Board,n) ;
    }
}