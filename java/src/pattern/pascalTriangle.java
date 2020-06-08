package pattern;

import java.util.Scanner;

public class pascalTriangle {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int row = sc.nextInt();
		for (int n = 0; n < row; n++) {
			int val = 1;
			for (int r = 0; r <= n; r++) {
				System.out.print(val + " ");
				val *= (n - r);
				val /= (r + 1);
			}
			System.out.println();
		}
	}

}
