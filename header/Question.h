#include <string>
#include<array>
#include<vector>
#include "answer.h"
#ifndef QUESTION_H
#define QUESTION_H

using Id = std::string;
using Score = float;
using Text = std::string;
class AnswerSheet;
std::string ques_id_maker();
std::string exam_id_maker();
int random(int);


class Question
{
    public:
        virtual Question& operator=(const Question&);
        using Id = ::Id;
        using Text = std::string;
        using Score = float;
        virtual void copy(Question *) const;
        virtual void clone(Question *) const;
        Id getId() const;
        virtual Text getText() const;
        Score getScore() const;
        void setText(Text);
        void setScore(Score);
        virtual void setAnswer(Answer *) = 0;
        virtual Answer *getAnswer() const = 0;
        void set_id(std::string);
        virtual bool hasAnswer() const = 0;
        virtual std::string toString(bool includeAnswer) const = 0;
        Score operator+(const Question &) const;
    protected: 
        Question(Text, Score);
        Answer * an;
    private: 
        Id id = ques_id_maker();
        Text text;
        Score score;
        
        friend Score operator+(Score, const Question &);
};

Question::Score operator+(Question::Score, const Question &);



#endif