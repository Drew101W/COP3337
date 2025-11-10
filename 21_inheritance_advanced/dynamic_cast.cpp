#include <iostream>

// TODO: Reload function for weapon and for all derived classes


class Weapon{ // Abstract class (at leaset one pure virtual function)
public:
    virtual void use(void) = 0; // Pure virtual function
    virtual void reload(void) {
        std::cout << "Reloading weapon..." << std::endl;    
        int magazine = 20;
    }

};
class Gun : public Weapon{
public:
    void use(void) override {
        std::cout << "BANG!" << std::endl;
    }
};

class MachineGun : public Gun{
public:
    int magazine = 20;
    void use(void) override {
        while(magazine-- > 0){
            std::cout << "BANG!";
        }
        std::cout << '\n';
        magazine = 20;
    }

};

class Bazooka : public Weapon{
public:
    void use(void) override {
        std::cout << "BOOM!" << std::endl;
    }

};
class Knife : public Weapon{
public:
Knife(bool stainless = false) : is_stainless(stainless) {}
    void use(void) override {
        std::cout << "SWISH!" << std::endl;
    }
    bool get_isStainless() const {
        return is_stainless;
    }

private:
    bool is_stainless;

};

class Player{
public:
    void use_weapon(Weapon& weapon) {
        // Dynamic casting
        Knife *knife = dynamic_cast<Knife*>(&weapon); // casting of a parent address to a child pointer
        if(knife != NULL){
            if (knife -> get_isStainless()) {
                std::cout << "Stainless knife. Can use it. " << std::endl;
                weapon.use();
            }
            else {
                std::cout << "Not stainless knife. Cannot use it. " << std::endl;
            }
        }
        else{
            std::cout << "Not a knife. Can use it. " << std::endl;
        }
        weapon.use();
    }
};

int main(void) {
    Gun gun;
    MachineGun mg;
    Bazooka bazooka;
    Knife knife;

    gun.use();
    //mg.shoot();
    bazooka.use();
    knife.use();

    // Create a reference to a base class
    Weapon& weapon = gun;
    weapon.use();

    std::cout << "---------------------" << std::endl;
    Player player;
    player.use_weapon(gun);
    player.use_weapon(mg);
    player.use_weapon(bazooka);
    player.use_weapon(knife);

    return 0;
}
