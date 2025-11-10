#ifndef POINT_H
#define POINT_H
#include <string>
#include <ostream>

class Point {
public:
    Point(int x = 0, int y = 0, const char* tag = nullptr);
    ~Point();
    Point(const Point& other);


    // Logic operator
    bool  operator==(const Point& other) const;
    bool operator!=(const Point& other) const;
    int  operator[](int index) const;
    // Arithmetic operator
    Point operator+(const Point& other) const;
    Point operator+=(const Point& other) const;
    Point operator*(const Point& other) const;
    Point operator*=(const Point& other) const;

    // Arithmetic assignment operator

    int& operator[](int index);
    
    Point operator-();

    // Increment
    Point operator++(); // Preincrement
    Point operator++(int ); // Postincrement

    // TODO Decrement
    Point operator--(); // Predecrement
    Point operator--(int ); // Postdecrement

    // Assignment operator
    void operator=(const Point& other);

    std::string toString(void) const;

    // Friend function
    friend int sum_coordinates();

    friend std::ostream& operator<<(std::ostream& out, Point& point);
    friend std::istream& operator>>(std::istream& in, Point& point);

private:
    int x;
    int y;
    char *tag;
};

std::ostream& operator<<(std::ostream& out, Point& point);

#endif