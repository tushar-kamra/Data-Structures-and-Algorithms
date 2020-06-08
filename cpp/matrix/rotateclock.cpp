#include<iostream>
using namespace std ;

int main(){
    int r,c ;
    cin >> r >> c ;
    int a[r][c] ;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j] ;
        }
    }
    int min_row = 0, max_row = r-1, min_col = 0, max_col = c-1 ;
    while(min_row <= max_row && min_col <= max_col){
        int x = min_row, y = min_col ;
        int temp = a[x][y] ;
        for(int i=min_col+1; i<=max_col; i++){
            int t = a[min_row][i] ;
            a[min_row][i] = temp ;
            temp = t ;
        }
        min_row++ ;
        for(int i=min_row; i<=max_row; i++){
            int t = a[i][max_col] ;
            a[i][max_col] = temp ;
            temp = t ;
        }
        max_col-- ;
        if(min_row <= max_row){
            for(int i=max_col; i>=min_col; i--){
                int t = a[max_row][i] ;
                a[max_row][i] = temp ;
                temp = t ;
            }
            max_row-- ;
        }
        if(min_col <= max_col){
            for(int i=max_row; i>=min_row; i--){
                int t = a[i][min_col];
                a[i][min_col] = temp ;
                temp = t ;
            }
            min_col++ ;
        }
        a[x][y] = temp ;
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<a[i][j]<<" " ;
        }
        cout<<endl ;
    }
}