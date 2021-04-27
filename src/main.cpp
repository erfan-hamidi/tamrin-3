#include <iostream>
#include <cstring>
#include <string>
#include "Question.h"
#include "course.h"
#include "answersheet.h"
#include <typeinfo>
#include <vector>
#include <ctime>
#include<cstdlib>
#include <unistd.h>
#include "BlankFillingQuestion.h"
#include "FourChoicesQuestion.h"
#include "TextualQuestion.h"
using namespace std;



void set( Exam & e)  //set exam
{
        //cout << e.getId() << endl;

   FourChoicesAnswer * a1 = new FourChoicesAnswer();
   FourChoicesQuestion *q1 = new FourChoicesQuestion("aya dar ersbari mishavad az func haye pedar atefade kard",0.5);
    //q1.setText();
    q1->setOption(1,"bale");
    q1->setOption(2,"khare");
    q1->setOption(3,"darsort ersbari public");
    q1->setOption(4,"darsort ersbari private");
    //cout << "id: " << q1.getId() << endl;
    //q1.setScore();
    a1->set("1");
    q1->setAnswer(a1);
    //cout << e.getId() << endl;
    e.addQuestion(q1);
    
    //cout << e.getId() << endl;
    BlankFillingQuestion *q2 = new BlankFillingQuestion("{} (ostream &,class &)", 0.25);
   // q2->setText("{} (ostream &,class &)","{}");
    BlankFillingAnswer *a2 = new BlankFillingAnswer();
    a2->set("ostream & operator<<");
    q2->setAnswer(a1);
    //q2.setScore(0.25);
    e.addQuestion(q2);
    TextualQuestion *q3 = new TextualQuestion("piyade sazi ye copy constractor",2.0);
    //q3.setText;
    //q3.setScore(2.0);
    TextualAnswer *a3 = new TextualAnswer();
    //cout << e.getId() << endl;
    a3->set("class(const class &){}");
    q3->setAnswer(a3);
    e.addQuestion(q3);
}

int main()
{
    cout << " welcome my program\n this program is very simple\n We have one exam for start Enter 1 \n Exit 0";
    int a;
    cin >> a;
    if(a != 1)
    {
        return 0;
    }
    Course sdw("ap");
    Exam temp;
    set(temp);
    AnswerSheet a1;
    a1 = temp.startTaking();
    AnswerSheet t(a1);
    FourChoicesAnswer a5();
    Answer * ans;
    string str;
    const vector<Question *> he = t.getQuestionList();
    for (size_t i = 0; i < he.size(); i++)
    {
        ans =he.at(i)->getAnswer();
        cout << he.at(i)->toString(false) << "\n---->";
        cin >> str;
        ans->set(str);
        t.setanswer(ans, i + 1);
        cout << endl << endl;
    }
    
    for (size_t i = 0; i < he.size(); i++)
    {
        delete he.at(i);
    }
    
    return 0;
}

//alsactl restore
//wget -qO- https://get.speedify.com | bash -
//wget -qO- https://get.speedify.com | sudo -E bash -
//sudo service speedify start
