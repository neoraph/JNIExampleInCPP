import java.util.Scanner;

public class Fibonacci {
	native int[] returnFibo(int n);

	static {
		System.loadLibrary("fibonacci");
	 }

	public static void main(String args[]) {
		
		Scanner inp = new Scanner(System.in);

		int n = inp.nextInt();

		Fibonacci fib = new Fibonacci();
	
		int[] fibo = fib.returnFibo(n);

		System.out.println("> The first " + n + " fibonacci numbers are ::");

		for(int i=0;i<n;i++)
			System.out.print(fibo[i] + " ");

		System.out.println();

	}

}
