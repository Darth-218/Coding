/*
Name: Kenzy Ibrahim
Course: COP-2800-98671
Date: 02/15/2025
Assignment: P6 - Counting Chickens
Description: A program that counts chicken and the eggs produced per week
AI Statment: No AI used.
*/

import java.time.LocalDateTime;
import java.util.Scanner;

public class P6 {
  public static void main(String[] args) {
    System.out.println("Kenzy Ibrahim");
    System.out.println("COP-2800-98671");
    System.out.println("P6 - Counting Chickens");
    System.out.println("AI Statment: No AI used.");
    System.out.println(LocalDateTime.now() + "\n\n");

    Scanner scanner = new Scanner(System.in);
    System.out.print("How many chickens do you have? ");

    int chickens = scanner.nextInt();

    if (chickens <= 0) {
      System.out.println("You need to have at least one chicken");
      System.exit(0);
    } else if (chickens > 10) {
      System.out.print("You can't have more than 10 chikckens");
      System.exit(0);
    }

    System.out.print("Over how many weeks? ");
    int weeks = scanner.nextInt();
    scanner.nextLine();

    if (weeks <= 0) {
      System.out.println(
          "You must have had the chicken(s) for at least a week");
      System.exit(0);
    }

    String[][] chicken_colors = new String[chickens][chickens];

    for (int i = 0; i < chickens; i++) {
      System.out.print("Enter chicken name: ");
      chicken_colors[0][i] = scanner.nextLine();
      System.out.print("Enter chicken color: ");
      chicken_colors[1][i] = scanner.nextLine();
      System.out.println();
    }

    int[][] production = new int[chickens][weeks];
    for (int j = 0; j < chickens; j++) {
      for (int i = 0; i < weeks; i++) {
        System.out.print("Enter the number of eggs produced by " +
                         chicken_colors[0][j] + " in week " + (i + 1) + ": ");
        production[j][i] = scanner.nextInt();
      }
    }

    for (int i = 0; i < chickens; i++) {
      int sum = 0;
      for (int j = 0; j < weeks; j++) {
        sum += production[i][j];
      }
      System.out.println(chicken_colors[0][i] + " the " + chicken_colors[1][i] +
                         " chicken has produced " + sum + " in " + weeks +
                         " weeks.");
    }
    scanner.close();
  }
}
