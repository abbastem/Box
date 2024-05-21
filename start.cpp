//
// Created by PcMax on ٢٠/٠٥/٢٠٢٤.
//

#include "iostream"
#include "start.h"


void start::Print(BOXData A) {

    for (int i = A.getSizeB() - 1; i >= 0; --i) {
        if (A.getArrayB()[i] != 0) {
            if (i == 0) {
                std::cout << A.getArrayB()[i] << " ";
                continue;
            }
            std::string Q = (A.getArrayB()[i - 1] > 0) ? " + " : " ";
            std::cout << A.getArrayB()[i] << "X^" << i << Q;
        }
    }

    std::cout << "\n-----------------------------------------" << std::endl;

    for (int i = A.getSizeM() - 1; i >= 0; --i) {
        if (A.getArrayM()[i] != 0) {
            if (i == 0) {
                std::cout << A.getArrayM()[i] << " ";
                continue;
            }
            std::string Q = (A.getArrayM()[i - 1] > 0) ? " + " : " ";
            std::cout << A.getArrayM()[i] << "X^" << i << Q;
        }
    }
    std::cout << "\n\n";
}


void start::printData(int a, int b, std::string s) {

    if (a == 111) {
        std::cout << "***** Solve " + s + " with Box[" << b << "] *****\n";
    } else {
        std::cout << "***** Box[" << a << "] " + s + " with" << " Box[" << b << "] *****\n";
    }
}
