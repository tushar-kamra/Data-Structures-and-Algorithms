package heap;

import java.util.Scanner;

public class Heap {

	static void buildHeap(int a[], int size) {
		int i = size / 2 - 1;
		for (int j = i; j >= 0; j--) {
			maxHeapify(a, j, size);
		}
	}

	static int extractMax(int a[], int size) {
		int root = a[0];
		a[0] = a[size-1] ;
		size-- ;
		maxHeapify(a,0,size) ;
		return root;
	}

	static void maxHeapify(int[] a, int i, int size) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < size && a[left] > a[largest])
			largest = left;
		if (right < size && a[right] > a[largest])
			largest = right;
		if (largest != i) {
			int temp = a[i];
			a[i] = a[largest];
			a[largest] = temp;
			maxHeapify(a, largest, size);
		}
	}

	static void print(int[] a, int size) {
		for (int i = 0; i < size; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}

	static void heapsort(int a[], int size) {
		for (int i = size - 1; i >= 0; i--) {
			int temp = a[i];
			a[i] = a[0];
			a[0] = temp;
			maxHeapify(a, 0, i);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;
		int a[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };
		n = a.length ;
		buildHeap(a, n);
		System.out.print("Heap : \n");
		print(a, n);
//		System.out.print("HeapSort : \n");
//		heapsort(a, n);
//		print(a, n);
		for(int i=1; i<=4; i++) {
			System.out.print(extractMax(a,n) +" ");
		}
	}

}
