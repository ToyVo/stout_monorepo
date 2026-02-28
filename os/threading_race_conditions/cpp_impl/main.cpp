#include "Customer.hpp"
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

void createAccountsFile(int count);
int sequentialCounting(const std::vector<Customer> &customerList);
void rangedCounting(const std::vector<Customer> &customerList, int &count,
                    unsigned long from, unsigned long to);
int parallelCounting(const std::vector<Customer> &customerList);
double loopSequential(const std::vector<Customer> &customerList,
                      int iterations);
double loopParallel(const std::vector<Customer> &customerList, int iterations);

int main() {
  createAccountsFile(20000000);
  std::cout << "File was created" << std::endl;

  // read file and construct vector of customers
  std::vector<Customer> customerList;
  long currentRec = 0;
  std::cout << "Reading the file \"accounts.txt\"" << std::endl;
  std::ifstream inFile;
  inFile.open("accounts.txt");
  if (inFile.is_open()) {
    std::string currentId;
    double currentValue;
    while (inFile >> currentId >> currentValue) {
      customerList.emplace_back(currentId, currentValue);
      if (++currentRec % 3000 == 0) {
        std::cout << ">>";
      }
      if (currentRec % 1000000 == 0) {
        std::cout << std::endl;
      }
    }
  }

  // single sequential run
  auto startTime = std::chrono::high_resolution_clock::now();
  int lowBalances = sequentialCounting(customerList);
  auto estimatedTime = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now() - startTime);
  std::cout << "Number of accounts with less than $1000 is: " << lowBalances
            << std::endl;
  std::cout << "Sequential run took in milliseconds: " << estimatedTime.count()
            << std::endl;

  // single Parallel run
  startTime = std::chrono::high_resolution_clock::now();
  lowBalances = parallelCounting(customerList);
  estimatedTime = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::high_resolution_clock::now() - startTime);
  std::cout << "Number of accounts with less than $1000 is: " << lowBalances
            << std::endl;
  std::cout << "Parallel run took in milliseconds: " << estimatedTime.count()
            << std::endl;

  // run multiple times to get an average
  double averageSequentialTime = loopSequential(customerList, 10);
  double averageParallelTime = loopParallel(customerList, 10);

  std::cout << "Average sequential " << averageSequentialTime << std::endl;
  std::cout << "Average parallel " << averageParallelTime << std::endl;
}

void createAccountsFile(int count) {
  // setup randomness
  std::random_device dev;
  std::default_random_engine generator(dev());
  std::uniform_int_distribution<int> id_dist(0, 300000000);
  std::uniform_int_distribution<int> char_dist(0, 25);
  std::uniform_int_distribution<int> value_dist(0, 1000000);
  auto randomId = std::bind(id_dist, generator);
  auto randomChar = std::bind(char_dist, generator);
  auto randomValue = std::bind(value_dist, generator);

  std::ofstream outFile;
  outFile.open("accounts.txt");
  if (outFile.is_open()) {
    for (int i = 0; i < count; ++i) {
      int tempId = randomId();
      std::ostringstream currentID;
      currentID << (char)('A' + randomChar()) << (char)('A' + randomChar())
                << (char)('A' + randomChar()) << tempId
                << (char)('A' + randomChar()) << (char)('A' + randomChar())
                << (char)('A' + randomChar());
      outFile << currentID.str() << std::endl
              << randomValue() / 100.0 << std::endl;
    }
  }
  outFile.close();
}

int sequentialCounting(const std::vector<Customer> &customerList) {
  int count = 0;
  for (const Customer &customer : customerList) {
    if (customer.getBalance() < 1000) {
      ++count;
    }
  }
  return count;
}

void rangedCounting(const std::vector<Customer> &customerList, int &count,
                    unsigned long from, unsigned long to) {
  count = 0;
  for (unsigned long i = from; i < to; ++i) {
    if (customerList[i].getBalance() < 1000) {
      count++;
    }
  }
}

int parallelCounting(const std::vector<Customer> &customerList) {
  unsigned long quarter = customerList.size() / 4;
  unsigned long half = customerList.size() / 2;
  unsigned long threeQuarter = (customerList.size() * 3) / 4;
  int c1, c2, c3, c4;
  std::thread t1(rangedCounting, std::ref(customerList), std::ref(c1), 0,
                 quarter);
  std::thread t2(rangedCounting, std::ref(customerList), std::ref(c2), quarter,
                 half);
  std::thread t3(rangedCounting, std::ref(customerList), std::ref(c3), half,
                 threeQuarter);
  std::thread t4(rangedCounting, std::ref(customerList), std::ref(c4),
                 threeQuarter, customerList.size());
  t1.join();
  t2.join();
  t3.join();
  t4.join();

  return c1 + c2 + c3 + c4;
}

double loopSequential(const std::vector<Customer> &customerList,
                      int iterations) {
  double duration = 0;
  int lowBalances;

  for (int i = 0; i < iterations; ++i) {
    auto startTime = std::chrono::high_resolution_clock::now();
    lowBalances = sequentialCounting(customerList);
    auto estimatedTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now() - startTime);
    duration += estimatedTime.count();
  }

  return duration / iterations;
}

double loopParallel(const std::vector<Customer> &customerList, int iterations) {
  double duration = 0;
  int lowBalances;

  for (int i = 0; i < iterations; ++i) {
    auto startTime = std::chrono::high_resolution_clock::now();
    lowBalances = parallelCounting(customerList);
    auto estimatedTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now() - startTime);
    duration += estimatedTime.count();
  }

  return duration / iterations;
}