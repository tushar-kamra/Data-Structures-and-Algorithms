#include<iostream>
using namespace std ;

int main(){
    int d ;
    cin >> d ;
    int s[6] = {} ;
    s[0] = 1 ;
    for(int i=1; i<=d; i++){
        int nv = s[0] + s[1] + s[2] + s[3] + s[4] + s[5] ;
        s[5] = s[4] ;
        s[4] = s[3] ;
        s[3] = s[2] ;
        s[2] = s[1] ;
        s[1] = s[0] ;
        s[0] = nv ;
    }
    cout << s[0] ;
}