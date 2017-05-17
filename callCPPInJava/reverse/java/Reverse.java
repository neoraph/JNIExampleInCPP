import java.util.Scanner;

public class Reverse {

	native String reverse(String word);

	static {
		System.loadLibrary("reverse");
	}

	public static void main(String args[]) {
		
		Scanner in = new Scanner(System.in);

		System.out.println("Enter a string : ");
		String word = in.nextLine();		

		Reverse r = new Reverse();

		System.out.println("the reversed String is " + r.reverse(word));

	}


}
