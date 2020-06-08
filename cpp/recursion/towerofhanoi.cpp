#include<iostream>
#include<vector>
using namespace std ;

vector<string> v ;

void toh(int n, char from, char aux, char to){
    if(n > 0){
        toh(n-1,'A','C','B');
        string s = "Move disc ["+to_string(n)+"] from "+from+" to "+to ;
        v.push_back(s) ;
        toh(n-1,'B','A','C');
    }
}

int main(){
    int d ;
    cin >> d ;
    toh(d,'A','B','C') ;
    cout << v.size() << endl ;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << endl ;
    }
    
}