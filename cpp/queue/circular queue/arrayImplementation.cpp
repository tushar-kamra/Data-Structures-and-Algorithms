#include<iostream>
using namespace std ;

class Queue {
    int front, rear, capacity ;
    int *queue ;
    public :
        Queue(int c){
            front = rear = -1 ;
            capacity = c ;
            queue = new int[c] ;
        }
        void enqueue(int x){
            // if queue is full
            if((front == 0 && rear == capacity-1) || (front!=0 && rear == front-1)){
                cout << "Queue is full...\n" ;
            }
            // insert first element
            else if(front == -1){
                front = rear = 0 ;
                queue[rear] = x ;
            }
            // circular insertion
            else if(front!=0 && rear == capacity-1){
                rear = 0 ;
                queue[rear] = x ;
            }
            // normal insertion
            else {
                rear++ ;
                queue[rear] = x ;
            }
        }
        void dequeue(){
            if(front == -1){
                cout << "Queue is empty...\n" ;
            }
            else if(front == rear){
                front = rear = -1 ;
            }
            else if(front == capacity-1){
                front = 0 ;
            }
            else {
                front++ ;
            }
        }
        void print(){
            if(front == -1) return;
            if(front <= rear){
                for(int i=front; i<=rear; i++){
                    cout << queue[i] <<" " ;
                }
            }
            else {
                for(int i=front; i<capacity; i++){
                    cout << queue[i] <<" " ;
                }
                for(int i=0; i<=rear ; i++){
                    cout << queue[i] <<" " ;
                }
            }
            cout << endl ;
        }
};

int main(){
    Queue q(5) ;
    q.enqueue(10) ;
    q.enqueue(20) ;
    q.enqueue(30) ;
    q.print() ;
    q.enqueue(40) ;
    q.enqueue(50) ;
    q.print() ;
    q.enqueue(60) ;
    q.print() ;
    q.dequeue() ;
    q.print() ;
    q.dequeue() ;
    q.dequeue() ;
    q.print() ;
    q.enqueue(70) ;
    q.print() ;
}

