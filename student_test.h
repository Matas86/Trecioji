#ifndef STUDENT_TEST_H
#define STUDENT_TEST_H

#include <string>
#include <vector>

struct student
{
    std::string name;
    std::string surname;
    int homeworkSum;
    std::vector<int> homework;
    int exam;
    double finalGrade;
    bool random;
    bool cool;
    student()
    {
        homeworkSum = 0;
    }
};

#endif // STUDENT_H