#include <iostream>
#include <vector>



int numberOfDuplicates(const std::vector<int>& v) {
    int count = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        bool alreadyCounted = false;
        for (size_t k = 0; k < i; ++k) {
            if (v[k] == v[i]) {
                alreadyCounted = true;
                break;
            }
        }
        if (alreadyCounted) continue;
        int freq = 0;
        for (size_t j = 0; j < v.size(); ++j) {
            if (v[j] == v[i]) ++freq;
        }
        if (freq > 1) ++count;
    }
    return count;
}


void printVector(const std::vector<int>&v, int nums){
    for(int el: v){
        std::cout << el << ", ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> v{1, 2, 3, 4, 5, 5, 5, 6, 7, 7, 9, 2};
    std::cout << "The vector is: ";
    printVector(v, v.size());
    std::cout << "It has " << numberOfDuplicates(v) << " duplicate(s)" << std::endl;

}