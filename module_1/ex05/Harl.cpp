#include "Harl.hpp"

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*functions[4])(void) = {
        &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*functions[i])();
            return;
        }
    }
}

void Harl::debug(void) {
    std::cout << "\e[1;34m[DEBUG]\e[0m Duuuude, I sure loooove mixing all of "
                 "the slurpee flavors at the 7-11!"
              << std::endl;
}

void Harl::info(void) {
    std::cout
        << "\e[1;32m[INFO]\e[0m I am so happy I could get a slurpee right "
           "now!"
        << std::endl;
}

void Harl::warning(void) {
    std::cout << "\e[1;33m[WARNING]\e[0m What?!? There is no more cherry "
                 "flavored slurpee? I can't believe this!"
              << std::endl;
}

void Harl::error(void) {
    std::cout
        << "\e[1;31m[ERROR]\e[0m OOOH I AM SO MAD RIGHT NOW! I swear I "
           "am not leaving this 7-11 until I get my cherry flavored slurpee!"
        << std::endl;
}
