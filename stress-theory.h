#include <vector>

class stress_theory {
    protected:
        std::vector<double> principalStresses;
        double yieldStress;

        virtual std::vector<double> takeInput();
        virtual void returnValues();
};

class MSST : public stress_theory {
    public:
        MSST() {this->principalStresses = this->takeInput();}
        ~MSST() {}

        void calculate();
};

class DET : public stress_theory {
    public:
        DET() {this->principalStresses = this->takeInput();}
        ~DET() {}

        void calculate();
};