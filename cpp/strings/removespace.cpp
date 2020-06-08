#include<iostream>
using namespace std ;

int main(){
    string s ;
    getline(cin,s);
    int j=0 ;
    for(int i=0; i<s.length(); i++){
        if(s[i] != ' '){
            s[j++] = s[i] ;
        }
        else {
            s.erase(s.begin()+i);
            i-- ;
        }
    }
    
    cout << s ;
}