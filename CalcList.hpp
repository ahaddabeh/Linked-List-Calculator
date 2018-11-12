#ifndef CALCLIST_H
#define CALCLIST_H
#include "CalcListInterface.hpp"
#include <string>

/*Alaa Haddabeh
USF ID#: 97523269*/

typedef std::string Elem;           /*I got a majority of the list interface and the node interface from the lecture slides.*/
class CalcNode{
    private:
        Elem elem;
        char operation;
        int step=0;                 /*I am creating a variable to count the number of steps taken to use in the toString function. I have to set it to 0*/
        double newNumber;           /*so that i can increment it every time a new node is created and take the previous step and increment it by 1 in the new node*/
        double oldNumber;
        double result = 0.0;
        CalcNode* next;
        CalcNode* previous;
        friend class CalcList;
};
class CalcList : public CalcListInterface {
    public:
        CalcList();
        ~CalcList();
        bool empty() const;
        double total() const;
        void newOperation(const FUNCTIONS func,const double operand);
        void removeLastOperation();
        std::string toString(unsigned short precision) const;
        const Elem& back() const;
        const Elem& front() const;
        void removeFront();
        void addFront(const Elem& e);
        int i = 1;
    private:
        CalcNode* header;
        CalcNode* trailer;
    
    
protected:
    void add(CalcNode* v,const Elem& e);
    void remove(CalcNode *v);
};

#endif





































/*#ifndef CALCLIST_H
#define CALCLIST_H
#include "CalcListInterface.hpp"
//#include "catch.hpp"
#include <string>


class CalcList;
typedef std::string Elem;
class CalcNode{
    private:
    Elem elem;
    double num;
    double data=0;
    int step=0;
    char operation;
    CalcNode* next;
    friend class CalcList;
    };

class CalcList : public CalcListInterface{
    public:
        CalcList();
        ~CalcList();
        bool empty();
        //void insertFront(const E& e);
        //const E& front() const;
        //void insertAfter(int afterElem, int element);
        
        double total() const;
        void newOperation(const FUNCTIONS func, const double operand);
        void removeLastOperation(); 
        std::string toString(unsigned short precision) const;
        void addition(double number);
        void subtraction(double number);
        void multiplication(double number);
        void division(double number); 
    private:
        CalcNode* head;
};

#endif
double total() const;
void newOperation(const FUNCTIONS func, const double operand);
void removeLastOperation(); 
std::string toString(unsigned short precision) const;*/