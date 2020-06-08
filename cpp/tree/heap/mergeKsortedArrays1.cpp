#include<iostream>
#include<queue>
#include<climits>
using namespace std ;

struct Node {
    int data ;
    int i ;
    int j ;
};

class minHeap {
    Node *arr ;
    int heapSize ;
    public:
        minHeap(Node a[], int k) ;
        void minHeapify(int i) ;
        void replaceMin(Node root) ;
        Node findMin() ;
} ;

void minHeap::minHeapify(int i){
    int smallest = i ;
    int l = 2*i + 1 ;
    int r = 2*i + 2 ;
    if(l < heapSize && arr[l].data < arr[smallest].data){
        smallest = l ;
    }
    if(r < heapSize && arr[r].data < arr[smallest].data){
        smallest = r ;
    }
    if(smallest != i){
        swap(arr[smallest], arr[i]) ;
        minHeapify(smallest) ;
    }
}

minHeap::minHeap(Node a[], int k){
    heapSize = k ;
    arr = a ;
    for(int i=k/2-1; k>=0; k--){
        minHeapify(i) ;
    }
}

Node minHeap::findMin(){
    return arr[0] ;
}

void minHeap::replaceMin(Node root){
    arr[0] = root ;
    minHeapify(0) ;
}

int* mergeKSorted(int **arr, int k, int n){
    int *ans = new int[n*k] ;
    Node *harr = new Node[k] ;
    for(int i=0; i<k; i++){
        harr[i].data = arr[i][0] ;
        harr[i].i = i ;
        harr[i].j = 1 ;
    }
    // Create the heap
    minHeap h(harr,k);

    for(int count=0; count<n*k; count++){
        Node root = h.findMin() ;
        ans[count] = root.data ;
        if(root.j < n){
            root.data = arr[root.i][root.j] ;
            root.j += 1 ;
        }
        else {
            root.data = INT_MAX ;
        }

        h.replaceMin(root) ;
    }
    return ans ;
}

void print(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] <<" " ;
    }
}

int main(){
    int k, n ;
    cin >> k >> n ;
    int **arr ;
    arr = new int*[k] ;
    for(int i=0; i<k; i++){
        arr[i] = new int[n] ;
    }
    for(int i=0; i<k; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j] ;
        }
    }
    int* output ;
    output = mergeKSorted(arr,k,n) ;
    print(output,n*k) ;
}
