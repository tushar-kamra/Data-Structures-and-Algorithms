#include<iostream>
using namespace std ;

class Node {
    public :
        int data ;
        Node* next ;
        Node(int x){
            data = x ;
            next = NULL ;
        }
};

class Queue {
    Node* front, *rear ;
    public :
        Queue(){
            front = NULL ;
            rear = NULL ;
        }
        void enqueue(int x){
            Node* temp = new Node(x) ;
            if(front == NULL){
                front = temp ;
                rear = front ;
            }
            else {
                rear->next = temp ;
                rear = temp ;
            }
        }
        void dequeue(){
            if(front == NULL) {
                return ;
            }
            Node* temp = front ;
            front = front->next ;
            delete temp ;
            if(front == NULL){
                rear = NULL ;
            }
        }
        void print(){
            Node* temp = front ;
            while(temp!=NULL){
                cout << temp->data <<" " ;
                temp = temp->next ;
            }
            cout << endl ;
        }
};

int main(){
    Queue q ;
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