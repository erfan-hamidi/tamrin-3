#include "Question.h"
#include <vector>
#ifndef ANSWERSHEET_H
#define ANSWERSHEET_H


class AnswerSheet
{
public:
    void setanswer(Answer * ,int) const;
    AnswerSheet() {}
    AnswerSheet(const AnswerSheet &);
    void addQuestion(Question *);
    void removeQuestion(const Question::Id &);
    Question *editQuestion(const Question::Id &);
    const std::vector<Question *> &getQuestionList() const;
    Question::Score getTotalScore() const;
    void check_id_question(Id) const; // checking id

private:
    std::vector<Question *> questions;
};
#endif