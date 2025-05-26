#include "Aplicant.h"

Aplicant::Aplicant() {}

Aplicant::Aplicant(const string& nume, const string& email, const vector<string>& skilluri) {
    this->nume = nume;
    this->email = email;
    this->skilluri = skilluri;
}

void Aplicant::afiseaza() const {
    cout << "Nume: " << nume << ", Email: " << email << ", Skilluri: ";
    for (size_t i = 0; i < skilluri.size(); ++i)
        cout << skilluri[i] << " ";
    cout << "\n";
}

string Aplicant::getNume() const {
    return nume;
}

string Aplicant::getEmail() const {
    return email;
}

vector<string> Aplicant::getSkilluri() const {
    return skilluri;
}

ostream& operator<<(ostream& out, const Aplicant& aplicant) {
    out << "Nume: " << aplicant.nume << ", Email: " << aplicant.email << ", Skilluri: ";
    for (size_t i = 0; i < aplicant.skilluri.size(); ++i)
        out << aplicant.skilluri[i] << " ";
    return out;
}
