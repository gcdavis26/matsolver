#ifndef STRESS_LIB
#define STRESS_LIB

#include <queue>
#include <string>

struct Tensor {
    double sigmaXX, sigmaYY, sigmaZZ, tauXY;
    Tensor() {this->addData();}
    ~Tensor() {}

    void addData();
};

class mohrsCircle {
    protected:
        Tensor myTensor;
        double radius, center;
        std::queue<double> principalValues;
        std::string type;

        virtual void findRadius();
        virtual void findCenter();
        virtual void determinePrincipals();

    public:
        virtual void printInformation();
        virtual std::queue<double> getPrincipals() {return this->principalValues;}

        // Will implement during GUI stage
        virtual void drawCircle();
};

class stressCircle : public mohrsCircle {
    public:
        stressCircle(Tensor directionalStresses);
        ~stressCircle() {}
};

class strainCircle : public mohrsCircle {
    public:
        strainCircle(Tensor directionalStrains);
        ~strainCircle() {}
};

#endif