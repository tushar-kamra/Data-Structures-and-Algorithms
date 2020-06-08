#include<iostream>
#include<vector>
using namespace std ;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " " ;
    }
    cout << endl ;
}

void boardPathCombWR(int idx, int n, vector<int> &v){
    if(n==0){
        print(v) ;
    }
    for(int i = idx ; i <= n; i++){
        v.push_back(i);
        boardPathCombWR(i+1,n-i,v);
        v.pop_back();
    }
}

int main(){
    int n ;
    cin >> n ;
    vector<int> v ;
    boardPathCombWR(1, n, v) ;
}