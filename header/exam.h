#include "Question.h"
#include "answersheet.h"
#include <vector>
#include<string>
#include <iostream>
using Id = std::string;
#ifndef EXAM_H
#define EXAM_H
class Exam
{
    public:
        Exam(); 
        using Id = ::Id;
        Exam(const Exam &);
        Id getId() const;
        void addQuestion(Question *);
        void removeQuestion(const Question::Id &);
        Question *editQuestion(const Question::Id &);
        const Question *getQuestion(const Question::Id &) const;
        const std::vector<Question *> &getQuestionList() const;
        AnswerSheet startTaking() const;
        void commitAnswerSheet(AnswerSheet);
        constexpr Question::Score getMaxScore() const;
        Question *operator[](const Question::Id &) const;
        void check_id_question(Id) const;
        const Exam &operator=(const Exam &);

    private:
        std::string id;
        std::vector<AnswerSheet> answerSheet;
};
using Id = std::string;

#endif