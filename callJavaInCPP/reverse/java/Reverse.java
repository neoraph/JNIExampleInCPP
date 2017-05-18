
class Reverse {
	public static String reverse(String str) {
		System.out.println ("Reverse " + str + "from Java");
		return new StringBuilder(str).reverse().toString();
	}
}
