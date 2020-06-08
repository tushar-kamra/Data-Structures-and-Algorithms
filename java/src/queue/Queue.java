package queue;

class Node {
	int data;
	Node next;

	Node(int data) {
		this.data = data;
		this.next = null;
	}
}

public class Queue {
	Node front, rear ;
	void push(int x) {
		Node temp = new Node(x) ;
		if(front == null && rear == null) {
			front = rear = temp ;
			return ;
		}
		rear.next = temp ;
		rear = temp ;
		return ;
	}
	
	void pop() {
		if(front == null) {
			return ;
		}
		if(front == rear) {
			front = rear = null ;
			return ;
		}
		front = front.next ;
		return ;
	}
	
	void print() {
		Node start = front ;
		while(start != null) {
			System.out.println(start.data) ;
			start= start.next ;
		}
	}
	public static void main(String[] args) {
		Queue q = new Queue();
		q.push(10);
		q.push(30);
		q.push(20);
		q.push(0);
		q.push(-110);
		q.push(90);
		q.print();
		q.pop();
		q.pop();
		q.print();
	}

}
