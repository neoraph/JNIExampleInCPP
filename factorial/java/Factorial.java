import java.util.Scanner;

public class Factorial {
	
	native int fact(int num);

	static {
		System.loadLibrary("factorial");
	}
	
	public static void main(String args[]) {
		
		Scanner in = new Scanner(System.in);
		
		System.out.println("Enter number : ");
		
		int num = in.nextInt();

		Factorial factorial = new Factorial();

		System.out.println("The factorial of num is " + factorial.fact(num));
		
		
	}
}
