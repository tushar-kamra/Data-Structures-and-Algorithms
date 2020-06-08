#include<iostream>
#include<vector>
using namespace std ;

int size = 0 ;
int row = -1 ;
int col = -1 ;
int maxSize(int x, int y, vector<vector<int>> v){
    int res ;
    if(x == v.size()-1 || y == v[0].size()-1){
        return v[x][y] ;
    }
    if(v[x][y] == 0){
        return 0 ;
    }
    else {
        int sizeH = maxSize(x,y+1,v) ;
        int sizeV = maxSize(x+1,y,v) ;
        int sizeD = maxSize(x+1,y+1,v) ;
        res = min(sizeH,min(sizeV,sizeD))+1 ;
        if(res>::size){
            ::size = res;
            row = x ;
            col = y ;
        }
    }
    return res ;
}

int main(){
    int r, c ;
    cin >> r >> c ;
    vector< vector<int> > v(r, vector<int>(c)) ;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> v[i][j] ;
        }
    }
    maxSize(0,0,v) ;
    cout << ::size << "@< [" << row <<"," <<col <<"]" ;
}