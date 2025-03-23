import java.util.Scanner;

public class q13 {
	public static void doThis(int iterations) {
		// Iterate for the number of input.
		while (iterations > 0) {
			System.out.println("I will do this " + iterations + " more times.");
			iterations--;
		}
		System.out.println("I am done doing this.");
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// Ask the user for input.
		System.out.print("Enter a number: ");
		int choice = Integer.parseInt(sc.nextLine());
		// Check that the input is withen bounds.
		while (choice > 10 || choice < 1) {
			System.out.println("Input out of bounds!");
			System.out.print("Enter a number: ");
			choice = Integer.parseInt(sc.nextLine());
		}
		// Call the iteration function.
		doThis(choice);
		sc.close();
	}
}
