package pattern;

import java.util.*;

public class diamond {

	void message(int n) {
		System.out.println("Diamond with number of rows = " + n);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, nsp, nst;
		n = sc.nextInt();
		diamond d = new diamond();
		d.message(n);
		nsp = n / 2;
		nst = 1;
		for (int r = 1; r <= n; r++) {
			for (int csp = 1; csp <= nsp; csp++) {
				System.out.print(" ");
			}
			for (int cst = 1; cst <= nst; cst++) {
				System.out.print("*");
			}
			if (r <= n / 2) {
				nst += 2;
				nsp--;
			} else {
				nsp++;
				nst -= 2;
			}
			System.out.println();
		}
	}
}
