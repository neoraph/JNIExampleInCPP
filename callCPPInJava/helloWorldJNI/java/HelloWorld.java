public class HelloWorld {
	native void display();
	
	static {
		System.loadLibrary("helloWorld");
	}

	public static void main(String args[]) {
		HelloWorld obj = new HelloWorld();
		obj.display();
			
	}

}
