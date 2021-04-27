#include <iostream>
#include <string>
#include <stdexcept>
#include "answersheet.h"
#include "Question.h"
#include "exam.h"
using namespace std;
const std::vector<Question *> & AnswerSheet::getQuestionList() const
{
    return questions;
}

Question * AnswerSheet::editQuestion(const Id & q)
{
    check_id_question(q);
    for (auto &i : questions)
    {
        if(i->getId() == q)
        {
            return i;
        }
    }
    return questions[0]; // compiler never arrive this line
}

Question::Score AnswerSheet::getTotalScore() const
{
    float sum = 0;
    for (auto &i : questions)
    {
        sum += i->getScore();
    }
    return sum;
}

AnswerSheet::AnswerSheet(const AnswerSheet & ans)
{
    // cout << "heehh:  \n";
    // cout  << questions.size() << endl;
    questions = ans.getQuestionList();
}

void AnswerSheet::check_id_question(Id id) const 
{
    try
    {
        for (auto &i : questions)
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
void AnswerSheet::addQuestion(Question *q)
{
    questions.push_back(q);
    //cout << "after:  \n";
}

void AnswerSheet::removeQuestion(const Question::Id & q)
{
    int counter = 0;
    for (auto &i : questions)
    {
        counter++;
        if (i->getId() == q)
        {
            questions.erase(questions.begin() + counter);
        }
    }
}
void AnswerSheet:: setanswer(Answer * a,int i) const
{
    questions.at(i - 1)->setAnswer(a);
}