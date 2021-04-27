#include <iostream>
#include <string>
#include <random>
#include "course.h"
#include "exam.h"
using namespace std;
Exam::Exam()  // constructor
{
    id = exam_id_maker(); 
    answerSheet.resize(1);
    
}
Id Exam::getId() const
{
    return id;
}
Exam::Exam(const Exam &selectedExam)
{
    answerSheet = selectedExam.answerSheet;
}

void Exam::removeQuestion(const Id & q)
{
    check_id_question(q);
    for (auto &i : answerSheet[0].getQuestionList())
    {
        if (i->getId() == q)
        {
            answerSheet[0].removeQuestion(q);
        }
    }
}

Question *Exam::editQuestion(const Question::Id &q)
{
    check_id_question(q);
    for (auto &i : answerSheet[0].getQuestionList())
    {
        if (q == i->getId())
        {
            return i;
        }
    }
    return answerSheet[0].getQuestionList()[0]; // compiler never arrive this line
}

AnswerSheet Exam::startTaking() const
{
    //cout << "ajab:  \n";
    AnswerSheet anssheet(answerSheet[0]);
    //cout << "2ajab:  \n";
    return anssheet;
}

Score Exam::getMaxScore() const
{
    Score sum = 0;
    for (auto &i : answerSheet[0].getQuestionList())
    {
        sum += i->getScore();
    }
    return sum; // max score of exam
    
}

void Exam::addQuestion(Question *q)
{
    
    answerSheet[0].addQuestion(q);
    
}

void Exam::check_id_question(Id id) const
{
    try
    {
        for (auto &i : answerSheet[0].getQuestionList())
        {
            if (i->getId() == id)
            {
                return;
            }
        }
        throw invalid_argument("404 not found!!!");
    }
    catch (invalid_argument &error_id)
    {
        cerr << error_id.what() << endl;
        exit(0);
    }
}

void Exam::commitAnswerSheet(AnswerSheet answer)
{
    answerSheet.push_back(answer);
}

const Exam &Exam::operator=(const Exam &second_operand)
{
    this->id = second_operand.id;
    this->answerSheet = second_operand.answerSheet;
    return *this;
}

const Question *Exam::getQuestion(const Question::Id &q) const
{

    check_id_question(q);
    for (auto &i : answerSheet[0].getQuestionList())
    {
        if (q == i->getId())
        {
            return i;
        }
    }
    return answerSheet[0].getQuestionList()[0]; // compiler never arrive this line
}

const std::vector<Question *> &Exam::getQuestionList() const
{
    return answerSheet[0].getQuestionList();
}


Question *Exam::operator[](const Question::Id &q) const
{
    check_id_question(q);
    for (auto &i : answerSheet[0].getQuestionList())
    {
        if (q == i->getId())
        {
            return i;
        }
    }
    return answerSheet[0].getQuestionList()[0]; // compiler never arrive this line
}
