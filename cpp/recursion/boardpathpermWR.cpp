#include<iostream>
#include<vector>
using namespace std ;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " " ;
    }
    cout << endl ;
}

void boardPathPermWR(int idx, int n, vector<int> &v, bool isdone[]){
    if(n==0){
        print(v) ;
    }
    for(int i = 1 ; i <= n; i++){
        if(isdone[i] == false){
            v.push_back(i) ;
            isdone[i] = true ;
            boardPathPermWR(i+1,n-i,v,isdone);
            v.pop_back();
            isdone[i] = false ;
        }
    }
}

int main(){
    int n ;
    cin >> n ;
    vector<int> v ;
    bool isdone[n+1] = {} ;
    boardPathPermWR(1, n, v, isdone) ;
}