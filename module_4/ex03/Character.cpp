#include "Character.hpp"

Character::Character() : name("Character") {
    std::cout << "\e[3;37m" << name << "\e[32m was born 󰹼 󰼹\n";
    for (int i = 0; i < 4; i++) inventory[i] = NULL;
    floor = NULL;
}

Character::Character(const std::string name) : name(name) {
    std::cout << "\e[3;37m" << name << "\e[32m was born 󰹼 󰼹\n";
    for (int i = 0; i < 4; i++) inventory[i] = NULL;
    floor = NULL;
}

Character::Character(const Character& other) {
    *this = other;
}

Character::~Character() {
    std::cout << "\e[3;37m" << name << "\e[31m died\e[0m" << std::endl;
    for (int i = 0; i < 4; i++)
        if (inventory[i]) delete inventory[i];
    if (floor) delete floor;
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; i++) {
            if (inventory[i]) delete inventory[i];
            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

void Character::setName(std::string name) {
    this->name = name;
}

std::string const& Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) {
        std::cout << "\e[1;31mError: \e[0;mmateria doesn't exist\e[0m\n";
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (inventory[i] == m) {
            std::cout << "\e[1;31mError: \e[0;mmateria already equipped\e[0m\n";
            return;
        }
        if (!inventory[i]) {
            inventory[i] = m;
            std::cout << "\e[3;37m" << name << "\e[0m equipped \e[1;94m"
                      << m->getType() << "\e[0m at index \e[1;94m" << i
                      << "\e[0m\n";
            return;
        } else
            std::cout << "\e[90m" << name
                      << " already has a materia at index \e[94m" << i
                      << "\e[0m\n";
    }
    delete m;
    std::cout << "\e[1;31mError: \e[0;mmateria inventory is full\e[0m\n";
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3) {
        std::cout << "\e[1;31mError: index out of bounds\e[0m\n";
        return;
    }
    if (!inventory[idx]) {
        std::cout << "\e[1;31mError: nothing equipped at index " << idx
                  << "\e[0m\n";
        return;
    }
    if (floor) {
        std::cout << inventory[idx]->getType() << " just despawned\n";
        delete inventory[idx];
    }
    std::cout << "\e[3;37m" << name << "\e[0m dropped \e[1;94m"
              << inventory[idx]->getType() << "\e[0m on the floor\n";
    floor = inventory[idx]->clone();
    delete inventory[idx];
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx > 3) {
        std::cout << "\e[1;31mError: index out of bounds\e[0m\n";
        return;
    }
    if (!inventory[idx]) {
        std::cout << "\e[1;31mError: nothing equipped at index " << idx
                  << "\e[0m\n";
        return;
    }
    inventory[idx]->use(target);
    delete inventory[idx];
    inventory[idx] = NULL;
}
