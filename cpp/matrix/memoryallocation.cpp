#include<iostream>
using namespace std ;

/*
void print(int a[], int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<*(a+i*c+j)<<" " ;
        }
        cout<<endl ;
    }
}
*/

void print(int **a, int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << a[i][j] <<" " ;
        }
        cout << endl ;
    }
}

int main(){
    int r,c ;
    cin >> r >> c ;
    /*
    int *arr = new int[r*c] ;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> *(arr+i*c+j) ;
        }
    }
    print(arr,r,c) ;
    */
   int **arr = new int *[r] ;
   for(int i=0; i<r; i++){
       arr[i] = new int[c] ;
   }
   for(int i=0; i<r; i++){
       for(int j=0; j<c; j++){
           cin >> arr[i][j] ;
       }
   }

   print(arr,r,c) ;
}