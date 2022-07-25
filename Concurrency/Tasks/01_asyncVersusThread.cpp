//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <thread>
#include <future>

int main(int argc, char* argv[]) {

   std::cout << "\n";

   int res {0};
   std::thread t([&]{
       res = 2000 + 11;
   });
   t.join();

   std::cout << "res: " << res << "\n";

   std::future<int> fut = std::async([]{ return 2000 + 11 ;});
   std::cout << "fut.get(): " << fut.get() << "\n";
   return 0;
}