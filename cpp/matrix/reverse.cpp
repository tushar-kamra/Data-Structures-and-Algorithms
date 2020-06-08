#include <iostream>
using namespace std ;

int main(){
    int r,c ;
    cin >> r >> c;
    int a[r][c] ;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> a[i][j] ;
        }
    }
    /*
    int c1 = 0, c2 = c-1 ;
    while(c1<c2){
        for(int i=0; i<r; i++){
            int temp = a[i][c1];
            a[i][c1] = a[i][c2] ;
            a[i][c2] = temp ;
        }
        c1++ ;
        c2-- ;
    }
    */
    int c1 = 0, c2 = c-1 ;
    for(int i=0; i<r; i++){
        c1 = 0, c2 = c-1 ;
        while(c1<c2){
            int temp = a[i][c1] ;
            a[i][c1] = a[i][c2] ;
            a[i][c2] = temp ;
            c1++ ;
            c2-- ;
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << a[i][j] <<" " ;
        }
        cout << endl ;
    }
}