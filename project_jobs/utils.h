#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include "Job.h"
#include "Aplicant.h"

using namespace std;

struct Aplicare {
    Aplicant aplicant;
    int jobIndex;
};

void salveazaJoburi(const vector<Job>& joburi, const string& filename);
void salveazaAplicari(const vector<Aplicare>& aplicari, const string& filename);
void incarcaJoburi(vector<Job>& joburi, const string& filename);
void incarcaAplicari(vector<Aplicare>& aplicari, const string& filename);

#endif
