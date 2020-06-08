package sorting;

import java.util.Scanner;

public class Sorting {

	static void selectionSort(int a[]) {
		for (int i = 0; i < a.length; i++) {
			int min_idx = i;
			for (int j = i + 1; j < a.length; j++) {
				if (a[j] < a[min_idx]) {
					min_idx = j;
				}
			}
			int temp = a[min_idx];
			a[min_idx] = a[i];
			a[i] = temp;
		}
	}

	static void bubbleSort(int a[]) {
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a.length - i - 1; j++) {
				if (a[j] > a[j + 1]) {
					int temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}

	static void insertionSort(int a[]) {
		for (int i = 1; i < a.length; i++) {
			int key = a[i];
			int j = i - 1;
			while (j >= 0 && a[j] > key) {
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = key;
		}
	}


	

	static void print(int a[]) {
		for (int i = 0; i < a.length; i++) {
			System.out.print(a[i] + " ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		System.out.print("Before : \n");
		print(a);
//		selectionSort(a);
//		bubbleSort(a);
		insertionSort(a);
		System.out.print("After : \n");
		print(a);
	}

}
