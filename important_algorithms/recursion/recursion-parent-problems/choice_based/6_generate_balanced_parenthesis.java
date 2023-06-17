import java.util.Scanner;
import java.util.ArrayList;

public class Program {
	static void solve(int open, int close, String op, ArrayList<String> v) {
		if(open == 0 && close == 0) {
			v.add(op);
			return;
		}
		
		if(open > 0) {
			String op1 = op;
			op1 += '(';
			solve(open - 1, close, op1, v);
		} 
		
		if(close > open) {
			String op2 = op;
			op2 += ')';
			solve(open, close - 1, op2, v);
		}
	}


	static ArrayList<String> findAllBalancedParenthesis(int n) {
		ArrayList<String> v = new ArrayList<String>();
		
		int open, close;
		open = close = n;
		String op = "";
	
		op += '(';		
		solve(open - 1, close, op, v);
		
		return v;
	}
	
	public static void main(String[] args) {
		int n = 3;
		ArrayList<String> v = findAllBalancedParenthesis(n);
		System.out.println(v.size());
		for(String s: v) {
			System.out.println(s);
		}
				
	}
}
