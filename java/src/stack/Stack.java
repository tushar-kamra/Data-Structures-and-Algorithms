package stack;

class Node {
	int data ;
	Node next ;
	Node(int data){
		this.data = data ;
		this.next = null ;
	}
}

public class Stack {
	
	Node top ;
	void push(int x) {
		Node temp = new Node(x) ;
		if(top == null) {
			top = temp ;
			return ;
		}
		temp.next = top ;
		top = temp ;
		return ;
	}
	
	int pop() {
		if(top == null)  return -1 ;
		Node temp = top ;
		top = top.next ;
		return temp.data ;
	}
	
	void print() {
		Node temp = top ;
		while(temp!=null) {
			System.out.println(temp.data);
			temp = temp.next ;
		}
	}
	public static void main(String[] args) {
		
		Stack st = new Stack();
		
		st.push(10);
		st.push(20);
		st.push(10);
		st.push(30);
		st.push(40);
		st.print();
		st.pop();
		st.print();
	}

}
