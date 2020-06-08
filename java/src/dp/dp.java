package dp;

import java.util.ArrayList;

public class dp {
	static int c = 0;

	static int countBoardPathMemo(int s, int e, int dp[]) {
		if (s == e) {
			dp[s] = 1;
			return 1;
		}
		if (dp[s] != 0) {
			return dp[s];
		}
		c++;
		int count = 0;
		for (int dice = 1; dice <= 6; dice++) {
			if (s + dice <= e) {
				count += countBoardPathMemo(s + dice, e, dp);
			}
		}
		dp[s] = count;
		return count;
	}

	static int countBoardPathTab(int e, int dp[]) {
		dp[e] = 1;
		for (int i = e - 1; i >= 0; i--) {
			for (int dice = 1; dice <= 6; dice++) {
				if (i + dice <= e) {
					dp[i] += dp[i + dice];
				}
			}
		}
		return dp[0];
	}

	static int countMazePathMemo(int x1, int y1, int x2, int y2, int dp[][]) {
		if (x1 == x2 && y1 == y2) {
			dp[x1][y1] = 1;
			return 1;
		}
		if (dp[x1][y1] != 0) {
			return dp[x1][y1];
		}
		int count = 0;
		if (x1 < x2) {
			count += countMazePathMemo(x1 + 1, y1, x2, y2, dp);
		}
		if (y1 < y2) {
			count += countMazePathMemo(x1, y1 + 1, x2, y2, dp);
		}
		dp[x1][y1] = count;
		return count;
	}

	static int goldmineTab(int cost[][], int dp[][]) {
		int r = cost.length;
		int c = cost[0].length;
		int ans = Integer.MIN_VALUE;
		for (int i = c - 1; i >= 0; i--) {
			for (int j = 0; j < r; j++) {
				if (i == c - 1) {
					dp[j][i] = cost[j][i];
				} else if (j == 0) {
					dp[j][i] = cost[j][i] + Math.max(dp[j][i + 1], dp[j + 1][i + 1]);
				} else if (j == r - 1) {
					dp[j][i] = cost[j][i] + Math.max(dp[j][i + 1], dp[j - 1][i + 1]);
				} else {
					dp[j][i] = cost[j][i] + Math.max(dp[j][i + 1], Math.max(dp[j - 1][i + 1], dp[j + 1][i + 1]));
				}
				ans = Math.max(ans, dp[j][i]);
			}
		}
		return ans;
	}

	static void rodCuttingTab() {
		int profit[] = { 0, 3, 5, 6, 15, 10, 25, 12, 24 };
		int dp[] = new int[9];
		dp[0] = profit[0];
		dp[1] = profit[1];
		for (int i = 2; i < 9; i++) {
			int x = 1, y = i - 1;
			dp[i] = profit[i];
			while (x <= y) {
				if (dp[x] + dp[y] > dp[i]) {
					dp[i] = dp[x] + dp[y];
				}
				x++;
				y--;
			}
		}
		System.out.print(dp[8]);
	}

	static void coinChangeCombinationTab() {
		int denom[] = { 2, 3, 5, 6 };
		int amount = 10;
		int[] dp = new int[amount + 1];
		ArrayList<String>[] path = new ArrayList[amount + 1];
		for (int i = 0; i < path.length; i++) {
			path[i] = new ArrayList<String>();
		}
		dp[0] = 1;
		path[0].add("");

		for (int i = 0; i < denom.length; i++) {
			for (int j = denom[i]; j <= amount; j++) {
				dp[j] = dp[j] + dp[j - denom[i]];
				for (int k = 0; k < path[j - denom[i]].size(); k++) {
					String s = path[j - denom[i]].get(k) + denom[i];
					path[j].add(s);
				}
			}
		}
		System.out.println("Number of ways : " + dp[amount]);
		for (String s : path[amount]) {
			System.out.print(s + "\n");
		}
	}

	static void coinChangePermutationTab() {
		int denom[] = { 2, 3, 5, 6 };
		int amount = 10;
		int[] dp = new int[amount + 1];
		ArrayList<String>[] path = new ArrayList[amount + 1];
		for (int i = 0; i < path.length; i++) {
			path[i] = new ArrayList<String>();
		}
		dp[0] = 1;
		path[0].add("");

		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < denom.length; j++) {
				if (i - denom[j] >= 0) {
					dp[i] = dp[i] + dp[i - denom[j]];
					for (int k = 0; k < path[i - denom[j]].size(); k++) {
						String s = path[i - denom[j]].get(k) + denom[j];
						path[i].add(s);
					}
				}
			}
		}
		System.out.println("Number of ways : " + dp[amount]);
		for (String s : path[amount]) {
			System.out.print(s + "\n");
		}
	}

	static void LIS() {
		int a[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80, 1 };
		int[] dp = new int[10];
		String[] path = new String[10];
		dp[0] = 1;
		path[0] = a[0] + "";
		int max = 0;
		String ans = "";
		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < i; j++) {
				if (a[j] < a[i] && dp[i] < dp[j]) {
					dp[i] = dp[j];
					path[i] = path[j];
				}
			}
			dp[i] += 1;
			path[i] += " " + a[i];
			if (max < dp[i]) {
				max = dp[i];
				ans = path[i];
			}
		}
		System.out.println(max + " @ " + ans);

	}

	public static void main(String[] args) {
//		int[] dp = new int[11];
//		int ans = countBoardPathMemo(0, 10, dp);
//		System.out.println("Count : " + c);
//		System.out.print(ans);
//		int ans = countBoardPathTab(10, dp);
//		System.out.print(ans);
//		int x1 = 0, y1 = 0, x2 = 2, y2 = 2;
//		int[][] dp = new int[x2 + 1][y2 + 1];
//		int ans = countMazePathMemo(x1, y1, x2, y2, dp);
//		System.out.print(ans);
//		int cost[][] = { { 2, 6, 0, 5 }, { 0, 7, 5, 2 }, { 3, 0, 3, 7 }, { 8, 0, 2, 3 } };
//		int dp[][] = new int[4][4] ;
//		int ans = goldmineTab(cost,dp) ;
//		System.out.print(ans) ;
//		rodCuttingTab();
//		coinChangeCombinationTab();
//		coinChangePermutationTab();
		LIS();
	}

}
