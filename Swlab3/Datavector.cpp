#include "Datavector.h"
#include <vector>
#include <cmath>
using namespace std;
DataVector::DataVector(int dimension){
    v.resize(dimension,0);
};
void DataVector::setDimension(int dimension){
    v.resize(dimension,0);
};
DataVector::~DataVector(){
    v.clear();
};
DataVector::DataVector(const DataVector & other):v(other.v)
{};
DataVector & DataVector::operator= (const DataVector & other){
    if(this != &other){
        v.clear();
        (*this).setDimension(other.v.size());
        int i;
        for(i = 0;i<other.v.size();i++){
            v[i] = other.v[i];
        }
        v.resize(other.v.size());
    }
    return *this;
};
DataVector DataVector::operator+(const DataVector &other){
    if(v.size() == other.v.size()){
        DataVector result(v.size());
        int i;
        for(i = 0;i<v.size();i++){
            result.v[i] = v[i] + other.v[i];
        }
        return result;
    }
    else{
        return *this;
    }
}
DataVector DataVector::operator-(const DataVector &other){
    if(v.size() == other.v.size()){
        DataVector result(v.size());
        int i;
        for(i = 0;i<v.size();i++){
            result.v[i] = v[i] - other.v[i];
        }
        return result;
    }
    else{
        return *this;
    }
}
double DataVector::operator*(const DataVector &other){
    if(v.size() == other.v.size()){
        double result;
        result = 0;
        int i;
        for(i = 0;i<v.size();i++){
            result += v[i] * other.v[i];
        }
        return result;
    }
    else{
        return 0;
    }
}
double DataVector ::norm(){
    double result;
    result = (*this)*(*this);
    result = sqrt(result);
    return result;
}
double DataVector::dist(const DataVector & other){
    double result;
    DataVector c;
    c = *this - other;
    result = c.norm();
    return result;
}
void DataVector::add(double & value){
    v.push_back(value);
}

