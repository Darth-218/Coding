/*
Name: Kenzy Ibrahim
Course: COP-2800-98671
Date: 02/15/2025
Assignment: P4 - Fun for a long trip
Description: A program that asks the user what type of plate is needed and
calculate the prices of plates AI Statment: No AI used.
*/

import java.time.LocalDateTime;
import java.util.Random;
import java.util.Scanner;

public class P4 {
  public static void main(String[] args) {

    boolean guess = true;

    System.out.println("Kenzy Ibrahim");
    System.out.println("COP-2800-98671");
    System.out.println("P4 - Fun for a long trip");
    System.out.println("AI Statment: No AI used.");
    System.out.println(LocalDateTime.now() + "\n\n");

    Scanner scanner = new Scanner(System.in);
    while (true) {
      System.out.println("Please choose one of the following games:");
      System.out.println("\t1. Guess a random number.");
      System.out.println("\t2. Calculate a factorial.");
      System.out.println("\t3. Print a matrix.");
      System.out.println("\t4. Exit.");

      String choice = scanner.nextLine();

      switch (choice) {
      case "1":
        Random random = new Random();
        int random_num = random.nextInt(11 - 1) + 1;
        System.out.println("\nYou chose 'Guess a random number'.");
        while (guess) {
          System.out.print("Pick a number between 1 and 10: ");
          String number = scanner.nextLine();

          if (Integer.parseInt(number) == random_num) {
            System.out.println("Congratulations, You guess right!");
            guess = false;
          } else {
            System.out.println("You guessed wrong. Try again!");
          }
        }
        break;
      case "2":
        System.out.println("\nYou chose 'Calculate a factorial'.");
        System.out.print("Enter a number: ");
        int number = Integer.parseInt(scanner.nextLine());
        int factor = 1;
        for (int i = number; i > 1; i--) {
          factor *= i;
        }
        if (factor > 100) {
          System.out.println("Thats a really big number!");
        }
        System.out.println(number + "! equals " + factor);
        break;
      case "3":
        System.out.println("\nYou chose 'Print a matrix'.");
        System.out.print("Enter matrix character: ");
        String character = scanner.nextLine();
        System.out.print("Enter matrix size [1 to 10]: ");
        int size = 0;
        while (size < 1 || size > 10) {
          System.out.print("Invalid, enter matrix size [1 to 10]: ");
          size = Integer.parseInt(scanner.nextLine());
        }
        System.out.println("Your matrix:\n");
        for (int i = 0; i < size; i++) {
          for (int j = 0; j < size; j++) {
            System.out.print(character + " ");
          }
          System.out.println();
        }
        System.out.println();
        break;
      case "4":
        System.out.println("\nYou chose 'Exit'.");
        System.out.println("Goodbye. Hope you had fun!!");
        System.exit(0);
        break;
      default:
        System.out.println("Invalid Option.");
      }
    }
  }
}
