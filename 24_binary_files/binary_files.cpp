#include <fstream>
#include <iostream>

int main(int argc, char* argv[]){
    std::ofstream file_out;

    if (!file_out){
        std::cerr << "Error incorrect usage." << std::endl;
        return 1;
    }

    char *file_name = argv[1];

    file_out.open(file_name, std::ios::binary);

    // Check file opening
    if (!file_out){
        std::cerr << "Error: could not open the file!" << std::endl;
        return 1;
    }

    int v = 1000;

    // Write into a binary file
    file_out.write(reinterpret_cast<char*>(&v), sizeof(v));

    // Close the file
    file_out.close();

    // Reading from a binary file
    std::ifstream file_in(file_name, std::ios::binary);
    file_in.open(file_name,  std::ios::binary);

    if (!file_in){
        std::cerr << "Error: could not open the file!" << std::endl;
        return 1;
    }

    int v2;
    file_in.read(reinterpret_cast<char*>(&v2), sizeof(v2));

    file_in.close();

    std::cout << v2 << std::endl;


    return 0;
}