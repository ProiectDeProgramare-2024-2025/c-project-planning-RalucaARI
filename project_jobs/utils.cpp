#include "utils.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>


void salveazaJoburi(const vector<Job>& joburi, const string& filename) {
    ofstream fout(filename.c_str());
    if (!fout.is_open()) {
        cout << "Eroare la salvarea in " << filename << "\n";
        return;
    }

    for (size_t i = 0; i < joburi.size(); ++i) {
        fout << joburi[i].getTitlu() << "|"
             << joburi[i].getCompanie();

        vector<string> skills = joburi[i].getSkilluri();
        for (size_t j = 0; j < skills.size(); ++j)
            fout << "|" << skills[j];

        fout << "\n";
    }

    fout.close();
}

void salveazaAplicari(const vector<Aplicare>& aplicari, const string& filename) {
    ofstream fout(filename.c_str());
    if (!fout.is_open()) {
        cout << "Eroare la salvarea in " << filename << "\n";
        return;
    }

    for (size_t i = 0; i < aplicari.size(); ++i) {
        fout << aplicari[i].aplicant.getNume()
             << "|" << aplicari[i].aplicant.getEmail()
             << "|" << aplicari[i].jobIndex;

        vector<string> skills = aplicari[i].aplicant.getSkilluri();
        for (size_t j = 0; j < skills.size(); ++j)
            fout << "|" << skills[j];

        fout << "\n";
    }

    fout.close();
}

void incarcaJoburi(vector<Job>& joburi, const string& filename) {
    ifstream fin(filename.c_str());
    if (!fin.is_open()) return;

    string line;
    while (getline(fin, line)) {
        istringstream iss(line);
        string part;
        vector<string> tokens;

        while (getline(iss, part, '|'))
            tokens.push_back(part);

        if (tokens.size() >= 2) {
            string titlu = tokens[0];
            string companie = tokens[1];
            vector<string> skills;

            for (size_t i = 2; i < tokens.size(); ++i)
                skills.push_back(tokens[i]);

            joburi.push_back(Job(titlu, companie, skills));
        }
    }

    fin.close();
}

void incarcaAplicari(vector<Aplicare>& aplicari, const string& filename) {
    ifstream fin(filename.c_str());
    if (!fin.is_open()) return;

    string line;
    while (getline(fin, line)) {
        istringstream iss(line);
        string part;
        vector<string> tokens;

        while (getline(iss, part, '|'))
            tokens.push_back(part);

        if (tokens.size() >= 3) {
            string nume = tokens[0];
            string email = tokens[1];
            int jobIndex = atoi(tokens[2].c_str());

            vector<string> skills;
            for (size_t i = 3; i < tokens.size(); ++i)
                skills.push_back(tokens[i]);

            Aplicant a(nume, email, skills);
            aplicari.push_back((Aplicare){a, jobIndex});
        }
    }

    fin.close();
}
