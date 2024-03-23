#include "Shape.h"
#include "stress-theory.h"
#include <iostream>

int main() {

	// declaration of variables
	double normalStressXX, normalStressYY, normalStressZZ, shearStressXY;

	// instructions to user
	std::cout << "Insert the values for stress acting on your element.\n+ = tensile stress\n- = compressive stress" << std::endl << std::endl;

	// user input of variables (will later be replaced with sensor input)
	std::cout << "Enter value for normal stress in the X-direction: ";
	std::cin >> normalStressXX;
	std::cout << "Enter value for normal stress in the Y-direction: ";
	std::cin >> normalStressYY;
	std::cout << "Enter value for normal stress in the Z-direction: ";
	std::cin >> normalStressZZ;
	std::cout << "Enter value for the shear stress in the XY plane: ";
	std::cin >> shearStressXY;
	std::cout << std::endl;
	// end of user input

	return 0;
}