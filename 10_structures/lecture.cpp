#include <iostream>
#include <string>
#include <iomanip>



// Prototype
void printLecture(const struct Lecture& lecture);
struct Lecture createLecture(std::string title, std::string author, int duration);

// Create a structure
// Inside are attributes/properties

struct Lecture {
    std::string title;
    std::string author;
    int duration; 
};


int main(void) {

    struct Lecture oop_the_best_lecture = createLecture("Structures", "Adam", 50);

    // Call the function
    printLecture(oop_the_best_lecture);

    return 0;
}

void printLecture(const struct Lecture& lecture){
        // Access the properties of an object
    std::cout << std::setw(15)<< std::left<< "Title: " << lecture.title << std::endl;
    std::cout << std::setw(15)<< std::left<< "Duration: " << lecture.duration / 60 << " minutes" << std::endl;
}

struct Lecture createLecture(std::string title, std::string author, int duration){
    // Create a lecture object
    struct Lecture oop_the_best_lecture;

    oop_the_best_lecture.title = title;
    oop_the_best_lecture.author = author;
    oop_the_best_lecture.duration = duration * 60;

    return oop_the_best_lecture;
}
