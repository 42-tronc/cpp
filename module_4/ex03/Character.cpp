#include "Character.hpp"

Character::Character() : name("Character") {
    std::cout << "\e[3;37m" << name << "\e[0m was born 󰹼 󰼹\n";
    for (int i = 0; i < 4; i++) inventory[i] = NULL;
    floor = NULL;
}

Character::Character(const std::string& name) : name(name) {
    std::cout << "\e[3;37m" << name << "\e[0m was born 󰹼 󰼹\n";
    for (int i = 0; i < 4; i++) inventory[i] = NULL;
    floor = NULL;
}

Character::Character(const Character& other) {
    *this = other;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        if (inventory[i]) {
            delete inventory[i];
            // inventory[i] = NULL;
        }

    if (floor) {
        delete floor;
        floor = NULL;
    }
    std::cout << "\e[3;37m" << name << "\e[31m died 󰥓\e[0m\n";
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        for (int i = 0; i < 4; i++) {
            if (inventory[i]) {
                delete inventory[i];
                inventory[i] = NULL;
            }

            if (other.inventory[i])
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
        // if (floor) {
        //     delete floor;
        //     floor = NULL;
        // }
        // if (other.floor)
        //     floor = other.floor->clone();
        // else
        //     floor = NULL;
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
    std::cout << "\e[3;37m" << name << "\e[0m unequipped \e[1;94m"
              << inventory[idx]->getType() << "\e[0m at index \e[1;94m" << idx
              << "\e[0m\n";
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
    this->inventory[idx]->use(target);
    // delete this->inventory[idx];
    // this->inventory[idx] = NULL;
}
