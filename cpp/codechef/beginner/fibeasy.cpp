#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;

void constructTriangle(ll pt[][31]){
    for(int i=0; i<31; i++){
        for(int j=0; j<=i; j++){
            if(i == 0 && j == 0){
                pt[i][j] = 1 ;
            }
            else if(j == 0 || j == i){
                pt[i][j] = 1 ;
            }
            else {
                pt[i][j] = pt[i-1][j-1] + pt[i-1][j] ;
            }
        }
    }
}

bool isValid(int x, int y, bool vis[][31]){
    if(x < 0 || y < 0 || x > 30 || y > x || vis[x][y]){
        return false ;
    }
    return true ;
}

vector<pair<int,int>> v ;

void printVector(){
    for(int i=0; i<v.size(); i++){
        cout << v[i].first <<" " << v[i].second << endl ;
    }
}

bool findPath(int x, int y, ll curr_sum, ll sum, ll pt[][31], bool vis[][31]){
    if(curr_sum == sum){
        v.push_back({x+1,y+1}) ;
        printVector() ;
        return true ;
    }
    if(curr_sum > sum){
        return false;
    }
    v.push_back({x+1,y+1}) ;
    vis[x][y] = true ;
    if(isValid(x-1,y,vis) && findPath(x-1,y,curr_sum+pt[x-1][y],sum,pt,vis)){
        return true ;
    }
    if(isValid(x,y+1,vis) && findPath(x,y+1,curr_sum+pt[x][y+1],sum,pt,vis)){
        return true ;
    }
    if(isValid(x+1,y,vis)  && findPath(x+1,y,curr_sum+pt[x+1][y],sum,pt,vis)){
        return true ;
    }
    if(isValid(x,y-1,vis) && findPath(x,y-1,curr_sum+pt[x][y-1],sum,pt,vis)){
        return true ;
    }
    if(isValid(x-1,y-1,vis) && findPath(x-1,y-1,curr_sum+pt[x-1][y-1],sum,pt,vis)){
        return true ;
    }
    if(isValid(x+1,y+1,vis) && findPath(x+1,y+1,curr_sum+pt[x+1][y+1],sum,pt,vis)){
        return true ;
    }
    vis[x][y] = false ;
    v.pop_back() ;
    return false ;
}


int main(){
    int t ;
    cin >> t ;
    while(t--){
        ll n ;
        cin >> n ;
        ll pt[31][31] = {} ;
        bool vis[31][31] = {false} ;
        constructTriangle(pt) ;
        findPath(0,0,1,n,pt,vis) ;
    }
}