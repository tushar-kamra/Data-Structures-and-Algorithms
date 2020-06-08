#include<iostream>
#include<vector>
#include<climits>
using namespace std ;

int main(){
    string s ;
    cin >> s ;
    int n = s.length() ;
    vector<vector<bool>> palin(n,vector<bool>(n,false));
    vector<vector<int>> mpc(n,vector<int>(n,0));
    for(int gap=0; gap<n; gap++){
        for(int i=0,j=gap ; i<n && j<n; i++,j++){
            if(gap == 0) palin[i][j] = true ;
            else if(gap == 1) palin[i][j] = s[i]==s[j] ;
            else palin[i][j] = s[i]==s[j] && palin[i+1][j-1]; 
        }
    }
    cout << "palin \n" ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << palin[i][j] <<" " ;
        }
        cout << endl ;
    }
    for(int gap=0; gap<n; gap++){
        for(int i=0,j=gap ; i<n && j<n; i++,j++){
            if(gap == 0) mpc[i][j] = 0 ;
            else if(gap == 1) mpc[i][j] = (palin[i][j])?0:1 ;
            else {
                if(palin[i][j]){
                    mpc[i][j] = 0 ;
                    continue ;
                }
                int mini = INT_MAX ;
                for(int cp=i; cp<j; cp++){
                    int val = mpc[i][cp] + mpc[cp+1][j]+1 ;
                    if(val < mini){
                        mini = val ;
                    }
                }
                mpc[i][j] = mini ;
            }
        }
    }
    cout << "mpc \n" ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mpc[i][j] <<" " ;
        }
        cout << endl ;
    }
    cout << mpc[0][n-1] ;
}