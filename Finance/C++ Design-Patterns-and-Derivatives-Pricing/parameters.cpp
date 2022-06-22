#include "parameters.hpp"

Parameters::Parameters(const ParametersInner& innerObject) {
    InnerObjectPtr = innerObject.clone();
}

Parameters::Paramaters(const Paramaters& original){
    InnerObjectPtr = original.InnerObjectPtr->clone();
}

Parameters& Paramaters::operator=(const Parameters& original){
    if(this != &original){
        delete InnerObjectPtr;
        InnerObjectPtr = original.InnerObjectPtr->clone();
    }
    return *this;
}

Paramaters::~Paramaters() {
    delete InnerObjectPtr;
}

double Parameters::Mean(double time1, double time2) const {
    double total = Integral(time1, time2);
    return total/(time2-time1);
}

double Parameters::RootMeanSquare( double time1, double time2) const{
    double total = IntegralSqaure(time1, time2);
    return total/(time2 - time1);
}

ParametersConstant::ParametersConstant(double constant){
    Constant = constant;
    ConstantSquare = Constant * Constant;
}

Parameters* ParametersConstant::clone() const {
    return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time1, double time2) const {
    return (time2-time1)*Constant;
}

double ParametersConstant::IntegralSquare(double time1, double time2) const {
    return (time2 - time1)* ConstantSquare
}