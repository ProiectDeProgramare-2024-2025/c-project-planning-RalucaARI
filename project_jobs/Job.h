#ifndef JOB_H
#define JOB_H

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Job {
private:
    string titlu;
    string companie;
    vector<string> skilluri;

public:
    Job();
    Job(const string& titlu, const string& companie, const vector<string>& skilluri);

    void afiseaza() const;
    bool necesitaSkill(const string& skill) const;

    string getTitlu() const;
    string getCompanie() const;
    vector<string> getSkilluri() const;
    friend ostream& operator<<(ostream& out, const Job& job);

};

#endif
