#include<iostream>
#include<vector>
using namespace std ;

void minCostPath(int x1, int y1, int x2, int y2,vector< vector<int> > &cost, vector< vector<int> > &minCost, vector< vector<string> > &path){
    for(int i=x2; i>=0; i--){
        for(int j=y2; j>=0; j--){
            if(i == x2 && j == y2){
                minCost[i][j] = cost[i][j] ;
                path[i][j] = "." ;
            }
            else if(i == x2){
                minCost[i][j] = cost[i][j] + minCost[i][j+1] ;
                path[i][j] = "H"+path[i][j+1] ;
            }
            else if(j == y2){
                minCost[i][j] = cost[i][j] + minCost[i+1][j] ;
                path[i][j] = "V"+path[i+1][j] ;
            }
            else {
                if(minCost[i+1][j] < minCost[i][j+1]){
                    minCost[i][j] = cost[i][j] + minCost[i+1][j] ;
                    path[i][j] = "V"+path[i+1][j] ;
                }
                else {
                    minCost[i][j] = cost[i][j] + minCost[i][j+1] ;
                    path[i][j] = "H"+path[i][j+1] ;
                }
            }
        }
    }
}

int main(){
    int x1,y1,x2,y2 ;
    cin >> x1 >> y1 >> x2 >> y2 ;
    vector< vector<int> > cost(x2+1,vector<int>(y2+1)) ;
    vector< vector<int> > minCost(x2+1,vector<int>(y2+1)) ;
    vector< vector<string> > path(x2+1,vector<string>(y2+1)) ;
    for(int i=0; i<cost.size(); i++){
        for(int j=0; j<cost[i].size(); j++){
            cin >> cost[i][j] ;
        }
    }
    minCostPath(x1,y1,x2,y2,cost,minCost,path) ;
    cout << "Min cost : " << minCost[0][0] << endl ;
    cout << "Min path : " << path[0][0] ;
}