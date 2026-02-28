package com.diekvoss;

import java.util.ArrayList;

public class ParallelCounting implements Runnable {
  private final int from;
  private final int to;
  private final ArrayList<Customer> customerList;

  private int count = 0;

  ParallelCounting(ArrayList<Customer> customerList, int from, int to) {
    this.customerList = customerList;
    this.from = from;
    this.to = to;
  }

  void rangeCounting(int from, int to) {
    for (int i = from; i < to; ++i) {
      if (customerList.get(i).getBalance() < 1000) {
        // I have elected to not use a static variable incremented synchronously as that essentially
        // turns the
        // parallel back to sequential but with all the overhead of threads
        count++;
      }
    }
  }

  int getCount() {
    return count;
  }

  @Override
  public void run() {
    rangeCounting(from, to);
  }
}
