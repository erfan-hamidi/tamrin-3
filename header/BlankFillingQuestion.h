#include "Question.h"
#include "answer.h"
#include <string>


#ifndef BLANK_H
#define BLANK_H

using Id = std::string;
class BlankFillingQuestion: public Question
{
    public:
        BlankFillingQuestion(Text a, Score s):Question(a,s) {setText(a);} // constructor
        virtual BlankFillingQuestion & operator=(const BlankFillingQuestion &);
        virtual void copy(Question *) const;
        virtual void clone(Question *) const;
        virtual void setAnswer(Answer *);
        virtual Answer *getAnswer() const;
        virtual bool hasAnswer() const;
        virtual std::string toString(bool includeAnswer) const;
        using Placeholder = std::string;
        void setText(Question::Text, Placeholder);
        virtual Question::Text getText() const;
    private:
        using Question::setText;
        Placeholder placeholderStr;
};


class BlankFillingAnswer: public Answer{
    public:
        virtual void clear();
        virtual operator bool() const;
        void set(std::string);
        std::string get() const;
    private:
    Text ans;
};

#endif