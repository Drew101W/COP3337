#include <iostream>
#include <fstream>  

int main(int argc, char *argv[]){
    
    for (int i = 0; i < argc; i++){
        std::cout << argv[i] << std::endl;
    }

    if (argc != 2){
        std::cout << "Usage: " << argv[0] << " <file_name>" << std::endl;
        return 1;
    }
    
    
    
    return 0;
}