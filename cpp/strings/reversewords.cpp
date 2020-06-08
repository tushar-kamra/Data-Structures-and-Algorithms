#include<iostream>
#include<sstream>
using namespace std ;

string reverse(string s){
    int i = 0;
    int j = s.length()-1 ;
    while(i<j){
        swap(s[i],s[j]);
        i++ ;
        j-- ;
    }
    return s ;
}
int main(){
    string str, word ;
    getline(cin,str);
    
    stringstream s(str);
    while(s >> word) {
        cout<<reverse(word)<<" " ;
    }
}