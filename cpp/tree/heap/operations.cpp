#include<iostream>
#include<climits>
using namespace std ;

class Heap {
    int capacity ;
    int size ;
    int *arr ;
    public :
        Heap(int n) ;
        void insertion(int key) ;
        void deletion(int i) ;
        void increaseKey(int i, int key) ;
        void decreaseKey(int i, int key) ;
        int extractMax() ;
        void printHeap() ;
        void maxHeapify(int i) ;
}; 

Heap::Heap(int n){
    capacity = n ;
    size = 0 ;
    arr = new int[n] ;
}

void Heap::insertion(int key){
    if(size == capacity){
        cout << "Heap is full !\n" ;
        return ;
    }
    size++ ;
    int i = size-1 ;
    arr[i] = key ;
    while(i!=0 && arr[i/2] < arr[i]){
        swap(arr[i], arr[i/2]) ;
        i = i/2 ;
    }
}

void Heap::maxHeapify(int i){
    int largest = i ;
    int l = 2*i+1 ;
    int r = 2*i+2 ;
    if(l<size && arr[l] > arr[largest]){
        largest = l ;
    }
    if(r<size && arr[r] > arr[largest]){
        largest = r ;
    }
    if(i != largest){
        swap(arr[i],arr[largest]) ;
        maxHeapify(largest) ;
    }
}

void Heap::increaseKey(int i, int key){
    arr[i] = key ;
    while(i!=0 && arr[i] > arr[i/2]){
        swap(arr[i],arr[i/2]) ;
        i = i/2 ;
    }
}

void Heap::decreaseKey(int i, int key){
    arr[i] = key ;
    maxHeapify(i) ;
}

int Heap::extractMax(){
    if(size <= 0){
        return INT_MIN ;
    }
    int root = arr[0] ;
    arr[0] = arr[size-1] ;
    size-- ;
    maxHeapify(0) ;
    return root ;
}

void Heap::deletion(int i){
    increaseKey(i,INT_MAX) ;
    extractMax() ;
}

void Heap::printHeap(){
    for(int i=0; i<size; i++){
        cout << arr[i] <<" " ;
    }
    cout << endl ;
}

int main(){
    Heap h(11) ;
    h.insertion(1) ;
    h.insertion(3) ;
    h.insertion(5) ;
    h.insertion(4) ;
    h.insertion(6) ;
    h.insertion(13) ;
    h.insertion(10) ;
    h.insertion(9) ;
    h.insertion(8) ;
    h.insertion(15) ;
    h.insertion(17) ;
    h.printHeap() ;
    cout << "Extract Max : " << h.extractMax() << endl ;
    h.printHeap() ;
    cout << "Extract Max : " << h.extractMax() << endl ;
    h.printHeap() ;
    cout << "Extract Max : " << h.extractMax() << endl ;
    h.printHeap() ;
    h.deletion(5) ;
    cout << "After Deletion : " ;
    h.printHeap() ;
    h.insertion(25) ;
    h.insertion(21) ;
    h.printHeap() ;
    cout << "After increasing key : \n" ;
    h.increaseKey(6,11) ;
    h.printHeap() ;
    h.decreaseKey(4,0) ;
    h.printHeap() ;
}
