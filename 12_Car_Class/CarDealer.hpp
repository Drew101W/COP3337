#ifndef CARDEALER_H
#define CARDEALER_H


#include "Car.hpp"
#include <vector>

class CarDealer {
public:
    void showInventory() const;
    void addCar(const Car& car); // Adds the car object to the inventory
    std::vector<Car> getInventory() const {return inventory;}
private:
    std::vector<Car> inventory;


};

#endif