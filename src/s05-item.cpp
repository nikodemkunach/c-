#include <iostream>
#include "Item.h"

class Weapon : public Item
{
    public:
    auto use_on(Creature& creature) -> void
    {
        creature.hp -= strength();
    }
};

class Potion : public Item
{
    public:
    auto use_on(Creature& creature) -> void
    {
        creature.hp += strength();
    }
};

class Sword : public Weapon
{
    public:
    auto strength() const -> int
    {
        return 10;
    }
};

class Axe : public Weapon
{
    public:
    auto strength() const -> int
    {
        return 20;
    }
};

class Bow : public Weapon
{
    public:
    auto strength() const -> int
    {
        return 30;
    }
};

class Health_potion : public Potion
{
    public:
    int timesUsed = 0;
    auto strength() const -> int {
    return 25;
    }
    auto use_on(Creature& creature) -> void
    {
        if (timesUsed < 2) {
        creature.hp += strength();
        timesUsed++;
        };
    }
};

auto main() -> int
{   
    Bow bow;
    Sword sword;
    Axe axe;
    Health_potion potion;
    Creature creature("Dragon", 100);
    
    std::cout <<"Monster health: " << std::endl;
    std::cout << creature.hp << std::endl;

    std::cout <<"Mosnter health after hit by bow: " << std::endl;
    bow.use_on(creature);
    std::cout << creature.hp << std::endl;

    std::cout <<"Mosnter health after hit by axe: " << std::endl;
    axe.use_on(creature);
    std::cout << creature.hp << std::endl;
    
    std::cout <<"Mosnter health after healing by health potion: " << std::endl;
    potion.use_on(creature);
    std::cout << creature.hp << std::endl;

    std::cout <<"Mosnter health after hit by sword: " << std::endl;
    sword.use_on(creature);
    std::cout << creature.hp << std::endl;

    std::cout <<"Mosnter health after healing by health potion: " << std::endl;
    potion.use_on(creature);
    std::cout << creature.hp << std::endl;

    std::cout <<"Mosnter health after healing by health potion: " << std::endl;
    potion.use_on(creature);
    std::cout << creature.hp << std::endl;
    return 0;
}
