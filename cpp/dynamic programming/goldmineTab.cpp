#include<iostream>
#include<vector>

using namespace std ;

int main(){
    int r,c ;
    cin >> r >> c ;
    vector<vector<int>> v(r,vector<int>(c));
    vector<vector<int>> mine(r,vector<int>(c)) ;
    vector<vector<string>> path(r,vector<string>(c)) ;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> v[i][j] ;
        }
    }
    for(int j=c-1; j>=0; j--){
        for(int i=0; i<r; i++){
            if(j == c-1){
                mine[i][j] = v[i][j] ;
            }
            else if(i == 0){
                mine[i][j] = v[i][j] + max(mine[i][j+1],mine[i+1][j+1]);
            }
            else if(i == r-1){
                mine[i][j] = v[i][j] + max(mine[i][j+1],mine[i-1][j+1]);
            }
            else {
                mine[i][j] = v[i][j] + max(mine[i-1][j+1],max(mine[i][j+1],mine[i+1][j+1]));
            }
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << mine[i][j] <<" " ;
        }
        cout << endl ;
    }
}