package tree.bst;

class Node {
	int data;
	Node left;
	Node right;

	Node(int data) {
		this.data = data;
		left = right = null;
	}
}

public class BST {
	Node root;

	// Insertion
	Node insert(Node rootref, int x) {
		if (rootref == null) {
			rootref = new Node(x);
			return rootref;
		} else if (rootref.data >= x) {
			rootref.left = insert(rootref.left, x);
		} else {
			rootref.right = insert(rootref.right, x);
		}
		return rootref;
	}

	// Inorder
	void inorder(Node root) {
		if (root == null) {
			return;
		}
		inorder(root.left);
		System.out.print(root.data + " ");
		inorder(root.right);
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

	public static void main(String[] args) {
		BST bst = new BST();
		bst.root = bst.insert(bst.root, 10);
		bst.root = bst.insert(bst.root, 6);
		bst.root = bst.insert(bst.root, 9);
		bst.root = bst.insert(bst.root, 1);
		bst.root = bst.insert(bst.root, 15);
		bst.root = bst.insert(bst.root, 27);
		bst.root = bst.insert(bst.root, 3);
		System.out.println("Inorder :");
		bst.inorder(bst.root);
	}

}
