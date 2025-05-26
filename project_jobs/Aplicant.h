#ifndef APLICANT_H
#define APLICANT_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Aplicant {
private:
    string nume;
    string email;
    vector<string> skilluri;

public:
    Aplicant();
    Aplicant(const string& nume, const string& email, const vector<string>& skilluri);

    void afiseaza() const;
    string getNume() const;
    string getEmail() const;
    vector<string> getSkilluri() const;
    friend ostream& operator<<(ostream& out, const Aplicant& aplicant);

};

#endif
