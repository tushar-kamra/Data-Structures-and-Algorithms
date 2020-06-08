#include<iostream>
#include<vector>
using namespace std ;


void targetsum(vector<int> v, int idx, int target, string ans){
    /*
    if(idx == v.size() || target <= 0){
        if(target == 0){
            cout << ans <<" " ;
            return 1 ;
        }
        return 0 ;
    }
    */
    if(idx == v.size()){
        if(target == 0){
            cout << ans <<" " ;
        }
        return ;
    }
    if(target < 0){
        return ;
    }
    targetsum(v,idx+1,target,ans);
    targetsum(v,idx+1,target-v[idx],ans+to_string(v[idx])+" ") ;
    return ;
}

int main(){
    int n, target ;
    cin >> n >> target ;
    vector<int> v(n) ;
    for(int i=0; i<n; i++){
        cin >> v[i] ;
    }
    targetsum(v,0,target, "") ;
}