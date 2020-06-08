#include<iostream>
#include<vector>
using namespace std ;

void print(vector<int> v){
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " " ;
    }
    cout << endl ;
}

void snakeladder(int si, int ei, int k, string ans){
    if(si==ei){
        cout << ans << " " ;
        return ;
    }
    for(int jump = 1; si+jump <= ei && jump <= k; jump++){
        snakeladder(si+jump, ei, k, ans+to_string(jump)) ;
    }
}

int main(){
    int n, k ;
    cin >> n >> k ;
    vector<int> v ;
    snakeladder(0, n, k, "") ;
}