//
// Created by yanghao on 2022/7/30.
//

#include <iostream>
#include <algorithm>
#include <vector>

bool hasPrefix(const std::string& str, const std::string& prefix) {
//    return str.size() >= prefix.size()
//    && std::mismatch(prefix.begin(), prefix.end(), str.begin()).first == prefix.end();
    return std::mismatch(prefix.begin(), prefix.end(), str.begin()).first == prefix.end();
}

bool hasSuffix(const std::string& str, const std::string& suffix) {
//    return str.size() >= suffix.size()
//    && std::mismatch(suffix.rbegin(), suffix.rend(), str.rbegin()).first == suffix.rend();
    return std::mismatch(suffix.rbegin(), suffix.rend(), str.rbegin()).first == suffix.rend();
}
int main() {
    std::vector<std::string> v{ "1", "2", "3"};
    std::string str = "hello";
    std::string prefix = "hello2333313123131313123123131313";

    std::cout << *(v.end()+200000000);
    std::cout << (*str.end()+20000000 == '2') << "\n";
    std::cout << std::boolalpha;

    std::cout << hasPrefix(str, prefix) << "\n";

    std::string suffix = "hello1111111";

    std::cout << hasSuffix(str, suffix) << "\n";
    return 0;
}