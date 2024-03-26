#include "mohrs-circle.h"
#include <iostream>
#include <math.h>

void Tensor::addData() {
    // User input to enter data to tenosr as well as instructions as to how to do it.
    std::cout << "Enter normal stress values in order of xyz seperated by spaces: " << std::endl;
    std::cin >> this->sigmaXX >> this->sigmaYY >> this->sigmaZZ;
    std::cout << "\nEnter shear stress values for the XY direction: " << std::endl;
    std::cin >> this->tauXY;
}

void mohrsCircle::findCenter() {
    // Finds the cetner by taking an average of the x and y stresses.
    this->center = (myTensor.sigmaXX + myTensor.sigmaYY)/2;
}

void mohrsCircle::findRadius() {
    // Uses pythagorean thm to find the radius.
    this->radius = sqrt(pow(this->myTensor.tauXY, 2) + pow(this->myTensor.sigmaXX - this->center, 2));
}

void mohrsCircle::determinePrincipals() {
    // Adds sigma 1 and 2 into the queue
    this->principalValues.push(this->center + this->radius);
    this->principalValues.push(this->center - this->radius);
    // Adds sigma 3 to queue
    this->principalValues.push(this->myTensor.sigmaZZ);
    // Adds tau max to the queue
    this->principalValues.push(this->radius);
}

void mohrsCircle::printInformation() {
    std::queue tempValues = principalValues; // Creates a temporary queue that can be emptied during for loop.

    std::cout << "Principal " << this->type << ", in order from I-III and max shear, is: " << std::endl;
    while (tempValues.empty() == false) {
        // Prints values then removes it from the temp queue
        std::cout << tempValues.front() << std::endl;
        tempValues.pop();
    }
}

stressCircle::stressCircle(Tensor directionalStresses) {
    this->type = "stresses"; // Label for printInformation
    this->myTensor = directionalStresses; // Stress tensor based on user input

    // Determines important data for the circle
    this->findCenter();
    this->findRadius();
    this->determinePrincipals();
}

strainCircle::strainCircle(Tensor directionalStrains) {
    this->type = "strains"; // Label for printInformation
    this->myTensor = directionalStrains; // Strain tensor based on user input

    // Determines important data for the circle
    this->findCenter();
    this->findRadius();
    this->determinePrincipals();
}