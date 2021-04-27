#include <iostream>
#include <string>
#include "Question.h"
#include "answer.h"
#include "TextualQuestion.h"
using namespace std;


void TextualQuestion::setAnswer(Answer * c)
{
    an = c;
}

Answer *TextualQuestion::getAnswer() const
{
    return an;
}

bool TextualQuestion::hasAnswer() const
{
    if (an)
    {
        return true;
    }
    return false;
}

string TextualQuestion::toString(bool showans) const
{
    if (showans)
    {
        TextualAnswer * q;
        q = dynamic_cast<TextualAnswer *>(an);  // down cast
        string a = q->get();
        string temp = getText();
        temp += "\nanswer:";
        temp += a;
        return temp;
    }
    return getText();   
}

TextualAnswer::operator bool() const
{
    if (text.empty())
    {
        return false;
    }
    else
    return true;
}

void TextualAnswer::clear()
{
    text.clear();
}

void TextualAnswer::set(string a)
{
    text = a;
}

string TextualAnswer::get() const
{
    return text;
}
