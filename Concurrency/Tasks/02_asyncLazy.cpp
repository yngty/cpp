//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <future>
#include <chrono>

int main(int argc, char* argv[]) {

   std::cout << "\n";
   auto begin = std::chrono::system_clock::now();
   auto asyncLazy = std::async(std::launch::deferred, []{ return std::chrono::system_clock::now();});

   auto asyncEager = std::async(std::launch::async, []{return std::chrono::system_clock::now(); });

   std::this_thread::sleep_for(std::chrono::seconds(1));

   auto lazyStart = asyncLazy.get() - begin;
   auto eagerStart = asyncEager.get() - begin;

   auto lazyDuration = std::chrono::duration<double>(lazyStart).count();
   auto eagerDuration = std::chrono::duration<double>(eagerStart).count();

   std:: cout << lazyDuration << "\n";
   std:: cout << eagerDuration << "\n";

   return 0;
}