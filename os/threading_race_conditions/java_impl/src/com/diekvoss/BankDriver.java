package com.diekvoss;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class BankDriver {

  public static void main(String[] args) throws FileNotFoundException {
    // feel free to create a different file with smaller/larger number of records
    // create a file with random records
    createAccountsFile(20000000);
    System.out.println("File Was Created!");

    ArrayList<Customer> customerList = new ArrayList<>();
    // reading the info from the file and storing in the arrayList
    long currentRec = 0;
    System.out.println("Reading the file \"accounts.txt\" ");
    Scanner inFile = new Scanner(new File("accounts.txt"));
    while (inFile.hasNext()) { // while 2
      String currID = inFile.nextLine();
      double currBalance = inFile.nextDouble();
      if (inFile.hasNextLine()) inFile.nextLine(); // dummy reading
      customerList.add(new Customer(currID, currBalance));
      if (++currentRec % 30000 == 0) System.out.print(">>");
      if (currentRec % 1000000 == 0) System.out.println();
    } // end of while 2

    // single sequential run
    long startTime = System.currentTimeMillis();
    int lowBalances = sequentialCounting(customerList);
    long estimatedTime = System.currentTimeMillis() - startTime;
    System.out.println("Number of accounts with less than $1000 is: " + lowBalances);
    System.out.println("Sequential run took in milliseconds: " + estimatedTime);

    // single parallel run
    startTime = System.currentTimeMillis();
    lowBalances = parallelCounting(customerList);
    estimatedTime = System.currentTimeMillis() - startTime;
    System.out.println("Number of accounts with less than $1000 is: " + lowBalances);
    System.out.println("Parallel run took in milliseconds: " + estimatedTime);

    // run multiple times to get an average
    double averageSequentialTime = loopSequential(customerList, 10);
    double averageParallelTime = loopParallel(customerList, 10);

    System.out.println("Average sequential " + averageSequentialTime);
    System.out.println("Average parallel " + averageParallelTime);
  }

  static int sequentialCounting(ArrayList<Customer> customerList) {
    int count = 0;
    for (Customer customer : customerList) if (customer.getBalance() < 1000) ++count;
    return count;
  }

  static int parallelCounting(ArrayList<Customer> customerList) {
    int quarter = customerList.size() / 4;
    int half = customerList.size() / 2;
    int threeQuarter = (customerList.size() * 3) / 4;
    ParallelCounting p1 = new ParallelCounting(customerList, 0, quarter);
    ParallelCounting p2 = new ParallelCounting(customerList, quarter, half);
    ParallelCounting p3 = new ParallelCounting(customerList, half, threeQuarter);
    ParallelCounting p4 = new ParallelCounting(customerList, threeQuarter, customerList.size());
    Thread t1 = new Thread(p1);
    Thread t2 = new Thread(p2);
    Thread t3 = new Thread(p3);
    Thread t4 = new Thread(p4);
    t1.start();
    t2.start();
    t3.start();
    t4.start();
    try {
      t1.join();
      t2.join();
      t3.join();
      t4.join();
    } catch (InterruptedException e) {
      e.printStackTrace();
    }
    return p1.getCount() + p2.getCount() + p3.getCount() + p4.getCount();
  }

  static void createAccountsFile(int count) throws FileNotFoundException {
    File accountsFile = new File("accounts.txt");
    PrintStream outFile = new PrintStream(accountsFile);
    Random rand = new Random();
    // needed for making sure that there is no duplication in the IDs
    // ArrayList<String> tmpIDs = new ArrayList<String>();

    // generating random records IDs from XXXX0 to XXXX300000000 (non-repeating) and
    // balances 0 to 1000000
    for (int i = 0; i < count; ++i) {
      int tempId;
      tempId = rand.nextInt(300000001);
      // try to generate a random ID with 3 random letters and a number from 0 to
      // 300000000
      String currentID =
          ""
              + ((char) ('A' + rand.nextInt(25)))
              + ((char) ('A' + rand.nextInt(25)))
              + ((char) ('A' + rand.nextInt(25)))
              + tempId
              + ((char) ('A' + rand.nextInt(25)))
              + ((char) ('A' + rand.nextInt(25)))
              + ((char) ('A' + rand.nextInt(25)));
      // if (tmpIDs.contains(currentID) == false) {
      // tmpIDs.add(currentID); // insert to the array list in location i
      outFile.println(currentID); // send to file
      // }
      outFile.println(rand.nextInt(1000001) / 100.0); // send to file
    }
    outFile.close();
  }

  static double loopSequential(ArrayList<Customer> customerList, int iterations) {
    long startTime;
    int lowBalances;
    double estimatedTime = 0;

    for (int i = 0; i < iterations; i++) {
      startTime = System.currentTimeMillis();
      lowBalances = sequentialCounting(customerList);
      estimatedTime += System.currentTimeMillis() - startTime;
    }

    return estimatedTime / iterations;
  }

  static double loopParallel(ArrayList<Customer> customerList, int iterations) {
    long startTime;
    int lowBalances;
    double estimatedTime = 0;

    for (int i = 0; i < iterations; i++) {
      startTime = System.currentTimeMillis();
      lowBalances = parallelCounting(customerList);
      estimatedTime += System.currentTimeMillis() - startTime;
    }

    return estimatedTime / iterations;
  }
}
