#include "stress-theory.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>

std::vector<double> stress_theory::takeInput() {
    // Condition to run loop. If false loop will run, otherwise it will stop.
    bool runCondition = false; 
    do { 
        // Input string.
        std::string stressString;

        // Deliminator varibles.
        std::string delim = ",";
        std::string token;
        size_t pos_start = 0, pos_end, delim_len = delim.length();

        std::cout << "Enter principal stresses from I-III seperated with commas: " << std::endl;
        std::cin >> stressString; 

        // Loop to take the input from user, deliminate and convert it to a double to be input to the stress vector.
        while ((pos_end = stressString.find(delim, pos_start)) != std::string::npos) {
            token = stressString.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            principalStresses.push_back(stod(token));
        }

        if (principalStresses.size() == 3) {
            runCondition = true;
            return this->principalStresses;
        }
        else {
            std::cout << "Incorrect number of stresses added. Try again." << std::endl;
        }
    }
    while (!runCondition); // Ensures that the code will run until the user inputs information correctly
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