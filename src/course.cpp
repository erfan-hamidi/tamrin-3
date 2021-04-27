#include <iostream>
#include <string>
#include <vector>
#include "course.h"
#include <stdexcept>
#include "exam.h"
using namespace std;

Course::Course(string a)
{
    setName(a);
}

string Course::getName() const
{
    return name;
}
void Course::setName(string a)
{
    name = a;
}
void Course::addExam(Exam exam)
{
    exams.push_back(exam);
}
void Course::removeExam(const Exam::Id &exam)
{
    int counter = 0;
    for (auto &i : exams)
    {
        counter++;
        if (i.getId() == exam)
        {
            exams.erase(exams.begin() + counter);
        }
    }
}
Exam &Course::editExam(const Exam::Id & exam)
{
    try
    {
        int result = searchExam(exam);

        if (result == -1)
        {
            throw invalid_argument("404 not found!!!");
        }

        for (size_t i = 0; i < exams.size(); i++)
        {
            if (exams[i].getId() == exam)
            {
                return exams[i];
            }
        }
    }
    catch (invalid_argument &invlidid)
    {
        cerr << invlidid.what() << endl;
        exit(0);
    }
    return exams[0]; // compiler never arrive to this line
}

Exam Course::cloneExam(const Id & E) const
{
    try
    {
        int result = searchExam(E);
        if (result == -1)
        {
            throw invalid_argument("404 not found!!!");
        }
        for (auto &i : exams)
        {
            if(i.getId() == E)
            {
                Exam clone_exam(i);
                return clone_exam;
            }
        }
        
    }
    catch (invalid_argument & a)
    {
        cerr << a.what() << endl;
    }
    return exams[0]; // compiler never arrive to this line
}

const Exam &Course::getExam(const Id & exam) const
{
    try
    {
        int result = searchExam(exam);
        if (result == -1)
        {
            throw invalid_argument("404 not found!!!");
        }
    }
    catch (invalid_argument &invlidid)
    {
        cerr << invlidid.what() << endl;
        exit(0);
    }
    for (size_t i = 0; i < exams.size(); i++)
    {
        if (exams[i].getId() == exam)
        {
            return exams[i];
        }
    }
    return exams[0]; // compiler never arrive to this line and it is for warning's
}
int Course::searchExam(const Id & e) const
{
    for (size_t i = 0; i < exams.size(); i++)
    {
        if (e == exams[i].getId())
        {
            return 1; // if found id
        }
    }
    return -1; // if not found id..
}

const vector<Exam> &Course::getExamList() const
{
    return exams;
}