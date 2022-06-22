#ifndef PARAMETERS_HPP
#define PARAMETERS_HPP

class ParametersInner {
    public:
        parametersInner(){}
        virtual ParametersInner* clone() const=0;
        virtual double Intergral(double time1, double time2) const =0;
        virtual double intergralSquare( double time1, double time2) const =0;
        virtual ~ParametersInner(){}
};

class Parameters {
    private:
        ParametersInner* InnerObjectPtr;
    public: 
        Parameters(const ParametersInner& innerObject);
        Parameters(const Parameters& original);
        Parameters& operator=(const Parameters& original);
        virtual ~Parameters();

        inline double Intergral(double time1, double time2) const;
        inline double IntergralSquare(double time1, double time2) const;

        double Mean(double time1, double time2) const;
        double RootMeanSquare(double time1, double time2) const;
};
inline double Paramaters::Intergral(double time1, double time2) const {
    return InnerObjectPtr->Integral(time1, time2);
}
inline double Parameters::IntergralSquare(double time1, double time2) const {
    return InnerObjectPtr->intergralSquare(time1, time2);
}

class ParametersConstant : public ParametersInner {
    private:
        double Constant;
        double ConstantSquare;
    public:
        ParametersConstant(double constant);

        virtual ParamatersInner* clone() const;
        virtual double Integral( double time1, double time2);
        virtual double IntegralSquare(double time1, double time2);
};

#endif