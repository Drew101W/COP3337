#include <iostream>
#include <string>

class Hello{
public:
    Hello() : messages(nullptr) , size(0) {
        std::cout <<"Constructor" << std::endl;
    }
    Hello(int n) : size(n) {
        std::cout << "Constructor with arguments: " << std::endl;
        // Dynamically allocate an array of strings
        messages = new std::string[n];
        // Initialize an array
        for (int i = 0; i< n; i++) {
            messages[i] = (i % 2 == 0) ? "Welcome!" : "Not Welcome";
    }
}

// Copy constructor
Hello(const Hello& other) {
    std::cout << "Copy Constructor\n";
    size = other.size;
    if (size > 0) {
        messages = new std::string[size];
        for (int i = 0; i < size; ++i) {
            messages[i] = other.messages[i];
        }
    } else {
        messages = nullptr;
    }
}

// Destructor
~Hello() {
    delete [] messages;
}

    void bye(void) {
        std::cout << "Bye!" << std::endl;

    }

    void printGreetings() const {
        for(int i = 0; i < size; i++) {
            std::cout << messages[i] << std::endl;
        }
    }

private:
    std::string *messages; // array of strings
    int size; // the size of the array
public:
    // Getter for size
    int getSize() const { return size; }

    // Setter for size (reallocates array, deletes old)
    void setSize(int newSize) {
        if (newSize == size) return;
        delete[] messages;
        size = newSize;
        if (size > 0) {
            messages = new std::string[size];
        } else {
            messages = nullptr;
        }
    }

    // Getter for messages (const pointer)
    const std::string* getMessages() const { return messages; }

    // Setter for messages (copies array)
    void setMessages(const std::string* newMessages, int newSize) {
        setSize(newSize);
        for (int i = 0; i < size; ++i) {
            messages[i] = newMessages[i];
        }
    }
};

void test(Hello h) {
    std::cout << "Test";
}

int main(void) {
    // Create an object dynamically
    Hello *hi = new Hello(100);

    // Access printGreetings method
    hi->printGreetings();



    // for(int i = 0; i < 100; i++) {
    //    Hello(9999999);
    // }

    Hello hi2(100);
    Hello hi3 = hi2;
    test(*hi);

    // Deallocate memory
    delete hi;

    return 0;
}
