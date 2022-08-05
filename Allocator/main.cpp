//
// Created by yanghao on 2022/7/5.
//

#include <iostream>
#include <vector>

template<typename T>
struct TYallotor {
    typedef T value_type;
    TYallotor() = default;

    template<class U> constexpr
    TYallotor(const TYallotor<U>& ) noexcept {}

    T* allocate(std::size_t n) {
        T* p =  static_cast<T*>(std::malloc(n * sizeof(T)));
        return p;
    }

    void deallocate(T*p, std::size_t n) noexcept {
        std::free(p);
    }
};

template <class T, class U>
bool operator==(const TYallotor <T>&, const TYallotor <U>&) { return true; }
template <class T, class U>
bool operator!=(const TYallotor <T>&, const TYallotor <U>&) { return false; }


int main(int argc, char* argv[]) {

    std::vector<int, TYallotor<int>> v(8);
    v.push_back(42);
    std::cout << v.back() << v.front() << "\n";
    return 0;
}