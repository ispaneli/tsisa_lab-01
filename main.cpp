// Copyright 2019 Medvate <ilia.bezverzhenko@mail.ru>

#include "header.h"

int main() {
    std::string str = std::string(32, '#');
    std::cout << str << std::endl;
    str = std::string(5, ' ');
    std::cout << str;
    std::cout << "ЛАБОРАТОРНАЯ РАБОТА №1." << std::endl;
    str = std::string(10, ' ');
    std::cout << str;
    std::cout << "(вариант №5)" << std::endl;
    str = std::string(32, '#');
    std::cout << str << std::endl << std::endl;

    double a = -2, b = 4, E = 0.1;

    // First Method.
    OptimalPassiveMethod(a, b, E);

    // Second Method.
    GoldenRatioMethod(a, b, E);

    return 0;
}