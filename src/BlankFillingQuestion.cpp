#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include "answersheet.h"
#include <random>
#include "Question.h"
#include "BlankFillingQuestion.h"
using namespace std;
BlankFillingQuestion & BlankFillingQuestion:: operator=(const BlankFillingQuestion & q)
{
    *this = q;
    placeholderStr = q.placeholderStr;
    return *this;
}
void  BlankFillingQuestion::setAnswer(Answer * c)
{
    an = c;
}
Answer *BlankFillingQuestion::getAnswer() const
{
    return an;
}
bool BlankFillingQuestion::hasAnswer() const
{
    if (an)
    {
        return true;
    }
    return false;
}
string BlankFillingQuestion::toString(bool showans) const
{
    if (showans)
    {
        BlankFillingAnswer * q;
        q = dynamic_cast<BlankFillingAnswer *>(an); // down cast
        string a = q->get();
        string temp = placeholderStr;
        temp += "answer:";
        temp += a;
        return temp;
    }
    return placeholderStr;   
}
Question::Text BlankFillingQuestion::getText() const
{
    return placeholderStr;
}
void  BlankFillingQuestion::setText(string a, string b)
{
    //cout << "hey";
    string temp;
    int q = a.find(b);
    //cout << q << endl;
    temp.assign(a,0,q);
    temp += "_________";
    //cout << temp<< endl;
    int q1 = a.length();
    int wq = b.length();
    string tem;
    tem.assign(a,q + wq,q1 - q + wq);
    //cout << tem;
    temp += tem;
    placeholderStr = temp;
    cout << placeholderStr;
}

BlankFillingAnswer::operator bool() const
{
    if (ans.empty())
    {
        return false;
    }
    else
    return true;
}
void BlankFillingAnswer::clear()
{
    ans.clear();
}
void BlankFillingAnswer::set(std::string a)
{
    ans = a;
}
string BlankFillingAnswer::get() const
{
    return ans;
}
void BlankFillingQuestion:: copy(Question * q) const
{
    BlankFillingQuestion * q1;
    q1 = dynamic_cast<BlankFillingQuestion *>(q);
    *q = *this;
}
void BlankFillingQuestion::clone(Question * q) const
 {
    *q = *this;
    q->set_id(ques_id_maker());
 }