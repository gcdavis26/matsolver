#include "stress-theory.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

std::vector<double> stress_theory::takeInput() {
    // Input string.
    std::string s1, s2, s3;
    std::vector<std::string> stresses = {s1, s2, s3};

    std::cout << "Enter principal stresses from I-III seperated with spaces: " << std::endl;
    std::cin >> s1 >> s2 >> s3;
 
    // Currently an issue with conversion from string to double
    for (auto s : stresses) {
        this->principalStresses.emplace_back(stod(s));
    }

    return this->principalStresses;
}

void stress_theory::returnValues() {
    std::cout << "Yield stress of the specimen is: " << this->yieldStress << std::endl;
}

void MSST::calculate() {
    std::vector<double> possibleYield;
    double yield;
    // Main equations of the MSST method (sigma1-sigma2=sigmaYield)
    possibleYield.emplace_back(abs(this->principalStresses[0] - this->principalStresses[1]));
    possibleYield.emplace_back(abs(this->principalStresses[1] - this->principalStresses[2]));
    possibleYield.emplace_back(abs(this->principalStresses[2] - this->principalStresses[0]));

    // Helps avoid possible issues in defining the limiting case.
    yield = possibleYield[0];

    // Determines the limiting case for yielding by determining if the current value is smaller than the smallest found.
    for (auto stress : possibleYield) {
        if (stress < yield) {
            yield = stress;
        }
    }

    this->yieldStress = yield;
}

void DET::calculate() {
    // Calculates the yield based on the DET formula.
    this->yieldStress = sqrt(pow(this->principalStresses[0], 2) + pow(this->principalStresses[1], 2) + 
                       pow(this->principalStresses[2], 2) - (this->principalStresses[0] * this->principalStresses[1]) -
                       (this->principalStresses[0] * this->principalStresses[1]) - 
                       (this->principalStresses[0] * this->principalStresses[1]));
}