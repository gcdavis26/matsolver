#ifndef THEORY
#define THEORY

#include <vector>
#include <queue>

class stress_theory {
    protected:
        std::vector<double> principalStresses;
        double yieldStress;

        virtual void takeInput();
        virtual void returnValues();
};

class MSST : public stress_theory {
    public:
        MSST() {this->takeInput();}
        ~MSST() {}

        void calculate();
};

class DET : public stress_theory {
    public:
        DET() {this->takeInput();}
        ~DET() {}

        void calculate();
};

#endif