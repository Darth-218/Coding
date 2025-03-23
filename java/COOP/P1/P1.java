/*
Name: Kenzy Ibrahim
Course: COP-2800-98671
Date: 01/02/2025
Assignment: P1 - Egg Production.
Description: A program that counts the estimated number
of eggs in a given time interval.
AI Statment: No AI used.
*/

import java.time.LocalDateTime;
import java.util.Scanner;

public class P1 {
  public static void main(String[] args) {

    System.out.println("Kenzy Ibrahim");
    System.out.println("COP-2800-98671");
    System.out.println("P1 - Egg Prodction");
    System.out.println("AI Statment: No AI used.");
    System.out.println(LocalDateTime.now() + "\n\n");

    Scanner scanner = new Scanner(System.in);

    System.out.print("What's the number of chickens on the farm? ");
    int chickens = scanner.nextInt();

    System.out.print("What's the number of roosters on the farm? ");
    int roosters = scanner.nextInt();

    System.out.print("What's the percentage change any random chicken lays "
                     + "an egg in a day? ");
    float percentage = scanner.nextFloat();

    System.out.print("What's the target number of days? ");
    int days = scanner.nextInt();

    float estimated = (chickens - roosters) * percentage * days;
    System.out.println("The estimated number of eggs produced in " + days +
                       " days on this farm is: " + estimated);
    scanner.close();
  }
}
