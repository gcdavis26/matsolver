#include "Shape.h"
#include <iostream>
#include <cmath>

const double PI = 3.1415;

Rod::Rod(double diameter, double length)
{
	this->length = length;
	this->radius = diameter/2;
}

Rod::~Rod()
{
	std::cout << "Rod deleted" << std::endl;
}

double Rod::area()
{
	return PI * pow(this->radius, 2);
}

double Rod::mInertia()
{
	return 1 / 4 * PI * pow(this->radius, 4);
}

double Rod::pmInertia()
{
	return 1 / 2 * PI * pow(this->radius, 4);
}

Pipe::Pipe(double diameter_out, double diameter_in, double length)
{
	this->length = length;
	this->radius_in = diameter_in / 2;
	this->radius_out = diameter_out / 2;
}

Pipe::~Pipe()
{
	std::cout << "Pipe deleted" << std::endl;
}

double Pipe::area()
{
	return PI * (pow(this->radius_out, 2) - pow(this->radius_in, 2));
}

double Pipe::mInertia()
{
	return 1 / 4 * PI * (pow(this->radius_out, 4) - pow(this->radius_in, 4));
}

double Pipe::pmInertia()
{
	return 1 / 2 * PI * (pow(this->radius_out, 4) - pow(this->radius_in, 4));
}