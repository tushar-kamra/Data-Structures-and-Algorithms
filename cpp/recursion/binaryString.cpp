#include<iostream>
using namespace std ;

void binaryString(int n, string ans){
    if(n == 0){
        cout << ans << endl ;
        return ;
    }
    binaryString(n-1,ans+'0') ;
    binaryString(n-1,ans+'1') ;
}

int main(){
    int n ;
    cin >> n ;
    binaryString(n,"");
}