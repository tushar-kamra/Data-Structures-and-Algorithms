package tree.bt;

import java.util.*;

class Node {
	int data;
	Node left;
	Node right;

	Node(int x) {
		this.data = x;
		left = right = null;
	}
}

class pair {
	int hd;
	Node n;

	pair(int hd, Node n) {
		this.hd = hd ;
		this.n = n;
	}
}

public class binaryTree {
	Node root, head, prev;
	int max_level = 0;
	int dia = Integer.MIN_VALUE;
	TreeMap<Integer, Vector<Integer>> map = new TreeMap<Integer, Vector<Integer>>();
	Vector<Integer> ksum = new Vector<Integer>();

	// Insert a node
	void insert(int x) {
		if (root == null) {
			root = new Node(x);
			return;
		}
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		while (!q.isEmpty()) {
			Node curr = q.remove();
			if (curr.left != null) {
				q.add(curr.left);
			} else {
				curr.left = new Node(x);
				break;
			}
			if (curr.right != null) {
				q.add(curr.right);
			} else {
				curr.right = new Node(x);
				break;
			}
		}
	}

	// Preorder
	void preorder(Node root) {
		if (root == null)
			return;
		System.out.print(root.data + " ");
		preorder(root.left);
		preorder(root.right);
	}

	// Inorder
	void inorder(Node root) {
		if (root == null)
			return;
		inorder(root.left);
		System.out.print(root.data + " ");
		inorder(root.right);
	}

	// Postorder
	void postorder(Node root) {
		if (root == null)
			return;
		postorder(root.left);
		postorder(root.right);
		System.out.print(root.data + " ");
	}

	// Iterative preorder - Method 1 (using stack)
	void iterPreorder1(Node root) {
		Stack<Node> s = new Stack<Node>();
		while (true) {
			while (root != null) {
				System.out.print(root.data + " ");
				s.push(root);
				root = root.left;
			}
			if (s.isEmpty()) {
				break;
			}
			root = s.pop();
			root = root.right;
		}
	}

	// Iterative preorder - Method 2 (using stack)
	void iterPreorder2(Node root) {
		Stack<Node> s = new Stack<Node>();
		s.add(root);
		while (!s.isEmpty()) {
			root = s.pop();
			System.out.print(root.data + " ");
			if (root.right != null) {
				s.push(root.right);
			}
			if (root.left != null) {
				s.push(root.left);
			}
		}
	}

	// Iterative inorder - Method 1 (using stack)
	void iterInorder1(Node root) {
		Stack<Node> s = new Stack<Node>();
		while (true) {
			while (root != null) {
				s.push(root);
				root = root.left;
			}
			if (s.isEmpty()) {
				break;
			}
			root = s.pop();
			System.out.print(root.data + " ");
			root = root.right;
		}
	}

	// Iterative postorder - Method 1 (using 2 stacks)
	void iterPostorder1(Node root) {
		Stack<Node> s1 = new Stack<Node>();
		Stack<Node> s2 = new Stack<Node>();
		s1.add(root);
		while (!s1.isEmpty()) {
			Node temp = s1.pop();
			s2.push(temp);
			if (temp.left != null)
				s1.push(temp.left);
			if (temp.right != null)
				s1.push(temp.right);
		}
		while (!s2.isEmpty()) {
			System.out.print(s2.pop().data + " ");
		}
	}

	// Maximum value
	int maximum(Node root) {
		if (root == null)
			return Integer.MIN_VALUE;
		int left = maximum(root.left);
		int right = maximum(root.right);
		return Integer.max(root.data, Integer.max(left, right));
	}

	// Height
	int height(Node root) {
		if (root == null) {
			return 0;
		}
		int lh = height(root.left);
		int rh = height(root.right);
		dia = Integer.max(dia, lh + rh + 1);
		return Integer.max(lh, rh) + 1;
	}

	// Level order traversal
	void levelOrder(Node root) {
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		while (!q.isEmpty()) {
			Node temp = q.remove();
			System.out.print(temp.data + " ");
			if (temp.left != null)
				q.add(temp.left);
			if (temp.right != null)
				q.add(temp.right);
		}
	}

	// Line by line Level order traversal - Method 1 : O(n^2)
	void printLevelOrder1(Node root) {
		int h = height(root);
		for (int i = 1; i <= h; i++) {
			printGivenLevel(root, i);
			System.out.println();
		}
	}

	void printGivenLevel(Node root, int level) {
		if (root == null)
			return;
		if (level == 1) {
			System.out.print(root.data + " ");
		}
		printGivenLevel(root.left, level - 1);
		printGivenLevel(root.right, level - 1);
	}

	// Line by line Level order traversal - Method 2 : O(n) using 2 queues
	void printLevelOrder2(Node root) {
		Queue<Node> q1 = new LinkedList<Node>();
		Queue<Node> q2 = new LinkedList<Node>();
		q1.add(root);
		while (!q1.isEmpty() || !q2.isEmpty()) {
			while (!q1.isEmpty()) {
				Node temp = q1.remove();
				System.out.print(temp.data + " ");
				if (temp.left != null) {
					q2.add(temp.left);
				}
				if (temp.right != null) {
					q2.add(temp.right);
				}
			}
			System.out.println();
			while (!q2.isEmpty()) {
				Node temp = q2.remove();
				System.out.print(temp.data + " ");
				if (temp.left != null) {
					q1.add(temp.left);
				}
				if (temp.right != null) {
					q1.add(temp.right);
				}
			}
			System.out.println();
		}

	}

	// Line by line Level order traversal - Method 3 : O(n) using 1 queue and a
	// delimiter
	void printLevelOrder3(Node root) {
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		q.add(null);
		while (!q.isEmpty()) {
			Node temp = q.remove();
			if (temp == null) {
				if (q.isEmpty()) {
					break;
				} else {
					System.out.println();
					q.add(null);
				}
			} else {
				System.out.print(temp.data + " ");
				if (temp.left != null)
					q.add(temp.left);
				if (temp.right != null)
					q.add(temp.right);
			}

		}
	}

	// Print left view - Method 1 using level order
	void leftView1(Node root) {
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		while (!q.isEmpty()) {
			int n = q.size();
			for (int i = 1; i <= n; i++) {
				Node temp = q.remove();
				if (i == 1)
					System.out.print(temp.data + " ");
				if (temp.left != null)
					q.add(temp.left);
				if (temp.right != null)
					q.add(temp.right);
			}
		}
	}

	// Print left view = Method 2 using recursion by tracking level
	void leftView2(Node root, int level) {
		if (root == null)
			return;
		if (level > max_level) {
			max_level = level;
			System.out.println(root.data);
		}
		leftView2(root.left, level + 1);
		leftView2(root.right, level + 1);
	}

	// Diameter - Method 1 : O(n^2)
	int diameter1(Node root) {
		if (root == null)
			return 0;
		int lh = height(root.left);
		int rh = height(root.right);
		int ld = diameter1(root.left);
		int rd = diameter1(root.right);
		return Integer.max(lh + rh + 1, Integer.max(ld, rd));
	}

	// Diameter - Method 2 : O(n)
	int diameter2(Node root) {
		int h = height(root);
		return dia;
	}

	// Sum of all nodes
	int sum(Node root) {
		if (root == null) {
			return 0;
		}
		int ans = root.data + sum(root.left) + sum(root.right);
		return ans;
	}

	// Ancestor of given key
	boolean ancestor(Node root, int key) {
		if (root == null) {
			return false;
		}
		if (root.data == key) {
			return true;
		}
		if ((ancestor(root.left, key)) || (ancestor(root.right, key))) {
			System.out.print(root.data + " ");
			return true;
		}
		return false;
	}

	// Boundary traversal
	void boundaryTraversal(Node root) {
		if (root == null)
			return;
		System.out.print(root.data + " ");
		printLeftbdr(root.left);
		printLeaf(root.left);
		printLeaf(root.right);
		printRightbdr(root.right);
	}

	void printLeftbdr(Node root) {
		if (root != null) {
			if (root.left != null) {
				System.out.print(root.data + " ");
				printLeftbdr(root.left);
			} else if (root.right != null) {
				System.out.print(root.data + " ");
				printLeftbdr(root.right);
			}
		}
	}

	void printLeaf(Node root) {
		if (root != null) {
			if (root.left == null && root.right == null) {
				System.out.print(root.data + " ");
			}
			printLeaf(root.left);
			printLeaf(root.right);
		}
	}

	void printRightbdr(Node root) {
		if (root != null) {
			if (root.right != null) {
				printRightbdr(root.right);
				System.out.print(root.data + " ");
			} else if (root.left != null) {
				printRightbdr(root.left);
				System.out.print(root.data + " ");
			}
		}
	}

	// Print all nodes at distance 'k' from root
	void printAtK(Node root, int k) {
		if (root == null) {
			return;
		}
		if (k == 0) {
			System.out.print(root.data + " ");
		}
		printAtK(root.left, k - 1);
		printAtK(root.right, k - 1);
	}

	// Spiral order
	void spiral(Node root) {
		Stack<Node> s1 = new Stack<Node>();
		Stack<Node> s2 = new Stack<Node>();
		s1.push(root);
		while (!s1.isEmpty() || !s2.isEmpty()) {
			while (!s1.isEmpty()) {
				Node temp = s1.pop();
				System.out.print(temp.data + " ");
				if (temp.right != null)
					s2.push(temp.right);
				if (temp.left != null)
					s2.push(temp.left);

			}
			while (!s2.isEmpty()) {
				Node temp = s2.pop();
				System.out.print(temp.data + " ");
				if (temp.left != null)
					s1.push(temp.left);
				if (temp.right != null)
					s1.push(temp.right);

			}
		}
	}

	// Nodes with 'k' leaves
	int kLeaves(Node root, int k) {
		if (root == null)
			return 0;
		if (root.left == null && root.right == null) {
			return 1;
		}
		int left = kLeaves(root.left, k);
		int right = kLeaves(root.right, k);
		if (left + right == k) {
			System.out.print(root.data + " ");
		}
		return left + right;
	}

	// Vertical order - Method 1 using recursion
	void verticalOrder1(Node root, int hd) {
		if (root == null) {
			return;
		}
		Vector<Integer> v = map.get(hd);
		if (v == null) {
			v = new Vector<Integer>();
			v.add(root.data);
		} else {
			v.add(root.data);
		}
		map.put(hd, v);
		verticalOrder1(root.left, hd - 1);
		verticalOrder1(root.right, hd + 1);
	}

	// Vertical order - Method 2 using level order
	void verticalOrder2(Node root) {
		int hd = 0;
		Queue<pair> q = new LinkedList<pair>();
		pair p = new pair(hd, root);
		q.add(p);
		while (!q.isEmpty()) {
			pair curr = q.remove();
			hd = curr.hd;
			Node temp = curr.n;
			Vector<Integer> v = map.get(hd);
			if (v == null) {
				v = new Vector<Integer>();
				v.add(temp.data);
			} else {
				v.add(temp.data);
			}
			map.put(hd, v);
			if (temp.left != null) {
				q.add(new pair(hd - 1, temp.left));
			}
			if (temp.right != null) {
				q.add(new pair(hd + 1, temp.right));
			}
		}
	}

	// Top view of tree
	void topView(Node root) {
		int hd = 0;
		Queue<pair> q = new LinkedList<pair>();
		q.add(new pair(hd, root));
		Node temp;
		while (!q.isEmpty()) {
			pair curr = q.remove();
			hd = curr.hd;
			temp = curr.n;
			Vector<Integer> v = map.get(hd);
			if (v == null) {
				v = new Vector<Integer>();
				v.add(temp.data);
				map.put(hd, v);
			}
			if (temp.left != null) {
				q.add(new pair(hd - 1, temp.left));
			}
			if (temp.right != null) {
				q.add(new pair(hd + 1, temp.right));
			}
		}
	}

	// Diagnol - Method 1 using HashMap and recursion
	void diagnol1(Node root, int d) {
		if (root == null)
			return;
		Vector<Integer> v = map.get(d);
		if (v == null) {
			v = new Vector<Integer>();
			v.add(root.data);
		} else {
			v.add(root.data);
		}
		map.put(d, v);
		diagnol1(root.left, d + 1);
		diagnol1(root.right, d);
	}

	// Diagnol - Method 2 using Queue
	void diagnol2(Node root) {
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		q.add(null);
		while (!q.isEmpty()) {
			Node temp = q.remove();
			if (temp == null) {
				q.add(null);
				System.out.println();
				if (q.peek() == null) {
					break;
				}
			}
			while (temp != null) {
				System.out.print(temp.data + " ");
				if (temp.left != null)
					q.add(temp.left);
				temp = temp.right;
			}
		}
	}

	// BT -> DLL - Method 1 using BFS
	void bt2dll1(Node root) {
		Node prev = null;
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		while (!q.isEmpty()) {
			Node curr = q.remove();
			Node temp = new Node(curr.data);
			if (prev == null) {
				head = temp;
			} else {
				temp.left = prev;
				prev.right = temp;
			}
			prev = temp;
			if (curr.left != null)
				q.add(curr.left);
			if (curr.right != null)
				q.add(curr.right);
		}
	}

	void print(Node head) {
		Node end = head;
		while (head != null) {
			end = head;
			System.out.print(head.data + " ");
			head = head.right;
		}
		System.out.println();
		while (end != null) {
			System.out.print(end.data + " ");
			end = end.left;
		}
	}

	// BT -> DLL - Method 2 using inorder
	void bt2dll2(Node root) {
		if (root == null)
			return;
		bt2dll2(root.left);
		if (prev == null) {
			head = root;
		} else {
			root.left = prev;
			prev.right = root;
		}
		prev = root;
		bt2dll2(root.right);
	}

	// Is BT a BST ?
	boolean isBST(Node root, int min, int max) {
		if (root == null)
			return true;
		if (root.data > min && root.data < max) {
			if (isBST(root.left, min, root.data) && isBST(root.right, root.data, max)) {
				return true;
			}
		}
		return false;
	}

	// kSum path from any node to any node in downward direction
	void ksumpath1(Node root, int k) {
		if (root == null) {
			return;
		}
		ksum.add(root.data);
		ksumpath1(root.left, k);
		ksumpath1(root.right, k);
		int sum = 0;
		for (int j = ksum.size() - 1; j >= 0; j--) {
			sum += ksum.get(j);
			if (sum == k) {
				printVector(j);
			}
		}
		ksum.remove(ksum.size() - 1);
	}

	void printVector(int idx) {
		for (int i = idx; i < ksum.size(); i++) {
			System.out.print(ksum.get(i) + " ");
		}
		System.out.println();
	}

	// Distance from root
	int level(Node root, int key, int c) {
		if (root == null)
			return -1;
		if (root.data == key) {
			return c;
		}
		int left = level(root.left, key, c + 1);
		if (left == -1) {
			return level(root.right, key, c + 1);
		}
		return left;
	}

	public static void main(String[] args) {
		binaryTree bt = new binaryTree();
		bt.insert(2);
		bt.insert(7);
		bt.insert(3);
		bt.insert(11);
		bt.insert(1);
		bt.insert(4);
		bt.insert(9);
		bt.insert(100);
		bt.insert(200);
		bt.insert(300);
		bt.insert(400);
		bt.insert(500);

//		bt.insert(1);
//		bt.insert(3);
//		bt.insert(-1);
//		bt.insert(2);
//		bt.insert(1);
//		bt.insert(4);
//		bt.insert(5);
//		bt.insert(0);
//		bt.insert(0);
//		bt.insert(1);
//		bt.insert(0);
//		bt.insert(1);
//		bt.insert(2);
//		bt.insert(0);
//		bt.insert(6);

//		System.out.println("Preorder :");
//		bt.preorder(bt.root);
//		System.out.println();
//		System.out.println("Inorder :");
//		bt.inorder(bt.root);
//		System.out.println();
//		System.out.println("Postorder :");
//		bt.postorder(bt.root);
//		System.out.println();
//		bt.iterPreorder1(bt.root);
//		bt.iterPreorder2(bt.root);
//		System.out.println();
//		bt.inorder(bt.root);
//		bt.iterInorder1(bt.root);
//		bt.iterPostorder1(bt.root);
//		System.out.println(bt.maximum(bt.root));
//		System.out.println("Height = " + bt.height(bt.root));
//		bt.levelOrder(bt.root);
//		bt.printLevelOrder1(bt.root);
//		bt.printLevelOrder2(bt.root);
//		bt.printLevelOrder3(bt.root);
//		bt.leftView1(bt.root);
//		bt.leftView2(bt.root,1);
//		System.out.print("Diameter = "+bt.diameter1(bt.root));
//		System.out.print("Diameter : "+bt.diameter2(bt.root));
//		System.out.print("Sum : "+bt.sum(bt.root));
//		if (!bt.ancestor(bt.root, 8)) {
//			System.out.print("No ancestor found");
//		}
//		bt.boundaryTraversal(bt.root);
//		bt.printAtK(bt.root, 2);
//		bt.spiral(bt.root);
//		bt.kLeaves(bt.root, 6);
//		bt.verticalOrder1(bt.root, 0);
//		for (Integer k : bt.map.keySet()) {
//			int key = k;
//			System.out.print(k + "->");
//			for (Integer v : bt.map.get(key)) {
//				System.out.print(v + " ");
//			}
//			System.out.println();
//		}
//		bt.verticalOrder2(bt.root);
//		for (Integer k : bt.map.keySet()) {
//			System.out.print(k + "---->");
//			for (Integer v : bt.map.get(k)) {
//				System.out.print(v + " ");
//			}
//			System.out.println();
//		}
//		bt.topView(bt.root);
//		for (Integer k : bt.map.keySet()) {
//			System.out.print(k + "---->");
//			for (Integer v : bt.map.get(k)) {
//				System.out.print(v + " ");
//			}
//			System.out.println();
//		}
//		bt.diagnol1(bt.root, 0);
//		for (Integer k : bt.map.keySet()) {
//			System.out.print(k + "---->");
//			for (Integer v : bt.map.get(k)) {
//				System.out.print(v + " ");
//			}
//			System.out.println();
//		}
//		bt.diagnol2(bt.root);
//		bt.bt2dll1(bt.root);
//		bt.print(bt.head);
//		bt.bt2dll2(bt.root);
//		bt.print(bt.head);
//		if(bt.isBST(bt.root,Integer.MIN_VALUE, Integer.MAX_VALUE)) {
//			System.out.println("True");
//		}
//		else {
//			System.out.println("False");
//		}
//		bt.ksumpath1(bt.root, 5);
//		System.out.println(bt.level(bt.root, 4, 0));
//		System.out.println(bt.level(bt.root, 400, 0));
//		System.out.println(bt.level(bt.root, 11, 0));
//		System.out.println(bt.level(bt.root, 41, 0));
	}

}
