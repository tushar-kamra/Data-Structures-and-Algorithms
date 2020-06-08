#include<iostream>
using namespace std ;

int main(){
    string s ;
    getline(cin,s) ;
    for(int i=0; i<s.length(); i++){
        if(ispunct(s[i])){
            s.erase(s.begin()+i) ;
            i-- ;
        }
    }
    cout << s ;
}