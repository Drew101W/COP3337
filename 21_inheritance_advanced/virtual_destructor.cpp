#include <iostream>

class Dad {
public:
    Dad() {
        std::cout << "Dad's constructor" << std::endl;
    }
};

class Son : public Dad {
public:
    Son() {
        std::cout << "Son's constructor" << std::endl;
        std::cout << "Dynamic memory was allocated" << std::endl;
    }
    ~Son(){
        std::cout << "Dynamic memory was deallocated" << std::endl;
    }
};

int main(void) {
    Dad *dad = new Son();



    return 0;
}