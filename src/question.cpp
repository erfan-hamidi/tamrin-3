#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include "C:\code\header\course.h"
#include "C:\code\header\Question.h"
using namespace std;

Id Question::getId() const
{
    return id;
}

void Question::setText(Text a)
{
    text = a;
}
void Question::setScore(Score a)
{
    score = a;
}
string Question::getText() const
{
    return text;
}
Score Question:: getScore() const
{
    return score;
}
Score Question::operator+(const Question & q) const
{
    Score a = q.getScore();
    a += score;
    return a;
}
Score operator+(Score a, const Question & q)
{
    a += q.score;
    return a;
}
Question::Question(Text a, Score b)
{
    text = a;
    score = b;
}
void Question:: copy(Question * q) const
{
    *q = (*this);
}
Question& Question::operator=(const Question& q)
{
    text = q.getText();
    score = q.getScore();
    id = q.getId();
    an = q.getAnswer();
    return *this;
}
void Question:: set_id(string a)
{
    id = a;
}
void Question:: clone(Question * q) const
{
    *q = (*this);
    q->set_id(ques_id_maker());
}