#include<iostream>
using namespace std ;

bool issafe(bool box[10][10], int n, int row, int col){
    int dir[][2] = {
        {-1,0},
        {-1,1},
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
        {0,-1},
        {-1,-1}
    };
    for(int i = 0; i<8; i++){
        for(int j=1; ; j++){
            int enrow = row + j*dir[i][0] ;
            int encol = col + j*dir[i][1] ;

            if(enrow < 0 || enrow >= n || encol < 0 || encol >= n){
                break ;
            }

            if(box[enrow][encol] == true){
                return false ;
            }
        }
    }
    return true ;
}

/*
bool isvalidboard(bool box[10][10], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(box[i][j] == true){
                if(issafe(box,n,i,j) == false){
                    return false ;
                }
            }
        }
    }
    return true ;
}
*/

void nqueen(bool box[10][10], int n, int qpsf, string ans, int lqpb){
    if(qpsf == n){
        cout << ans<< endl ;
        return ;
    }
    for(int i=lqpb; i<n*n; i++){
        int row = i/n ;
        int col = i%n ;
        if(box[row][col] == 0){
            if(issafe(box,n,row,col)){
                box[row][col] = 1 ;
                nqueen(box,n,qpsf+1,ans+"Q"+char(qpsf+1+'0')+"B"+to_string(i)+" ",i);
                box[row][col] = 0 ;
            }
        }
    }
}

int main(){
    int n ;
    cin >> n ;
    bool box[10][10] = {} ;
    nqueen(box,n,0,"",0) ;
}