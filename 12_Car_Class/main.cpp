// Testing file
#include "Car.hpp"
#include "CarDealer.hpp"
#include <iostream>

// Returns true if the given car is efficient
bool isEfficient(const Car& car);


int numberOfInefficientCars(const CarDealer&);


int main(void) {
// Create a car object
    Car ferrari_spider("Ferrari", "Spider", 2021, 16.4);
    Car ferrari_superGT("Ferrari", "Super GT", 2025, 23.4);
    ferrari_spider.print();
    Car ferrari_f50;
    ferrari_f50.setMake("Ferrari");
    ferrari_f50.setModel("F 50");
    ferrari_f50.setYear(2025);
    ferrari_f50.setMPG(10.5);


    ferrari_f50.print();

    // Check whether the car is efficient
    std::cout << "\n" << (isEfficient(ferrari_f50) ? "Efficient" : "Inefficient") << "\n";
    std::cout << "\n" << (isEfficient(ferrari_superGT) ? "Efficient" : "Inefficient")  << "\n";
    std::cout << "\n" << (isEfficient(ferrari_spider) ? "Efficient" : "Inefficient")  << "\n";

    // Create a CarDealer object
    CarDealer ferrari_lakeland;
    ferrari_lakeland.addCar(ferrari_f50);
    ferrari_lakeland.addCar(ferrari_spider);
    ferrari_lakeland.addCar(ferrari_superGT);
    
    ferrari_lakeland.showInventory();
    // Print dealers inefficient cars
    std::cout << numberOfInefficientCars(ferrari_lakeland) << std::endl;



    return 0;
}


// Function implementation
bool isEfficient(const Car& car) {
    return (car.getMPG() > 20.0) ? true : false;
}

int numberOfInefficientCars(const CarDealer& car_dealer){
    int n_cars = 0;
    for (Car& car : car_dealer.getInventory()) {
        if (!isEfficient(car)) {
            n_cars++;
        }
    }
    return n_cars;
}
