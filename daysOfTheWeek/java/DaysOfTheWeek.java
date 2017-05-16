import java.lang.String;

public class DaysOfTheWeek {

	native String[] displayDays();

	static {
		System.loadLibrary("DaysOfTheWeek");
	}

	public static void main(String args[]) { 
		DaysOfTheWeek obj = new DaysOfTheWeek();
		
		String[] days = (String[])obj.displayDays();		
		
				

		System.out.println("les jours de la semaines sont les suivant : ");
		for(String day : days)
			System.out.println("- " + day);
	}
}
