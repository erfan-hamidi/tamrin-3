#include <iostream>
#include <string>
#include <cstring>
#include "Question.h"
#include "answersheet.h"
#include "FourChoicesQuestion.h"
using namespace std;

void  FourChoicesQuestion::setAnswer(Answer * c)
{
    an = c;
}
Answer *FourChoicesQuestion::getAnswer() const
{
    return an;
}
bool FourChoicesQuestion::hasAnswer() const
{
    if (an)
    {
        return true;
    }
    return false;
}
string FourChoicesQuestion::toString(bool showans) const
{
    string temp;
    temp += getText();
    temp += "\n";
    if (showans)
    {
        FourChoicesAnswer * q;
        q = dynamic_cast<FourChoicesAnswer *>(an); // down cast
        string a = q->get();
        temp += "1: ";
        temp += options[0];
        temp += "\n2: ";
        temp += options[1];
        temp += "\n3: ";
        temp += options[2];
        temp += "\n4: ";
        temp += options[3];
        temp += "answer:";
        temp += a;
        return temp;

    }
    temp += "1: ";
        temp += options[0];
        temp += "\n2: ";
        temp += options[1];
        temp += "\n3: ";
        temp += options[2];
        temp += "\n4: ";
        temp += options[3];
    return temp;   
}
void FourChoicesQuestion::setOption(size_t a , OptionText b)
{
    options.at(a-1) = b;
}
const array<string , 4> &FourChoicesQuestion::getOptions() const
{
    return options;
}
void FourChoicesAnswer::set(string a)
{
    an = a;
}
string FourChoicesAnswer::get() const
{
    return an;
}

void FourChoicesAnswer:: clear()
{
    an.clear();
}
FourChoicesAnswer::operator bool() const
{
    if (an.empty())
    {
        return false;
    }
    else
    return true;
}
void FourChoicesQuestion:: copy(Question * q) const
{
    FourChoicesQuestion * q1;
    q1 = dynamic_cast<FourChoicesQuestion *>(q);
    *q = *this;
}
 void FourChoicesQuestion::clone(Question * q) const
 {
    *q = *this;
    q->set_id(ques_id_maker());
 }
FourChoicesQuestion  & FourChoicesQuestion :: operator=(const FourChoicesQuestion  & q)
{
    *this = q;
    options = q.getOptions();
    return *this;
}

bool FourChoicesAnswer:: operator ==(const FourChoicesAnswer & a) const
{
    if (an == a.get())
    {
        return true;
    }
    return false; 
}