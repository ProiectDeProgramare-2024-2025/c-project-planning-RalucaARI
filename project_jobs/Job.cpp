#include "Job.h"

Job::Job() {}

Job::Job(const string& titlu, const string& companie, const vector<string>& skilluri) {
    this->titlu = titlu;
    this->companie = companie;
    this->skilluri = skilluri;
}

void Job::afiseaza() const {
    cout << "Titlu: " << titlu << ", Companie: " << companie << ", Skilluri: ";
    for (size_t i = 0; i < skilluri.size(); ++i)
        cout << skilluri[i] << " ";
    cout << "\n";
}

bool Job::necesitaSkill(const string& skill) const {
    for (size_t i = 0; i < skilluri.size(); ++i)
        if (skilluri[i] == skill)
            return true;
    return false;
}

string Job::getTitlu() const {
    return titlu;
}

string Job::getCompanie() const {
    return companie;
}

vector<string> Job::getSkilluri() const {
    return skilluri;
}

ostream& operator<<(ostream& out, const Job& job) {
    out << "Titlu: " << job.titlu << ", Companie: " << job.companie << ", Skilluri: ";
    for (size_t i = 0; i < job.skilluri.size(); ++i)
        out << job.skilluri[i] << " ";
    return out;
}
