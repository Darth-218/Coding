import java.util.Random;
import java.util.Scanner;

public class P3 {
  public static String randomPlate() {
    String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    String first = "", second = "";
    Random index = new Random();
    for (int i = 0; i < 3; i++) {
      first += alphabet.charAt(index.nextInt(26));
      second += alphabet.charAt(index.nextInt(10));
    }
    return second + "-" + first;
  }

  public static double customPlate(String plate) {
    plate = plate.toUpperCase();
    String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    String numbers = "1234567890";
    double cost = 45.00;
    if (2 > plate.length() || 8 < plate.length()) {
      System.out.println("Invalid plate length.");
      return -1.00;
    }
    for (int i = 0; i < plate.length(); i++) {
      if (alphabet.indexOf(plate.charAt(i)) != -1) {
        cost += 1.25;
      } else if (numbers.indexOf(plate.charAt(i)) != -1) {
        cost += 1.00;
      } else if (plate.charAt(i) != '-') {
        System.out.println("Illegal plate character " + plate.charAt(i) + ".");
        return -1.00;
      }
    }
    return cost;
  }

  public static int plateLength(String plate) {
    int length = 0;
    for (int i = 0; i < plate.length(); i++) {
      if (plate.charAt(i) != '-') {
        length++;
      }
    }
    return length;
  }

  public static void main(String[] args) {

    Scanner scanner = new Scanner(System.in);
    while (true) {
      System.out.println("Please choose one of the following options:");
      System.out.println("\t1. Random Plate.");
      System.out.println("\t2. Custom Plate.");
      System.out.println("\t3. Plate Renewal.");
      System.out.println("\t4. Exit.");

      String choice = scanner.nextLine();
      String plate;

      switch (choice) {
      case "1":
        System.out.println("You chose 'Random Plate'.");
        System.out.println("Your new random plate: " + randomPlate());
        System.out.println("Plate cost: $45.00");
        break;
      case "2":
        System.out.println("You chose 'Custom Plate'.");
        System.out.print("Enter your custom plate: ");
        plate = scanner.nextLine();
        System.out.println("Your custom plate " + plate + " costs: $" +
                           customPlate(plate));
        break;
      case "3":
        System.out.println("You chose 'Plate Renewal'.");
        System.out.println("Please choose one of the following options:");
        System.out.println("\t1. Random Plate.");
        System.out.println("\t2. Custom Plate.");
        String newchoice = scanner.nextLine();

        switch (newchoice) {
        case "1":
          System.out.println("Your plate renewal costs: $22.50");
          break;
        case "2":
          System.out.print("Enter your custom plate: ");
          plate = scanner.nextLine();
          System.out.println("Your plate renewal costs: $" + 45 / 2 +
                             plateLength(plate));
          break;
        }
        break;
      case "4":
        System.out.println("You chose 'Exit'.");
        System.out.println("Goodbye...");
        System.exit(0);
        break;
      default:
        System.out.println("Invalid Option.");
      }
    }
  }
}
