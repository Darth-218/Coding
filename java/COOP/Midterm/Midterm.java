import java.util.Scanner;

public class Midterm {
  public static void thirtyone(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String input = scanner.nextLine();
    switch (input) {
    case "0":
      System.out.println("You entered zero.");
      break;
    case "1":
      System.out.println("You entered one.");
      break;
    case "2":
      System.out.println("You entered two.");
      break;
    case "3":
      System.out.println("You entered three.");
      break;
    case "4":
      System.out.println("You entered four.");
      break;
    case "5":
      System.out.println("You entered five.");
      break;
    case "6":
      System.out.println("You entered six.");
      break;
    case "7":
      System.out.println("You entered seven.");
      break;
    case "8":
      System.out.println("You entered eight.");
      break;
    case "9":
      System.out.println("You entered nine.");
      break;
    default:
      System.out.println("You entered '" + input +
                         "', which is not a digit between 0 and 9.");
    }
    scanner.close();
  }

  public static void namemath(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Welcome to my program. Please choose:");
    System.out.println("1. String");
    System.out.println("2. Math");
    int choice = scanner.nextInt();
    scanner.nextLine();
    switch (choice) {
    case 1:
      System.out.print("What is your name? ");
      String name = scanner.nextLine();
      char first = name.charAt(0);
      System.out.println("Your uppercase name is " + name.toUpperCase() +
                         ", your lowercase name is " + name.toLowerCase() +
                         ", and the first letter of your name is '" + first +
                         "'.");
      break;
    case 2:
      System.out.print("What is the value? ");
      double value = scanner.nextDouble();
      System.out.println("1. Sine");
      System.out.println("2. Cosine");
      System.out.println("3. Tangent");
      int mathchoice = scanner.nextInt();
      switch (mathchoice) {
      case 1:
        System.out.println("The sine of " + value + " is " + Math.sin(value));
        break;
      case 2:
        System.out.println("The cosine of " + value + " is " + Math.cos(value));
        break;
      case 3:
        System.out.println("The tangent of " + value + " is " +
                           Math.tan(value));
        break;
      }
      break;
    }
    scanner.close();
  }

  public static void main(String[] args) {
    int j = 0;
    System.out.println(++j + j * 5);
  }
}
