#include "Datavector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class VectorDataset{
    vector <DataVector> d;
    public:
    VectorDataset();
    ~VectorDataset();
    void Add(DataVector & v);
    int size();
    void ReadDataset(ifstream & file);
};