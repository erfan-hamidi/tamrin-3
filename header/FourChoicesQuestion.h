#include "Question.h"
#include "answer.h"


#ifndef FOURCHOICESQUESTION_H
#define FOURCHOICESQUESTION_H

class FourChoicesQuestion: public Question{
    public:
        FourChoicesQuestion(Text a, Score s):Question(a,s) {} //constructor
        virtual FourChoicesQuestion & operator=(const FourChoicesQuestion &);
        virtual void copy(Question *) const;
        virtual void clone(Question *) const;
        virtual void setAnswer(Answer *);
        virtual Answer *getAnswer() const;
        virtual bool hasAnswer() const;
        virtual std::string toString(bool includeAnswer) const;
        using OptionText = std::string;
        using Options = std::array<OptionText, 4>;
        const Options &getOptions() const;
        void setOption(size_t, OptionText);
    private:
        Options options;
};
class FourChoicesAnswer: public Answer{
    public:
        FourChoicesAnswer() {}
        void set(std::string);
        std::string get() const;
        bool operator =(const FourChoicesAnswer &) const;
        virtual void clear();
        virtual operator bool() const;
        bool operator ==(const FourChoicesAnswer &) const;
    private:
    std::string an;
};


#endif