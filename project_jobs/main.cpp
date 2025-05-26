#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Job.h"
#include "Aplicant.h"
#include "utils.h"
#include "template_utils.h"

using namespace std;

int main(int argc, char* argv[]) {
    vector<Job> joburi;
    vector<Aplicare> aplicari;

    incarcaJoburi(joburi, "joburi.txt");
    incarcaAplicari(aplicari, "aplicari.txt");

    if (argc < 2) {
        cout << "Comanda lipsa. Foloseste --help pentru instructiuni.\n";
        return 1;
    }

    string comanda = argv[1];

    if (comanda == "--adauga-job") {
        if (argc < 5) {
            cout << "Utilizare: --adauga-job titlu companie skill1 [skill2 ...]\n";
            return 1;
        }

        string titlu = argv[2];
        string companie = argv[3];
        vector<string> skilluri;
        for (int i = 4; i < argc; ++i)
            skilluri.push_back(argv[i]);

        joburi.push_back(Job(titlu, companie, skilluri));
        cout << "Job adaugat cu succes!";
    }
    else if (comanda == "--aplica") {
        if (argc < 6) {
            cout << "Utilizare: --aplica nume email jobIndex skill1 [skill2 ...]\n";
            return 1;
        }

        string nume = argv[2];
        string email = argv[3];
        int jobIndex = atoi(argv[4]);

        if (jobIndex < 0 || jobIndex >= (int)joburi.size()) {
            cout << "Index job invalid.";
            return 1;
        }

        vector<string> skilluri;
        for (int i = 5; i < argc; ++i)
            skilluri.push_back(argv[i]);

        Aplicant a(nume, email, skilluri);
        aplicari.push_back((Aplicare){a, jobIndex});
        cout << "Aplicare salvata cu succes!\n";
    }
    else if (comanda == "--afiseaza-joburi") {
        afiseazaVector(joburi);
    }
    else if (comanda == "--filtreaza") {
        if (argc != 3) {
            cout << "Utilizare: --filtreaza skill\n";
            return 1;
        }

        string skill = argv[2];
        for (size_t i = 0; i < joburi.size(); ++i)
            if (joburi[i].necesitaSkill(skill))
                cout << joburi[i] << " ";
    }
    else if (comanda == "--aplicanti-job") {
        if (argc != 3) {
            cout << "Utilizare: --aplicanti-job index\n";
            return 1;
        }

        int index = atoi(argv[2]);
        if (index < 0 || index >= (int)joburi.size()) {
            cout << "Index invalid.\n";
            return 1;
        }

        for (size_t i = 0; i < aplicari.size(); ++i)
            if (aplicari[i].jobIndex == index)
                cout << aplicari[i].aplicant << "";
    }
    else if (comanda == "--help") {
        cout << "Comenzi disponibile:\n";
        cout << "  --adauga-job titlu companie skill1 [skill2 ...]\n";
        cout << "  --aplica nume email jobIndex skill1 [skill2 ...]\n";
        cout << "  --afiseaza-joburi\n";
        cout << "  --filtreaza skill\n";
        cout << "  --aplicanti-job index\n";
        cout << "  --stergere joburi\n";
    } else {
        cout << "Comanda necunoscuta. Foloseste --help\n";
    }

    salveazaJoburi(joburi, "joburi.txt");
    salveazaAplicari(aplicari, "aplicari.txt");

    return 0;
}
