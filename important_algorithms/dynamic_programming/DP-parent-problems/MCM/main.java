import java.util.Scanner;

class Program {
	public static void main(String[] args) {

	}
	
	public boolean isPrime(int number) {
		for(int i = 2; i <= Math.sqrt(number); ++i) 
			if(number % i == 0) 
				return false;

		return true;
	}
}