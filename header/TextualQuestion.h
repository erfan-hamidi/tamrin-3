#include "answersheet.h"
#include "Question.h"
#include "answer.h"

#ifndef TEXTUALQUESTION_H
#define TEXTUALQUESTION_H

class TextualQuestion: public Question
{
    public:
        TextualQuestion(Text a, Score s):Question(a,s) {} // constructor
        virtual void setAnswer(Answer *);
        virtual Answer *getAnswer() const;
        virtual bool hasAnswer() const;
        virtual std::string toString(bool includeAnswer) const;
    
};

class TextualAnswer: public Answer
{
    public:
        void set(std::string);
        std::string get() const;
        virtual void clear();
        virtual operator bool() const;
    private:
    std::string text;
        
};
#endif