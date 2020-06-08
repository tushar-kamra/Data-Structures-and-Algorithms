#include<iostream>
#include<sstream>
using namespace std ;

int main(){
    string s ;
    getline(cin,s) ;
    stringstream obj(s) ;
    string w ;
    while(obj >> w){
        cout << w[0] <<" " ;
    }
}