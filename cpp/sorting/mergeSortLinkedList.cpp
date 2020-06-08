#include<iostream>
using namespace std ;

struct Node {
    int data ;
    Node* next ;
};

void insert(Node** headRef, int x){
    Node* temp = new Node() ;
    temp->data = x ;
    temp->next = NULL ;
    if(*headRef == NULL){
        *headRef = temp ;
        return ;
    }
    temp->next = *headRef ;
    *headRef = temp ;
}

void print(Node* head){
    while(head){
        cout << head->data << " " ;
        head = head->next ;
    }
}

Node* merge(Node* h1, Node* h2){
    Node* curr = NULL ;
    if(!h1) return h2 ;
    if(!h2) return h1 ;
    if(h1->data <= h2->data){
        curr = h1 ;
        curr->next = merge(h1->next,h2) ;
    }
    else {
        curr = h2 ;
        curr->next = merge(h1,h2->next) ;
    }
    return curr ;
}

void mergeSort(Node** head){
    if(*head == NULL || (*head)->next == NULL){
        return  ;
    }
    Node* prev ;
    Node* slow = *head ;
    Node* fast = *head ;
    while(fast && fast->next){
        prev = slow ;
        slow = slow->next ;
        fast = fast->next->next ;
    }
    Node* first = *head ;
    Node* second = slow ;
    prev->next = NULL ;

    mergeSort(&first) ;
    mergeSort(&second) ;
    *head = merge(first,second) ;
}

int main(){
    Node* head = NULL ;
    insert(&head,10);
    insert(&head,8);
    insert(&head,13);
    insert(&head,0);
    insert(&head,-7);
    insert(&head,20);
    insert(&head,9);
    print(head) ;
    cout << endl ;
    mergeSort(&head) ;
    print(head);
}