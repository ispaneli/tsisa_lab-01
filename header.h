// Copyright 2019 Medvate <ilia.bezverzhenko@mail.ru>

#ifndef __LAB1_HEADER_H
#define __LAB1_HEADER_H

#include <iostream>
#include <cmath>
#include <iomanip>

// "Золотое число".
const double goldenRatio = (1 + sqrt(5)) / 2;

// Выдает значение функции в заданной точке.
double Function(double& x) {
    return (double)- cos(0.5 * x) - 1;
}

/* Optimal Passive Method
 * Перебираем все возможные значения функции
 * и выбираем из них самое наименьшее. */
void OptimalPassiveMethod (double& begin, double& end, double& epsilon) {
    std::cout << std::endl;
    std::cout << "=====OPTIMAL PASSIVE METHOD=====" << std::endl;

    double Number = (end - begin) / epsilon - 1,
           Xi = begin,
           X_min = Xi,
           Y_min = Function(Xi);

    // Вывод таблицы.
    std::cout << std::fixed << std::setprecision(3) << std::right;
    std::cout << "|" << std::setw(4) << "N" << "  |   ";
    std::cout << std::setw(4) << "Xi" << "    |   ";
    std::cout << std::setw(6) << "F(Xi)" << "  |";
    std::cout << std::endl;
    std::string str = std::string(32, '=');
    std::cout << str << std::endl;
    std::cout << "|" << std::setw(4) << 1 << "  |   ";
    std::cout << std::setw(6) << Xi << "  |   ";
    std::cout << std::setw(6) << Function(Xi) << "  |";
    std::cout << std::endl;

    for (size_t i = 0; i < Number + 1; ++i) {
        // Переходим к следующей точки.
        Xi +=  epsilon;

        /* Сравниваем значение функции
         * в предыдущей точки и новой. */
        if (Function(Xi) < Y_min) {
            Y_min = Function(Xi);
            X_min = Xi;
        }

        // Вывод значений.
        std::cout << "|" << std::setw(4) << i + 2 << "  |   ";
        std::cout << std::setw(6) << Xi << "  |   ";
        std::cout << std::setw(6) << Function(Xi) << "  |";
        std::cout << std::endl;
    }

    std::cout << str << std::endl;

    // Вывод результата вычислений.
    std::cout << std::fixed << std::setprecision(1) << std::right;
    std::cout << "# OPM: Ymin = " << (int) Y_min;
    std::cout << ", при X = " << (int) X_min;
    std::cout << " ± " << epsilon << std::endl;
}

/* Golden Ratio Method.
 * Метод схож с методом Дихотомии.
 * Отличие - разделение отрезка
 * в отношении Золотого сечения. */
void GoldenRatioMethod (double begin, double end, double& epsilon) {
    std::cout << std::endl;
    std::string str = std::string(91, '=');
    std::cout << "===GOLDEN RATIO METHOD===" << std::endl;

    /* x1 и x2 - точки, которые делят отрезок
     * в отношении золотого сечения. */
    double x1 = end - (end - begin) / goldenRatio,
           x2 = begin + (end - begin) / goldenRatio;

    // Вывод таблицы.
    std::cout << std::fixed << std::setprecision(5) << std::right;
    std::cout << "|  " << std::setw(6) << "BEGIN" << "    |  ";
    std::cout << std::setw(5) << "END" << "    |   ";
    std::cout << std::setw(5) << "LENGTH" << "   |  ";
    std::cout << std::setw(5) << "X1" << "     |  ";
    std::cout << std::setw(5) << "X2" << "     |   ";
    std::cout << std::setw(6) << "F(x1)" << "   |   ";
    std::cout << std::setw(6) << "F(x2)" << "   |";
    std::cout << std::endl;
    str = std::string(91, '=');
    std::cout << str << std::endl;


    /* Выполняется до тех пор, пока не
     * будет достигнута требуемая точность. */
    for(size_t i = 1; (end - begin) / 2 > epsilon; ++i) {
        // Вывод значений.
        std::cout << "|  " << std::setw(6) << begin << "  |  ";
        std::cout << std::setw(6) << end << "  |  ";
        std::cout << std::setw(6) << end - begin << "   |  ";
        std::cout << std::setw(8) << x1 << "  |  ";
        std::cout << std::setw(8) << x2 << "  |  ";
        std::cout << std::setw(8) << Function(x1) << "  |  ";
        std::cout << std::setw(8) << Function(x2) << "  |  ";
        std::cout << std::endl;

        // Сравниваем значения функций в точках.
        if (Function(x1) >= Function(x2)) {
            begin = x1;
            x1 = x2;
            x2 = begin + (end - begin) / goldenRatio;
        } else {
            end = x2;
            x2 = x1;
            x1 = end - (end - begin) / goldenRatio;
        }
    }

    // Вывод последней точки таблицы.
    std::cout << "|  " << std::setw(6) << begin << "  |  ";
    std::cout << std::setw(6) << end << "  |  ";
    std::cout << std::setw(6) << end - begin << "   |  ";
    std::cout << std::setw(8) << x1 << "  |  ";
    std::cout << std::setw(8) << x2 << "  |     ";
    std::cout << std::setw(8) << "Length < epsilon    |";
    std::cout << std::endl;
    std::cout << str << std::endl;

    // Вывод результата вычислений.
    double tmp = (begin + end) / 2;
    std::cout << "# GRM: Ymin = " << Function(tmp);
    std::cout << ", при X = " << tmp << " ± ";
    std::cout << (end - begin) / 2 << std::endl;
}

#endif //__LAB1_HEADER_H
