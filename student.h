#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <algorithm>
//base class
class Stud_base
{
    protected:   
        std::string name;
        std::string surname;
        std::string id;
        
};
class student : public Stud_base
{
    private:
        std::vector<int> homework;
        int exam;
        double finalGrade;
        bool random;
    public:
        //base constructor
        student(std::string n, std::string s);

        student(std::string studentData);

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
        void setName(std::string n) {name = n;}
        void setSurname (std::string s) {surname = s;}
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