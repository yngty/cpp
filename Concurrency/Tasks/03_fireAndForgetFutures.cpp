//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <future>
#include <chrono>

using namespace std::chrono_literals;
int main(int argc, char* argv[]) {

    std::cout << "begin...\n";
    std::async(std::launch::async, []{
        std::this_thread::sleep_for(10s);
        std::cout << "first thread: " << std::this_thread::get_id() << "\n";
  });

    std::cout << "main thread1: " << std::this_thread::get_id() << "\n";

  std::async(std::launch::async, []{
      std::this_thread::sleep_for(1s);
      std::cout << "second thread: " << std::this_thread::get_id() << "\n";
  });

  std::cout << "main thread2: " << std::this_thread::get_id() << "\n";

  return 0;
}