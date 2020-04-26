#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <algorithm>
class student
{
private:
    std::string name;
    std::string surname;
    std::vector<int> homework;
    int exam;
    double finalGrade;
    bool random;
public:
    //base constructors
    student()
    {
    }
    student(std::string n, std::string s): name(n), surname(s) {}
    //getters
    std::string getName() {return name;}
    std::string getSurname() {return surname;}
    std::vector<int> getGrades() {return homework;}
    int getGradesCount() {return homework.size(); }
    int getExam() {return exam;}
    bool getRandom() {return random;}
    double getFinal() {return finalGrade;}
    bool hasGrades() {return !homework.empty();}
    //setters
    void setName(int n) {name = n;}
    void setSurname (int s) {surname = s;}
    void addGrade(int grade) {homework.push_back(grade); }
    void setGrades(std::vector<int> grades) {homework = grades; }
    void setExam(int examg) {exam = examg; }
    void setRandom(bool reiksme) {random = reiksme; }
    void setFinal(double f) {finalGrade = f;}
    //operator
    student& operator=(const student& studd);
    //destructor
    ~student();
};

#endif // STUDENT_H