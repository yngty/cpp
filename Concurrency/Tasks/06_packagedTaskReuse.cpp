//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <future>
#include <functional>
#include <vector>

void calcProducts(std::packaged_task<int(int, int)>& task,
                  const std::vector<std::pair<int, int>>& pairs) {
    for (auto& [first, second]: pairs) {
        auto fut = task.get_future();
        task(first, second);
        std::cout << first << " * " << second << " = " << fut.get();
        task.reset();
    }
}
int main(int argc, char* argv[]) {

    std::cout << "In Main: " << std::this_thread::get_id() << "\n";
    std::vector<std::pair<int, int>> allPairs;
    allPairs.emplace_back(1, 2);
    allPairs.emplace_back(2, 3);
    allPairs.emplace_back(3, 4);
    allPairs.emplace_back(4, 5);

    std::packaged_task<int(int, int)> task ([](int fir, int sec) {
        std::cout << "In packaged_task: " << std::this_thread::get_id() << "\n";
        return fir * sec;
    });

    calcProducts(task, allPairs);
    std::cout << "\n";
    std::cout << "In Main: " << std::this_thread::get_id() << "\n";



//    std::thread t(calcProducts, std::ref(task), allPairs);
//    t.join();

    return 0;
}