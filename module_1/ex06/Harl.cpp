#include "Harl.hpp"

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    size_t i;

    for (i = 0; i < (sizeof(levels) / sizeof(levels[0])); i++) {
        if (level == levels[i]) break;
    }
    switch (i) {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;

        default:
            std::cout << "\e[1;35m[UNKNOWN]\e[0m Oh boy he's talking about "
                         "slurpees again..."
                      << std::endl;
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
