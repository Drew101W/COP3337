#include <iostream>
#include <stdexcept>
double calculate(double a, double b, char op);
int main() {
    double num1, num2;
    char op;
    try {
        std::cout << "Enter first number: ";
        if (!(std::cin >> num1)) {
            // Input was not a number
            throw std::invalid_argument("First input is not a number");
        }
        std::cout << "Enter operator (+ - * /): ";
        if (!(std::cin >> op)) {
            throw std::invalid_argument("Operator input failed");
        }
        std::cout << "Enter second number: ";
        if (!(std::cin >> num2)) {
            throw std::invalid_argument("Second input is not a number");
        }
        double result = calculate(num1, num2, op);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
// TODO 1: Complete this function
// Throw appropriate built-in exceptions
// Division by zero → std::overflow_error
// Invalid operator (not +, -, *, /) -> std::invalid_argument
double calculate(double a, double b, char op) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '*') {
        return a * b;
    } else if (op == '/') {
        if (b == 0) {
            throw std::overflow_error("Division by zero");
        }
        return a / b;
    } else {
        throw std::invalid_argument("Invalid operator");
    }
}