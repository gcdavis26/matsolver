#pragma once

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
protected:
	double length;
	virtual double area() = 0;
	virtual double mInertia() = 0;
	virtual double pmInertia() = 0;
};

class Rod : public Shape
{
public: 
	Rod(double, double);
	~Rod();
	double area();
	double mInertia();
	double pmInertia();

private:
	double radius;
};

class Pipe : public Shape
{
public:
	Pipe(double, double, double);
	~Pipe();
	double area();
	double mInertia();
	double pmInertia();

private:
	double radius_in;
	double radius_out;
};


#endif