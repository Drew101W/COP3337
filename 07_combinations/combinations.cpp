/*
    Prints combination of n characters

*/

#include <iostream>
#include <string>

void printCombinations(int n);
void printCombinations(std::string& s, int n, int i);

int main(void) {
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    printCombinations(n);

    return 0;
}

void printCombinations (int n) {
    // Create a string and initialize with n 'a' characters
    std::string s(n, 'a');

    printCombinations(s, n, 0);

}

void printCombinations(std::string& s, int n, int i) {
    // base case
    if (i >= n) {
        std::cout << s << std::endl;

        return;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
 
        bool used = false;
        for (int j = 0; j < i; ++j) {
            if (s[j] == c) {
                used = true;
                break;
            }
        }

        if (!used) {
            s[i] = c;
            printCombinations(s, n, i + 1);
        }

}
}
