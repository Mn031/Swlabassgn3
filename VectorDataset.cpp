#include "VectorDataset.h"
using namespace std;
VectorDataset::VectorDataset(){
    d.resize(0);
};
VectorDataset::~VectorDataset(){
    d.clear();
};
void VectorDataset::Add(DataVector &v){
    d.push_back(v);
};
int VectorDataset:: size(){
    return d.size();
}
void VectorDataset::Add(DataVector & value){
    d.push_back(value);
}
void VectorDataset::ReadDataset(ifstream & file){
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        DataVector v;
        double value;
        char comma;
        while (ss >> value) {
            v.add(value);
            ss >> comma;
        }
        (*this).Add(v);
    }
}
