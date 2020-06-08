#include<iostream>
using namespace std ;

string content(string s){
    if(s.length()<2) return "" ;
    if(s[0] == '('){
        if(s[s.length()-1] == ')'){
            return s ;
        }
        else {
            return content(s.substr(0,s.length()-1)) ;
        }
    }
    return content(s.substr(1)) ;
}

int main(){
    string s ;
    cin >> s ;
    cout << content(s) ;
}