#include<iostream>
using namespace std ;

class Queue {
    int front ;
    int rear ;
    int capacity ;
    int *queue ;
    public :
        Queue(int c) {
            front = rear = 0 ;
            capacity = c ;
            queue = new int[c] ;
        }
        void enqueue(int x){
            if(rear == capacity){
                cout << "Overflow...\n" ;
                return ;
            }
            queue[rear++] = x ;
        }
        void dequeue(){
            if(front == rear){
                cout << "Underflow...\n" ;
                return ;
            }
            for(int i=0; i<rear-1; i++){
                queue[i] = queue[i+1] ;
            }
            rear-- ;
        }
        void print(){
            for(int i=front; i<rear; i++){
                cout << queue[i]<<" " ;
            }
            cout << endl ;
        }
};

int main(){
    Queue q(5);
    q.enqueue(20) ;
    q.enqueue(30) ;
    q.enqueue(40) ;
    q.enqueue(50) ;
    q.print() ;
    q.dequeue() ;
    q.print() ;
    q.enqueue(80) ;
    q.print() ;
    q.dequeue() ;
    q.dequeue() ;
    q.print() ;
    q.enqueue(30) ;
    q.enqueue(40) ;
    q.enqueue(50) ;
    q.print() ;
    q.enqueue(30) ;
    q.enqueue(40) ;
    q.enqueue(50) ;
    q.print() ;
}