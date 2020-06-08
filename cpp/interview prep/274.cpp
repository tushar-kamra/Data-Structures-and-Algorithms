#include <iostream>
using namespace std;

class Node {
    public :
        int data ;
        Node* next ;
        Node(){
            
        }
        Node(int x){
            data = x ;
            next = NULL ;
        }
};

Node* createNode(int x){
    Node* temp = new Node(x) ;
    return temp ;
}

void insert(Node** start, Node** end, int x){
    Node* temp = createNode(x) ;
    if(*start == NULL){
        *start = temp ;
        *end = *start ;
    }
    else {
        (*end)->next = temp ;
        *end = temp ;
    }
}

void print(Node* head){
    while(head){
        cout << head->data <<" " ;
        head = head->next ;
    }
}

int main() {
	int t ;
	cin >> t ;
	while(t--){
	    int n ;
	    cin >> n ;
	    Node* eStart=NULL, *eEnd=NULL, *oStart=NULL, *oEnd=NULL ;
	    while(n--){
	        int x ;
	        cin >> x ;
	        if(x%2 == 0){
	            insert(&eStart,&eEnd,x) ;
	        }
	        else {
	            insert(&oStart,&oEnd,x) ;
	        }
	    }
        if(eStart == NULL){
            print(oStart) ;
        }
        else {
            eEnd->next = oStart ;
            oEnd->next = NULL ;
            print(eStart) ;
        }
	    cout << endl ;
	}
	return 0;
}