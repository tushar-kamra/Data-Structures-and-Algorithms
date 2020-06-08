#include<iostream>
using namespace std ;

string divide(string s, int div){
    string ans = "" ;
    int idx = 0 ;
    int temp = s[idx]-'0' ;
    while(temp<div){
        temp = temp*10 + (s[++idx]-'0') ;
    }
    while (idx < s.length()){
        ans += (temp/div)+'0';
        temp = (temp%div)*10 + (s[++idx]-'0');
    }
    if(ans.length() == 0) {
        return "0" ;
    }
    return ans  ;
}

int main(){
    string s ;
    cin >> s ;
    int n ;
    cin >> n ;
    cout << divide(s,n) ;
}