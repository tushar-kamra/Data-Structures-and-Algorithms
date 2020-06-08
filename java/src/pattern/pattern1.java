package pattern;

import java.util.Scanner;

public class pattern1 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, nsp, nst;
		n = sc.nextInt();
		nsp = n - 1;
		nst = 1;
		for (int r = 1; r <= n; r++) {
			for (int csp = 1; csp <= nsp; csp++) {
				System.out.print(" ");
			}
			for (int cst = 1; cst <= nst; cst++) {
				System.out.print("*");
			}
			nsp--;
			nst += 2;
			System.out.println();
		}
	}
}
