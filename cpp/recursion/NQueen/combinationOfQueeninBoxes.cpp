#include<iostream>
using namespace std ;

void combination(bool box[], int n, int tq, int qpsf, string ans, int lqpb){
    if(qpsf == tq){
        cout << ans << endl ;
        return ;
    }
    for(int i=lqpb; i<n; i++){
        if(box[i] == 0){
            box[i] = 1 ;
            combination(box,n,tq,qpsf+1,ans+"Q"+char(qpsf+1+'0')+"B"+char(i+'0')+" ",i+1);
            box[i] = 0 ;
        }
    }
}

int main(){
    int n, tq ;
    cin >> n >> tq ;
    bool box[n] = {0} ;
    combination(box,n,tq,0,"",0) ;
}