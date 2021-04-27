#include <string>
#include <vector>
#include"exam.h"


#ifndef COURSE_H
#define COURSE_H

using Id = std::string;
class Course
{
    public:
        using Name = std::string;
        Course(Name);
        Course(const Course &) = delete;
        Name getName() const;
        void setName(Name);
        void addExam(Exam);
        void removeExam(const Exam::Id &);
        Exam cloneExam(const Exam::Id &) const;
        Exam &editExam(const Exam::Id &);
        const Exam &getExam(const Exam::Id &) const;
        const std::vector<Exam> &getExamList() const;

    private:
        int searchExam(const Exam::Id &) const;
        Name name;
        std::vector<Exam> exams;
        int cexam = 0;
};

#endif