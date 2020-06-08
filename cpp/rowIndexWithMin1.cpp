#include<iostream>
using namespace std ;

int main(){
    int n,m,c,idx ;
    cin >> n >> m ;
    int mini = m+1 ;
    int a[n][m] ;
    for(int i=0; i<n; i++){
        c = 0 ;
        for(int j=0; j<m; j++){
            cin >> a[i][j] ;
            if(a[i][j] == 1){
                c++ ;
            }
        }
        if(c < mini){
            mini = c ;
            idx = i ;
        }
    }
    cout << idx << endl ;
}