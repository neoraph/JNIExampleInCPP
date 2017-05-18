public class Factorial {

	public static int calcFactorial(Integer n) {
		Integer result = 1;
		while(n > 0) {
			result *= n;
			n--;
		}
		System.out.println("le resultat dans java est : " + result);
		return result;
	}

}
