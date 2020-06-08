package recursion;

import java.util.Arrays;
import java.util.Scanner;

public class recursion {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int m, n;
		m = sc.nextInt();
		n = sc.nextInt();
		boolean[][] visit = new boolean[m][n];
		for (boolean[] row : visit) {
			Arrays.fill(row, false);
		}
		System.out.print(floodfill(0, 0, m-1, n-1, visit));

	}

	public static boolean isValid(int x, int y, boolean[][] v) {
		if (x < 0 || x >= v.length || y < 0 || y >= v[0].length || v[x][y] == true) {
			return false;
		}
		return true;
	}

	public static int floodfill(int x1, int y1, int x2, int y2, boolean[][] v) {
		if (x1 == x2 && y1 == y2) {
			return 1;
		}
		int c = 0;
		v[x1][y1] = true;
		if (isValid(x1 + 1, y1, v)) {
			c += floodfill(x1 + 1, y1, x2, y2, v);
		}
		if (isValid(x1 - 1, y1, v)) {
			c += floodfill(x1 - 1, y1, x2, y2, v);
		}
		if (isValid(x1, y1 + 1, v)) {
			c += floodfill(x1, y1 + 1, x2, y2, v);
		}
		if (isValid(x1, y1 - 1, v)) {
			c += floodfill(x1, y1 - 1, x2, y2, v);
		}
		v[x1][y1] = false;
		return c;
	}

}
