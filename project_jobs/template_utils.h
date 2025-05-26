#ifndef TEMPLATE_UTILS_H
#define TEMPLATE_UTILS_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void afiseazaVector(const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << "\n";
}

#endif
