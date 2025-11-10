

#include <iostream>
#include <cmath>
#include <vector>
void rotateLeft(std::vector<char>& v, int k);


void rotateLeft(std::vector<char>& v, int k) {
    if (v.empty()) return;
    k %= v.size();
    while (k--) {
        int temp = v.front();      // Save first element
        v.erase(v.begin());        // Remove first element
        v.push_back(temp);         // Add it to the end
    }
}

int main(void) {
std::vector<char> attend {'1', 'u', '3', '4', 'g', '6', 'r', 'j', 'y', 'j',
'd', 'd', 'f', 'h', 's', 'd', 'f', '5', 'a', 'd', 'h', '6', 'j', 's', 'd', 'f',
'j', '1', 's', 'v', 'a', '8', 'q', 'n', 'a', 'o', '9', 's', 'j', 'd', 'f'};
int n_rotations = pow((50 * 2 - 75 / 3 + 20 % 7 + 20 + 12 / 4), 3);
rotateLeft(attend, n_rotations);
for(int i = 0; i < 5; i++) {
std::cout << attend.at(i);
}
std::cout << '\n';
return 0;
}
