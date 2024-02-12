#include <iostream>
#include <fstream>
#include <string>
#include "VectorDataset.h"
#include <sstream>

using namespace std;

int main() {
string line;
ifstream file("fmnist-test.csv");
VectorDataset d;
while (getline(file, line)) {
    // Create a stringstream to parse the line
    stringstream ss(line);

    // Define a vector to store the values of each line
    DataVector v;

    // Read each value separated by commas and store it in the row vector
    double value;
    char comma; // To capture the comma between double values
    while (ss >> value) {
        v.add(value);
        ss >> comma; // Consume the comma
    }

    // Add the row vector to the data vector
    d.Add(v);
}

// Close the file
file.close();

}
