#include<iostream>
#include<vector>
using namespace std ;

bool isvalid(vector<vector<bool>> &v, int x, int y){
    if(x<0 || y<0 || x>=v.size() || y>=v[0].size() || v[x][y]){
        return false ;
    }
    return true ;
}

int floodfill(vector<vector<bool>> &v, int x1, int y1, int x2, int y2, string ans){
    if(x1 == x2 && y1 == y2){
        cout << ans << " " ;
        return 1 ;
    }
    int count = 0 ;
    v[x1][y1] = true ;
    if(isvalid(v,x1,y1+1)){
        count += floodfill(v,x1,y1+1,x2,y2,ans+"R") ;
    }
    if(isvalid(v,x1+1,y1)){
        count += floodfill(v,x1+1,y1,x2,y2,ans+"D") ;
    }
    if(isvalid(v,x1-1,y1)){
        count += floodfill(v,x1-1,y1,x2,y2,ans+"U") ;
    }
    if(isvalid(v,x1,y1-1)){
        count += floodfill(v,x1,y1-1,x2,y2,ans+"L") ;
    }
    v[x1][y1] = false ;     // backtracking
    return count ;
}

int main(){
    int m, n ;
    cin >> m >> n ;
    vector<vector<bool>> v(m,vector<bool>(n,false)) ;
    cout << floodfill(v,0,0,m-1,n-1,"") ;
}