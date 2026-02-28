import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter in a sentence");
    String sentenceInput = in.nextLine();
    System.out.println("Enter in a word to search for");
    String wordInput = in.next();
    System.out.println("Searching " + sentenceInput + " for " + wordInput);
    if (sentenceInput.contains(wordInput)) {
      System.out.println("FOUND");
    } else {
      System.out.println("NOT FOUND");
    }
  }
}
