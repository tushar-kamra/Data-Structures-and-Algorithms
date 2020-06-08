package linkedlist;

import java.util.*;

//Node of a linked list
	 class Node {
		int data;
		Node next;

		Node(int d) {
			data = d;
			next = null;
		}
	}

public class LinkedList {
	// head of list
	Node head;


	void insertAtBeg(int data) {
		Node temp = new Node(data);
		temp.next = head;
		head = temp;
	}

	void insertAtEnd(int data) {
		Node temp = new Node(data);
		if (head == null) {
			head = temp;
			return;
		}
		Node n = head;
		while (n.next != null) {
			n = n.next;
		}
		n.next = temp;
		return;
	}

	void insertAtPos(int pos, int data) {
		Node temp = new Node(data);
		if (pos == 1) {
			temp.next = head;
			head = temp;
			return;
		}
		Node temp2 = head;
		for (int i = 1; i < pos - 1; i++) {
			temp2 = temp2.next;
		}
		Node fwd = temp2.next;
		temp2.next = temp;
		temp.next = fwd;
		return;
	}

	void deleteAtBeg() {
		if (head == null)
			return;
		head = head.next;

	}

	void deleteAtEnd() {
		Node temp = head;
		Node prev = null;
		while (temp.next != null) {
			prev = temp;
			temp = temp.next;
		}
		prev.next = null;
	}

	void print() {
		Node n = head;
		while (n != null) {
			System.out.print(n.data + " ");
			n = n.next;
		}
	}

	Node middle() {
		Node slow = head;
		Node fast = head;
		while (fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;
		}
		return slow;
	}

	int length(Node head) {
		if (head == null)
			return 0;
		return 1 + length(head.next);
	}

	void reverse(Node headref) {
		if (headref.next == null) {
			head = headref;
			return;
		}
		reverse(headref.next);
		Node temp = headref.next;
		temp.next = headref;
		headref.next = null;
	}

	static Node SortedMerge(Node a, Node b) {
		if (a == null)
			return b;
		if (b == null)
			return a;
		if (a.data < b.data) {
			a.next = SortedMerge(a.next, b);
			return a;
		} else {
			b.next = SortedMerge(a, b.next);
			return b;
		}
	}

	public static void main(String[] args) {

		LinkedList list = new LinkedList();
		
		list.insertAtEnd(101);
		list.insertAtBeg(10);
		list.insertAtBeg(40);
		list.insertAtEnd(102);
		list.insertAtBeg(20);
		list.insertAtEnd(103);
		list.insertAtBeg(50);
		list.insertAtEnd(104);
		list.insertAtBeg(30);
		list.insertAtEnd(105);
		list.insertAtPos(4, 200);
		list.insertAtPos(1, 201);
		list.insertAtPos(7, 202);
		System.out.println("List :");
		list.print();
		list.deleteAtEnd();
		list.deleteAtEnd();
		System.out.println();
		System.out.println("List :");
		list.print();
		list.deleteAtBeg();
		System.out.println();
		System.out.println("List :");
		list.print();
		System.out.println();
		
		// Middle
		Node mid = list.middle();
		System.out.println("Middle : " + mid.data);
		
		// Length
		System.out.println("Length : " + list.length(list.head));
		
		// Reverse
		System.out.println("Reverse :");
		list.reverse(list.head);
		list.print();
		System.out.println();
		
		// Merge sorted linked list 
		LinkedList list1 = new LinkedList() ;
		LinkedList list2 = new LinkedList() ;
		list1.insertAtEnd(10); 
		list1.insertAtEnd(20);
		list1.insertAtEnd(30);
		list1.insertAtEnd(40);
		list2.insertAtEnd(12);
		list2.insertAtEnd(18);
		list2.insertAtEnd(29);
		LinkedList res = new LinkedList() ;
		res.head = SortedMerge(list1.head,list2.head);
		res.print();
		System.out.println();
	}

}
