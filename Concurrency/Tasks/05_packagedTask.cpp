//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <future>
#include <random>
#include <deque>

class SumUp{
public:
    int operator()(int begin, int end) {
        long long int sum {0};
        for (int i = begin; i < end; ++i) {
            sum += i;
        }
        return sum;
    }
};

int main(int argc, char* argv[]) {
    std::cout << "\n";
    SumUp sumUp1;
    SumUp sumUp2;
    SumUp sumUp3;
    SumUp sumUp4;

    // 1. wrap the tasks
    std::packaged_task<int(int, int)> sumTask1(sumUp1);
    std::packaged_task<int(int, int)> sumTask2(sumUp2);
    std::packaged_task<int(int, int)> sumTask3(sumUp3);
    std::packaged_task<int(int, int)> sumTask4(sumUp4);

    std::cout << "sumTask1 is valid: " << sumTask1.valid() << "\n";
    // 2. create the futures
    std::future<int> sumResult1 = sumTask1.get_future();
    std::future<int> sumResult2 = sumTask2.get_future();
    std::future<int> sumResult3 = sumTask3.get_future();
    std::future<int> sumResult4 = sumTask4.get_future();

    std::cout << "sumTask1 is valid: " << sumTask1.valid() << "\n";

    std::deque<std::packaged_task<int(int, int)>> allTasks;
    allTasks.emplace_back(std::move(sumTask1));
    allTasks.emplace_back(std::move(sumTask2));
    allTasks.emplace_back(std::move(sumTask3));
    allTasks.emplace_back(std::move(sumTask4));

    int begin {1};
    int increment {2500};

    int end = begin + increment;

    // 3. perform the calculations
    while (not allTasks.empty()) {
        std::packaged_task<int(int, int)> task = std::move(allTasks.front());
        allTasks.pop_front();
        std::thread sumThread(std::move(task), begin, end);
        begin = end;
        end += increment;
        sumThread.detach();
    }

    // 4. pick up the results
    try {
        auto sum = sumResult1.get() + sumResult2.get() +
                   sumResult3.get() + sumResult4.get();
        std::cout << "sum of 0 .. 1000" << sum << "\n";
    } catch (const std::future_error& e) {
        std::cout << e.what() << "\n";
    }



    return 0;
}