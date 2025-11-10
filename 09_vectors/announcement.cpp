#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// Helper function to check if a character is a vowel
bool isVowel(char c) {
    c = std::tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Reverse the vowels in the string
void reverseVowels(std::string &s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        while (left < right && !isVowel(s[left])) left++;
        while (left < right && !isVowel(s[right])) right--;
        if (left < right) {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
}

int main() {
    std::string s(
        ".snAutcirtsne lineetadde htow ioy adevurp lliw i ,"
        "toht ruf ecnedava datnemiced eht edavurp iay dno ssilc\n"
        "s'yudsendoW "
        "dnatta at ulbe tin ori eay fe\n\n"
        "01 - 40:serotcoL\n)2.11 ratpehC( scasaB retnaiP ,)7.21,6.21( sratceV ,"
        ")7 rotpohC( syarre ,)6-rutpihC( snoatcneF ,)5-rAtpahC( spaeL ,"
        ")4-retpohC( sgnortS dni sretcarihC:sratpehC keubtxeT\n"
        ")dIkso ub llaw sneotsaeq 01(. skrom 01 :skraM leteT\n\n"
        ".setanam 02 raf ,ssolC gnurod ,)yidsendeW( 5202/71/90:omuT & eteD\n"
        ".sselc yidsendeW roa nI 2 zioQ iveh ot gnuig ari iw ,rodnamir kcuiq o"
    );

    // Step 1: Reverse the entire string
    std::reverse(s.begin(), s.end());

    // Step 2: Reverse only the vowels
    reverseVowels(s);

    // Output the decoded message
    std::cout << s << std::endl;

    return 0;
}
/*
A quick reminder, we are going to have Quiz 2 in our Wednesday class.
Date & Time:09/17/2025 (Wednesday), during Class, for 20 minutes.

Total Marks: 10 marks .(10 questions will be asked)
Textbook Chapters:Characters and Strings (Chapter-4), Loops (Chapter-5), Functions (Chapter-6), Arrays (Chapter 7), Vectors (12.6,12.7), Pointer Basics (Chapter 11.2)
Lectures:04 - 10

If you are not able to attend Wednesday's
class and you provide the documented evidence for that, I will provide you with additional instructions.

*/