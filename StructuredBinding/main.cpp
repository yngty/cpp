//
// Created by yanghao on 2022/7/5.
//

#include <map>
#include <iostream>
#include <string>
#include <vector>
class UserEntry {
public:
    void load() {}

    std::string  getName() const {return name;}
private:
    std::string name;
    unsigned age {0};
    size_t cacheEntry {0};
};
int main(int argc, char* argv[]) {
    const std::map<std::string, int> mapCityPopulation {
            {"Beijing", 21'707'000},
            {"London", 8'787'892},
            {"New York", 8'622'698}
    };

    for (auto&[city,population]: mapCityPopulation) {
        std::cout << city << ": " << population <<"\n";
    }
    return 0;
}