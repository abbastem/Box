//
// Created by PcMax on ٢٠/٠٥/٢٠٢٤.
//

#include "Git.h"

int Git::getMax(int a, int b) {
    if (a == b)
        return a;
    return (a > b)? a : b;
}

int Git::getMin(int a, int b) {
    if (a == b)
        return a;
    return (a < b)? a : b;
}

int Git::getSizeForS(int a, int b) {
    return (a + b) - 1;
}