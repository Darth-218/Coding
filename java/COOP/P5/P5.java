/*
Name: Kenzy Ibrahim
Course: COOP-2800-98671
Date: 04/06/2025.
Assignment: P5 - Buying Chickens at the Chicken Store.
Description: A program that produces a report on chickens based on user input.
AI Statment: No AI used.
*/

import java.time.LocalDateTime;
import java.util.Scanner;

public class P5 {

  public static void welcomeMessage() {
    System.out.println("Welcome to the Chicken Store!");
  }

  public static int getChickenType() {
    System.out.println("What type of chicken do you want to buy?");
    System.out.println("1: Rhode Island Red");
    System.out.println("2: Americana");
    System.out.println("3: Longhorn\n");
    Scanner scanner = new Scanner(System.in);
    String value = scanner.nextLine();
    return Integer.parseInt(value);
  }

  public static int getHealthStatus() {
    System.out.println("\nWhat is the health status of the chicken?");
    System.out.println("0: Healthy");
    System.out.println("1: Under weight");
    System.out.println("2: Over weight");
    System.out.println("3: Droopy comb\n");
    Scanner scanner = new Scanner(System.in);
    String value = scanner.nextLine();
    return Integer.parseInt(value);
  }

  public static float calculateEggs(int chickenType, int healthStatus) {
    double productionCount = 0;
    double healthValue = 0;

    final int RHODE_ISLAND_RED = 1;
    final int AMERICANA = 2;
    final int LONGHORN = 3;

    final int RHODE_ISLAND_RED_COUNT = 7;
    final int AMERICANA_COUNT = 5;
    final int LONGHORN_COUNT = 6;

    final double HEALTHY_VALUE = 1.0;
    final double UNDER_WEIGHT_VALUE = 0.7;
    final double OVER_WEIGHT_VALUE = 0.9;
    final double DROOPY_COMB_VALUE = 0.5;

    final int HEALTHY = 0;
    final int UNDER_WEIGHT = 1;
    final int OVER_WEIGHT = 2;
    final int DROOPY_COMB = 3;

    switch (chickenType) {
    case RHODE_ISLAND_RED:
      productionCount = RHODE_ISLAND_RED_COUNT;
      break;
    case AMERICANA:
      productionCount = AMERICANA_COUNT;
      break;
    case LONGHORN:
      productionCount = LONGHORN_COUNT;
      break;
    default:
      System.out.println("Invalid chicken type.");
      return 0;
    }

    switch (healthStatus) {
    case HEALTHY:
      healthValue = HEALTHY_VALUE;
      break;
    case UNDER_WEIGHT:
      healthValue = UNDER_WEIGHT_VALUE;
      break;
    case OVER_WEIGHT:
      healthValue = OVER_WEIGHT_VALUE;
      break;
    case DROOPY_COMB:
      healthValue = DROOPY_COMB_VALUE;
      break;
    default:
      System.out.println("Invalid health status.");
      return 0;
    }

    return (float)(productionCount * healthValue * 52);
  }

  public static String getChickenValue(float eggs) {
    if (eggs > 300) {
      return "great value";
    } else if (eggs > 200) {
      return "good value";
    } else {
      return "consider fried chicken";
    }
  }

  public static void main(String[] args) {

    System.out.println("Kenzy Ibrahim");
    System.out.println("COP-2800-98671");
    System.out.println("Date: 04/06/2025.");
    System.out.println("P5 - Buying Chickens at the Chicken Store");
    System.out.println("Description: A program that produces a report on "
                       + "chickens based on user input.");
    System.out.println("AI Statment: No AI used.");
    System.out.println(LocalDateTime.now() + "\n\n");

    welcomeMessage();

    while (true) {
      int chickenType = getChickenType();
      int healthStatus = getHealthStatus();
      float eggs = calculateEggs(chickenType, healthStatus);
      String value = getChickenValue(eggs);

      System.out.println("Expected number of eggs in a year: " + eggs);
      System.out.println("Chicken value: " + value + "\n");

      System.out.print("Would you like to buy this chicken? (y/n): ");
      Scanner scanner = new Scanner(System.in);
      if (scanner.nextLine().equals("y")) {
        System.out.println("You bought this chicken!");
        scanner.close();
        System.exit(0);
      }
    }
  }
}
