#include<iostream>
using namespace std ;

string copy(string s, string c){
    static int k = 0 ;
    if(k == s.length()){
        return c ;
    }
    c += s[k] ;
    k++ ;
    return copy(s,c) ;
}
int main(){
    string s, c="" ;
    getline(cin,s) ;
    cout<<copy(s,c) ;
}