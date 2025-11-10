#include <iostream>

class Character {
public:
    Character(unsigned hp_ = 100) : hp(hp_) {
        std::cout << "Characters constructor" << std::endl;
    }

    int hp;
    int dmg = 5;
    int lvl = 1;


};

class Elf : virtual public Character{
public:
    Elf() {
        std::cout <<"I am an Elf!" << std::endl;
    }
    void think() const{
        std::cout << "Lets not fight!" << std::endl;
    }
};
class Warrior : virtual public Character{
public:
    Warrior() {
        std::cout <<"I am an Warrior!" << std::endl;
    }
    void fight() const{
        std::cout << "Slash!!!!" << std::endl;

    }
};

class ElfWarrior : public Elf, public Warrior{
};


int main(void) {
    ElfWarrior buddy;
    buddy.think();
    buddy.fight();

    std::cout << buddy.Elf::hp << std::endl; // Error: ambiguous
    return 0;
}