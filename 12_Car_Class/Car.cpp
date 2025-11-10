// The implementation of a Car class
#include "Car.hpp"
#include <iostream>
// No-arg constructor
Car::Car() {
setMake("Unknown");
setModel("Unknown");
setYear(1900);
setMPG(0.0);
}
Car::Car(std::string make, std::string model, int year, double MPG) {
setMake(make);
setModel(model);
setYear(year);
setMPG(MPG);
}
// Setters
void Car::setMake(std::string newMake) {
if (!newMake.empty()) {
make = newMake;
}
}
void Car::setModel(std::string newModel) {
if (!newModel.empty()) {
model = newModel;
}
}
void Car::setYear(int newYear) {
year = (newYear >= 1900 && newYear <= 2025) ? newYear : 1900;
}
void Car::setMPG(double newMPG) {
MPG = (newMPG > 0) ? newMPG : 0;
}
// Getters
std::string Car::getMake() const { return make; }
std::string Car::getModel() const { return model; }
int Car::getYear() const { return year; }
double Car::getMPG() const { return MPG; }
// Print
void Car::print(void) const {
std::cout << getMake() << std::endl;
std::cout << getModel() << std::endl;
std::cout << getYear() << std::endl;
std::cout << getMPG() << std::endl;
}
