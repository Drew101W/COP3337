#include <iostream>
#include <string>



class Human {
public:
    std::string name;
    int age;
    Human(): name("John Doe"), age(1) { }
    Human(std::string name, int age): name(name), age(age) { }

    void print(void) const {
        std::cout << "Hi! My name is " << name << '\n';
        std::cout << "I am " << age << " years old." << '\n';
    }

};



class Student : public Human{ // Student is a child of Human
public:
    int student_id;

    Student(std::string name = "John Doe", int age = 1, int student_id = 0) : 
        Human(name, age), student_id(student_id) { }

    void print(void) const {
        Human::print(); // Call parent class print function
        std::cout << "My student ID is " << student_id << '\n';
    }

};


int main(void) {
    Human h("Slim Shady", 53);
    h.print();
    Student st("Michael Jordan", 62, 23);
    st.print();
    return 0;
}