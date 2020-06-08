package linkedlist;

public class middle {
	static Node middleNode(Node head) {
		Node slow = head;
		Node fast = head;
		while (fast != null && fast.next != null) {
			slow = slow.next;
			fast = fast.next.next;
		}
		return slow;

	}

	public static void main(String[] args) {
		LinkedList list = new LinkedList();
		list.insertAtEnd(10);
		list.insertAtEnd(20);
		list.insertAtEnd(30);
		list.insertAtEnd(40);
		list.insertAtEnd(50);
		list.insertAtEnd(60);
		list.print();
		System.out.println();
		Node mid = middleNode(list.head);
		System.out.println(mid.data);

	}

}
