/*
Name: Kenzy Ibrahim
Course: COP-2800-98671
Date: 02/15/2025
Assignment: P2 - Cooking Breakfast
Description: A program that asks what user wants to have for breakfast.
AI Statment: No AI used.
*/

import java.time.LocalDateTime;
import java.util.Scanner;

public class P2 {
  public static void main(String[] args) {

    System.out.println();
    System.out.println("Kenzy Ibrahim");
    System.out.println("COP-2800-98671");
    System.out.println("P2 - Cooking Breakfast");
    System.out.println("AI Statment: No AI used.");
    System.out.println(LocalDateTime.now() + "\n\n");

    Scanner scanner = new Scanner(System.in);

    boolean Coffee, Cream, RegularCream, NonDairyCream, Sugar, RegularSugar,
        SugarSub;

    Coffee = Cream = RegularCream = NonDairyCream = Sugar = RegularSugar =
        SugarSub = false;

    System.out.println("Do you want Coffee? (true or false)");
    Coffee = scanner.nextBoolean();

    if (Coffee) {
      System.out.println("Do you want Cream?");
      Cream = scanner.nextBoolean();

      if (Cream) {
        System.out.println("Do you want Regular Cream?");
        RegularCream = scanner.nextBoolean();

        if (RegularCream) {
          NonDairyCream = false;
        } else {
          NonDairyCream = true;
        }
      }
      System.out.println("Do you want Sugar?");
      Sugar = scanner.nextBoolean();

      if (Sugar) {
        System.out.println("Do you want Regular Sugar?");
        RegularSugar = scanner.nextBoolean();

        if (RegularSugar) {
          SugarSub = false;
        } else {
          SugarSub = true;
        }
      }
    }

    boolean Bacon, Strips, Canadian, Traditional, Vegan;
    Bacon = Strips = Canadian = Traditional = Vegan = false;

    System.out.println("Do you want Bacon? (true or false)");
    Bacon = scanner.nextBoolean();

    if (Bacon) {

      System.out.println("Do you want Bacon Strips?");
      Strips = scanner.nextBoolean();

      if (Strips) {
        Canadian = false;
      } else {
        Canadian = true;
      }

      System.out.println("Do you want Traditional Bacon?");
      Traditional = scanner.nextBoolean();

      if (Traditional) {
        Vegan = false;
      } else {
        Vegan = true;
      }
    }

    boolean Eggs, Scrambled, Sunny, Fried;
    Eggs = Scrambled = Sunny = Fried = false;

    System.out.println("Do you want Eggs? (true/false)");
    Eggs = scanner.nextBoolean();

    if (Eggs) {

      System.out.println("Do you want Scrambled Eggs?");
      Scrambled = scanner.nextBoolean();

      if (Scrambled) {
        Sunny = Fried = false;
      } else {

        System.out.println("Do you want Sunny-Side-Up Eggs?");
        Sunny = scanner.nextBoolean();

        if (Sunny) {
          Fried = false;
        } else {
          Fried = true;
        }
      }
    }

    boolean Toast, White, Wheat;
    Toast = White = Wheat = false;

    System.out.println("Do you want Toast? (true/false)");
    Toast = scanner.nextBoolean();

    if (Toast) {

      System.out.println("Do you want White Toast?");
      White = scanner.nextBoolean();

      if (White) {
        Wheat = false;
      } else {
        Wheat = true;
      }
    }

    System.out.println("\n==Order Summary==");

    if (Coffee) {
      System.out.printf("\nCoffee: %b\n", Coffee);
      if (Cream) {
        System.out.printf("Regular Cream: %b\n", RegularCream);
        System.out.printf("Non-Dairy Cream: %b\n", NonDairyCream);
      }
      if (Sugar) {
        System.out.printf("Regular Sugar: %b\n", RegularSugar);
        System.out.printf("Sugar Subistitute: %b\n", SugarSub);
      }
    }

    if (Bacon) {
      System.out.printf("\nBacon: %b\n", Bacon);
      System.out.printf("Strips: %b\n", Strips);
      System.out.printf("Canadian: %b\n", Canadian);
      System.out.printf("Traditional: %b\n", Traditional);
      System.out.printf("Vegan: %b\n", Vegan);
    }

    if (Eggs) {
      System.out.printf("\nEggs: %b\n", Eggs);
      System.out.printf("Sunny-Side-Up: %b\n", Sunny);
      System.out.printf("Scrambled: %b\n", Scrambled);
      System.out.printf("Fried: %b\n", Fried);
    }

    if (Toast) {
      System.out.printf("\nToast: %b\n", Toast);
      System.out.printf("White: %b\n", White);
      System.out.printf("Wheat: %b\n", Wheat);
    }

    System.out.println();

    if ((!Coffee || (Coffee && !(Cream && Sugar)) ||
         (Coffee && (SugarSub || NonDairyCream))) &&
        (!Bacon || (Bacon && Vegan)) && (!Toast || (Toast && Wheat))) {
      System.out.println("This is a healthy breakfast!");
    } else {
      System.out.println("Take a walk after this breakfast!");
      System.out.println();
    }
  }
}
