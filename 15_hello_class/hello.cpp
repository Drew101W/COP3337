#include <iostream>

class Hello{
public:
    Hello() {
        std::cout <<"Constructor" << std::endl;
    }
    Hello(int n){
        std::cout << "Constructor with arguments: " << std::endl;
    }

    void bye(void) {
        std::cout << "Bye!" << std::endl;

    }
};

int main(void) {
    // Create an object dynamically

    Hello *hi = new Hello;
    // Create an object dynamically

    Hello *hi2 = new Hello(10);

    // Access bye method
    hi->bye();

    // Deallocate memory
    delete hi;
    delete hi2;


    return 0;
}