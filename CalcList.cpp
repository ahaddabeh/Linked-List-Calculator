#include "CalcListInterface.hpp"
#include "CalcList.hpp"
#include "catch.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;       /*I'm using namespace std because i find it very annoying to type "std::" in front of everything.*/


/*Alaa Haddabeh
USF ID#: 97523269*/



CalcList::CalcList() { 
    header = new CalcNode;
    trailer = new CalcNode;
    header->next = trailer;
    trailer->previous = header;
}
CalcList::~CalcList() {
    while (!empty()){
        removeLastOperation();
    }
    delete header; 
    delete trailer;
    
}
bool CalcList::empty() const { /*I got this from the lecture slides*/
    return (header->next == trailer);
}

void CalcList::addFront(const Elem& e){
    add(trailer, e); 
}
void CalcList::remove(CalcNode* v){ /*I got this remove function from the lecture slides. I will be implementing this into my removeLastOperation function.*/
    CalcNode* u = v->previous;
    CalcNode* w = v->next;
    u->next = w; w->previous = u; delete v;
}
void CalcList::removeLastOperation(){
   
   if(empty()){                     /*Here, I am checking to see if the list is empty. If it is, there's obviously no operation to remove so we just throw the error*/
       throw "Error";
   } 
   remove(trailer->previous);       /*If it's not empty, then we will remove the operation using the remove function*/
     
}
void CalcList::add(CalcNode* v, const Elem& e){ /*this will add the new node to the end of the list. I will be using this when creating a  new node in the newOperation function*/
    CalcNode* u = new CalcNode; 
    u->elem = e;
    u->next = v;
    u->previous = v->previous;
    v->previous->next = v->previous;
    v->previous = u;
    
}




void CalcList::newOperation(const FUNCTIONS func,const double operand){
                                        
 
    if(func==ADDITION){
        //addFront();
       addFront(trailer->elem);
        trailer->previous->oldNumber=trailer->previous->previous->result;       /*I will be using the oldNumber to store the value of the result in the operation done before this node was created.*/
        trailer->previous->newNumber=operand;
        trailer->previous->result=(trailer->previous->oldNumber)+(trailer->previous->newNumber);
        trailer->previous->step=(trailer->previous->previous->step)+1;  /*This will be to increment the step that will need to be shown in the toString function. I am using the step from the node before and incrementing it by 1.*/
        trailer->previous->operation='+';           /*This is mainly just to be used in the toString function.*/
        
    }
    else if(func==SUBTRACTION){
        //addFront();
        //add(CalcNode* trailer, e);
        addFront(trailer->elem);
        trailer->previous->oldNumber=trailer->previous->previous->result;
        trailer->previous->newNumber=operand;
        trailer->previous->result=(trailer->previous->oldNumber)-(trailer->previous->newNumber);
        trailer->previous->step=(trailer->previous->previous->step)+1;
        trailer->previous->operation='-';
        
    }
    else if(func==MULTIPLICATION){
        //addFront();
        //add(CalcNode* trailer, e);
        addFront(trailer->elem);
        trailer->previous->oldNumber=trailer->previous->previous->result;
        trailer->previous->newNumber=operand;
        trailer->previous->result=(trailer->previous->oldNumber)*(trailer->previous->newNumber);
        trailer->previous->step=(trailer->previous->previous->step)+1;
        trailer->previous->operation='*';
        
    }
    else if(func==DIVISION){            
        if(operand==0){              /*Over here, I'll be throwing the operand in case the exception of dividing by 0 comes up.*/
            throw operand;
        }
        else{
            //addFront();
            //add(CalcNode* trailer, e);
            addFront(trailer->elem);
            trailer->previous->oldNumber=trailer->previous->previous->result;   /*I will be using the oldNumber to store the value of the result in the operation done before this node was created.*/
            trailer->previous->newNumber=operand;
            trailer->previous->result=(trailer->previous->oldNumber)/(trailer->previous->newNumber);
            trailer->previous->step=(trailer->previous->previous->step)+1;
            trailer->previous->operation='/';
    }
    }


}
string CalcList::toString(unsigned short precision) const {
    CalcNode* temporary=trailer->previous;
    
    stringstream Stream;

    string performedCalculations;   /*This string declaration will be used to take in the information that is put into the string stream object.*/ 
    
   
    
    while(temporary != header->next){   /*This while loop will iterate through the list starting from the last operation working its way up back to first node*/
        
        
        performedCalculations = performedCalculations + to_string(temporary->step); /*Putting the step of the current node*/
        
        performedCalculations = performedCalculations + ": ";
        
        Stream << fixed << showpoint << setprecision(precision) << temporary->oldNumber;    /*Now using the result from the previous operation that was done before th current operation being looked at.*/
        
        performedCalculations = performedCalculations + Stream.str();  /*By doing this, I am just appending whatever was put into the string stream object into the performedCalculations string*/
        
        Stream.str("");         
        
        performedCalculations = performedCalculations + temporary->operation; /*This is where i will be putting that operation character from when i first created the node*/
        
        Stream << fixed << showpoint << setprecision(precision) << temporary->newNumber;    /*Now I'm showing the operand that was put into the newNumber element when this node was first created*/
        
        performedCalculations = performedCalculations + Stream.str();
        
        Stream.str("");
        
        performedCalculations = performedCalculations + "=";
        
        Stream << fixed << showpoint << setprecision(precision) << temporary->result;   /*Finally the result that was achieved from the operation*/
        
        performedCalculations = performedCalculations + Stream.str();
        
        Stream.str("");
        
        performedCalculations = performedCalculations + "\n";
        
        temporary = temporary->previous;
        }
   
    
    
    return performedCalculations;       /*Then we just return our finalized string*/
}
double CalcList::total() const{
    return trailer->previous->result;   /*Using the result element that was achieved at the most recent operation will give me total.*/ 
}
















































































 




