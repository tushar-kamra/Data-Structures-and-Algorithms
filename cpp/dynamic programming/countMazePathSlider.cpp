#include<iostream>
using namespace std ;

int main(){
    int x1,y1,x2,y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ;
    int s[y2+1] ;
    for(int i = 0; i<=y2; i++){
        s[i] = 1 ;
    }
    for(int i=1; i<=x2; i++){
        for(int j=y2-1; j>=0; j--){
            s[j] += s[j+1] ;
        }
    }
    cout << s[0] ;
}