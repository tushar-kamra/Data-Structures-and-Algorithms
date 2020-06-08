package string;

import java.util.ArrayList;

public class codeString {
	public static void main(String[] args) {
//		System.out.println(divideLarge("24", 123));
//		System.out.println(subsequence_1("abc"));
//		System.out.println(subsequence_2("abc", ""));
//		System.out.println(permutation("abc", ""));
		System.out.println(contentBtwParenthesis("abc(mynameistuhsar(kamra))ye"));
	}

	public static String contentBtwParenthesis(String s) {
		if (s.charAt(0) == '(') {
			if (s.charAt(s.length() - 1) == ')') {
				return s;
			}
			return contentBtwParenthesis(s.substring(0, s.length() - 1));
		}
		return contentBtwParenthesis(s.substring(1));
	}

	public static int permutation(String s, String ans) {
		if (s.length() == 0) {
			System.out.println(ans);
			return 1;
		}
		int c = 0;
		for (int i = 0; i < s.length(); i++) {
			char ch = s.charAt(i);
			String left = s.substring(0, i);
			String right = s.substring(i + 1);
			c += permutation(left + right, ans + ch);
		}
		return c;
	}

	public static ArrayList<String> subsequence_1(String s) {
		if (s.length() == 0) {
			ArrayList<String> temp = new ArrayList<String>();
			temp.add("");
			return temp;
		}
		char ch = s.charAt(0);
		String restStr = s.substring(1);
		ArrayList<String> recAns = subsequence_1(restStr);
		ArrayList<String> ans = new ArrayList<String>();
		for (int i = 0; i < recAns.size(); i++) {
			ans.add(recAns.get(i) + ch);
			ans.add(recAns.get(i));
		}
		return ans;
	}

	public static int subsequence_2(String s, String ans) {
		if (s.length() == 0) {
			System.out.println(ans);
			return 1;
		}
		int c = 0;
		char ch = s.charAt(0);
		String restStr = s.substring(1);
		c += subsequence_2(restStr, ans + ch);
		c += subsequence_2(restStr, ans);
		return c;
	}

	public static String divideLarge(String dividend, int divisor) {
		String ans = "";
		int idx = 0;
		int temp = dividend.charAt(idx) - '0';
		while (temp < divisor) {
			if (idx + 1 == dividend.length())
				break;
			temp = temp * 10 + (dividend.charAt(++idx) - '0');

		}
		while (idx < dividend.length()) {
			ans += (temp / divisor); // type promotion
			temp = (temp % divisor) * 10 + (dividend.charAt(idx) - '0');
			idx++;
		}
		if (ans.length() == 0) {
			return "0";
		}

		return ans;
	}
}
