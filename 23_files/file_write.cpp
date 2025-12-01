#include <iostream>
#include <iomanip>
#include <fstream>

int main(void){
    std::ofstream out;
    std::string file_name;
    std::cout << "Enter a file name: ";
    std::cin >> file_name;
    // Open the file
    out.open(file_name);

    // Write into a file
    out << "Hello" << std::endl;
    out << "MDRM8" << std::endl;

    for (int i = 1 ; i < 100; i++){
        out << std::setw(5) << i;
        if (i % 10 == 0){
            out << std::endl;
        }
    }

    // Close the file
    out.close();

    return 0;
}