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

    // Get number of chickens from user
    System.out.print("How many chickens do you have? ");
    int chickens = scanner.nextInt();

    // Validate number of chickens
    if (chickens <= 0) {
      System.out.println("You need to have at least one chicken");
      System.exit(0); // Exit program if invalid input
    } else if (chickens > 10) {
      System.out.print("You can't have more than 10 chickens");
      System.exit(0);
    }

    // Get number of weeks from user
    System.out.print("Over how many weeks? ");
    int weeks = scanner.nextInt();
    scanner.nextLine(); // Get rid of the newline

    // Validate number of weeks
    if (weeks <= 0) {
      System.out.println(
          "You must have had the chicken(s) for at least a week");
      System.exit(0);
    }

    // Create 2D array to store chicken names and colors
    // First row: names, second row: colors
    String[][] chicken_colors = new String[chickens][chickens];

    // Loop to get each chicken's name and color
    for (int i = 0; i < chickens; i++) {
      System.out.print("Enter chicken name: ");
      chicken_colors[0][i] = scanner.nextLine();
      System.out.print("Enter chicken color: ");
      chicken_colors[1][i] = scanner.nextLine();
      System.out.println();
    }

    // Create 2D array to store egg production data
    // Rows represent chickens, columns represent weeks
    int[][] production = new int[chickens][weeks];

    // Nested loops to get egg production for each chicken each week
    for (int j = 0; j < chickens; j++) {
      for (int i = 0; i < weeks; i++) {
        System.out.print("Enter the number of eggs produced by " +
                         chicken_colors[0][j] + " in week " + (i + 1) + ": ");
        production[j][i] = scanner.nextInt();
      }
    }

    // Calculate and display total eggs for each chicken
    for (int i = 0; i < chickens; i++) {
      int sum = 0;
      // Sum eggs for current chicken across all weeks
      for (int j = 0; j < weeks; j++) {
        sum += production[i][j];
      }
      // Display chicken's info and total production
      System.out.println(chicken_colors[0][i] + " the " + chicken_colors[1][i] +
                         " chicken has produced " + sum + " in " + weeks +
                         " weeks.");
    }

    // Close scanner to prevent leak
    scanner.close();
  }
}
