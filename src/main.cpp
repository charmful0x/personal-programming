#include<iostream>
#include<cassert>
#include<cmath>
#include "utils.h"

int main() {
    double M[2][2] = {{1, 2}, {4, 5}};
    double res = main_matrix_diagonal(M);
    std::cout << "trace = " << res << std::endl;
}