#ifndef ANSWER_H
#define ANSWER_H

class Answer
{
public:
    virtual void clear() = 0;
    virtual operator bool() const = 0;
    virtual void set(std::string) = 0;
    virtual std::string get() const = 0;
};
#endif