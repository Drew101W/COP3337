#include "Point.hpp"
#include <cstring>

Point::Point(int x, int y, const char* tag) {
    this->x = x;
    this->y = y;
    if (tag) {
        int size = strlen(tag);
        this->tag = new char[size + 1];
        strcpy(this->tag, tag);
    }
    else {
        this->tag = nullptr;
    }
}

Point::~Point() {
    if (tag) {
        delete[] tag;
    }
}

Point::Point(const Point& other){
    x = other.x;
    y = other.y;
    if (other.tag) {
        int size = strlen(other.tag);
        this->tag = new char[size + 1];
        strcpy(this->tag, other.tag);
    }
    else {
        tag = other.tag;
    }
}
bool  Point::operator==(const Point& other) const{
    return(x == other.x && y == other.y);

}

int& Point::operator[](int index) {
    return (index == 0) ? x : y;
}

bool Point::operator!=(const Point& other) const{
    return !(*this == other);
}

Point Point::operator+(const Point& other) const{
    return Point(x + other.x, y + other.y);
}

Point Point::operator+=(const Point& other) const{
    return Point(x + other.x, y + other.y);
}

Point Point::operator*(const Point& other) const{
    return Point(x * other.x, y * other.y);
}
Point Point::operator*=(const Point& other) const{
    return Point(x * other.x, y * other.y);
}

std::string Point::toString(void) const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}


Point Point::operator-() {
    return Point(-x, -y);
}
// Preincrement
Point Point::operator++(){
    x +=1 ;
    y +=1 ;
    return *this;
}
// Postincrement
Point Point::operator++(int ){
    Point temp(*this);
    this->x += 1;
    this->y += 1;
    return temp;
}
// Postdecrement
Point Point::operator--(int ){
    Point temp(*this);
    this->x -= 1;
    this->y -= 1;
    return temp;
}
// Predecrement
Point Point::operator--(){
    x -=1 ;
    y -=1 ;
    return *this;
}

void Point::operator=(const Point& other){
    x = other.x;
    y = other.y;
    if (tag) {
        delete[] tag;
    }
    if (other.tag) {
        int size = strlen(other.tag);
        tag = new char[size + 1];
        strcpy(tag, other.tag);
    }
    else {
        tag = nullptr;
    }
}


std::ostream& operator<<(std::ostream& out, Point& point){
    out << point.toString();
    return out;
}

std::istream& operator>>(std::istream& in, Point& point){
    in >> point.x >> point.y;
    return in; 
}

