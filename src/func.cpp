#include <iostream>
#include <string>
#include <cstring>
#include "answersheet.h"
#include <random>
#include "Question.h"
#include<ctime>
using namespace std;


unsigned int random_n()
{
    default_random_engine eng(static_cast<unsigned int>(time(NULL)));
    uniform_int_distribution<unsigned int> Myrand(1, 100554);
    Myrand(eng);
    return Myrand(eng);
}
string ques_id_maker()
{
    char a[100];
    int count = 0;
    for (size_t i = 33; i < 126; i++)
    {
        a[count] = i;
        count++;
    }
    a[count] = '\0';
    unsigned int q = random_n();
    int q1 = q % 5 + 2;
    
    char temp[90];
    strcpy(temp , "question_");
    count = 9;
    for (size_t i = 0; i < 100; i += q1)
    {
       temp[count] = a[i];
       count++;
    }
    temp [count] = '\0';
    temp[90] = '\0';
    return temp;

}
string exam_id_maker()
{
    char a[100];
    int count = 0;
    for (size_t i = 33; i < 126; i++)
    {
        a[count] = i;
        count++;
    }
    //a[count] = '\0';
    //cout << a;
    unsigned int q = random_n();
    int q1 = q % 5;
    //q1 -= 1;
    char temp[90];
    strcpy(temp , "exam_");
    count = 5;
    for (size_t i = 0; i < 90; i += q1)
    {
       temp[count] = a[i];
       count++;
    }
    temp [count] = '\0';
    temp[90] = '\0';
    cout <<endl;
    //cout<< endl << "temp: " << temp;
    //string s
    return temp;
}

