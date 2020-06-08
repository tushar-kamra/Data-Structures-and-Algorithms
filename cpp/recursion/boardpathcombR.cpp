#include<iostream>
#include<vector>
using namespace std ;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " " ;
    }
    cout << endl ;
}

void boardPathCombR(int idx, int n, vector<int> &v){
    if(n==0){
        print(v) ;
    }
    for(int i = idx ; i <= n; i++){
        v.push_back(i);
        boardPathCombR(i,n-i,v);
        v.pop_back();
    }
}

int main(){
    int n ;
    cin >> n ;
    vector<int> v ;
    boardPathCombR(1, n, v) ;
}