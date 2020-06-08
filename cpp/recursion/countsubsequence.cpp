#include<iostream>
using namespace std ;

int subsequence(string s, string ans){
    if(s.length() == 0){
        cout << ans << " " ;
        return 1 ;
    }
    char ch = s[0] ;
    string str = s.substr(1) ;
    int count = 0 ;
    count += subsequence(str,ans) ;
    count += subsequence(str,ans+ch) ;
    return count ;
}

int main(){
    string s ;
    cin >> s ;
    cout << subsequence(s,"") ;
}