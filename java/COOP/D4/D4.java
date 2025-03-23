/*
Name: Kenzy Ibrahim
Course: COP-2800-98671
Date: 01/02/2025
Assignment: D4 - Cybersecurity in code.
Description: A program that calculates the
division of two numbers
AI Statment: No AI used.
*/

import java.util.Scanner;

public class D4 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("Enter the first number: ");
    float first = scanner.nextFloat();
    System.out.print("Enter the second number: ");
    float second = scanner.nextFloat();

    if (first <= 0 || first > 100 || second <= 0 || second > 100) {
      System.out.println(
          "One or both numbers is not between 0 and 100, exiting...");
      System.exit(0);
    }

    System.out.println(first + "/" + second + " = " + first / second);
  }
}
