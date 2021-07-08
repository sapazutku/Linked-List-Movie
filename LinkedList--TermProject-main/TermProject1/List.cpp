//
// Created by utkus on 5/12/2021.
//


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "List.h"

using namespace std;



List::List() {

    head = NULL;
    curr = NULL;
    temp = NULL;
}

void List::add(std::string name, double rate, int year) {
    nodePtr n = new node;
    n->next = NULL;

    n->name = name;
    n->rate = rate;
    n->year = year;

    if (head != NULL) {
        curr = head;
        while (curr->next != NULL) {          //nodelara arasından gezinme
            curr = curr->next;
        }
        curr->next = n;

    } else {               //önceden bir node yoksa oluşturulan nodeu baş olarak işaretle
        head = n;
    }


}

bool List::remove(string name) {
    bool isDelete = false;
    nodePtr delPtr = NULL;
    temp = head;
    curr = head;

    while (curr != NULL && curr->name != name) {
        temp = curr;
        curr = curr->next;

    }

    if (curr == NULL) {

        isDelete = false;
        cout << name << "was not in the list\n";
        delete delPtr;

    } else {
        delPtr = curr;
        curr = curr->next;
        temp->next = curr;
        if (delPtr == head) {
            head = head->next;
            temp = NULL;
        }
        isDelete = true;
        cout << "The value" << name << "was deleted\n";
        delete delPtr;
    }
    return isDelete;
}

void List::print() {
    curr = head;
    while (curr != NULL) {
        cout << curr->name << "  " << curr->year << "  " << curr->rate << endl;
        curr = curr->next;
    }
}

void List::printByYear() {

    curr = head;
    while (curr != NULL && curr->next != NULL) {
        if ((curr->next->year) < (curr->year)) {            // 1999     2000     2001    2002
            swap(curr->name, curr->next->name);
            swap(curr->year, curr->next->year);
            swap(curr->rate, curr->next->rate);
            printByYear();          //
        }else{
            curr = curr->next;
        }

    }

}

void List::update(string name, double rate) {
    curr = head;
    while(curr != NULL){
        if (curr->name == name){
            curr->rate = rate;
        }
        curr = curr->next;
    }
}

void List::printByRate() {
    curr = head;
    while (curr != NULL && curr->next != NULL) {
        if ((curr->next->rate) > (curr->rate)) {         // 3   5   1    10
            curr = curr->next;
        }
        else{
            swap(curr->name,curr->next->name);
            swap(curr->rate, curr->next->rate);
            swap(curr->year,curr->next->year);
            printByRate();      //
        }

   }
    //print();
}


//curr->name.compare(curr->next->name)== true
void List::printByName() {
   curr = head;

    while (curr != NULL&& curr->next != NULL){
        if ((curr->name.compare(curr->next->name)) == true ){          //   b    a     d    c
               //
            swap(curr->name, curr->next->name);
            swap(curr->year, curr->next->year);
            swap(curr->rate, curr->next->rate);
            printByName();
        }else {
            curr = curr->next;
        }
    }

}






    /*curr = head;
    while (curr != NULL&& curr->next != NULL) {
        if (curr->name > curr->next->name ){            //b   a    c
            swap(curr->name, curr->next->name);
            swap(curr->year, curr->next->year);
            swap(curr->rate, curr->next->rate);
        }else
        curr = curr->next;
    }
    print();*/


void List::loadFile(string filename) {
    myFile.open(filename,ios::app);
    if(myFile.is_open()){
        cout << "File: " << filename << "Opened " << endl;
    } else{
        cout << filename <<": is not opened " << endl;
    }
}

void List::saveToFileByYear(string filename) {
    //sort by year
    curr = head;
    while (curr != NULL && curr->next != NULL) {
        if ((curr->next->year) > (curr->year)) {
            swap(curr->name, curr->next->name);
            swap(curr->year, curr->next->year);
            swap(curr->rate, curr->next->rate);
            printByYear();    //
        }
        curr = curr->next;
    }
    curr = head;    // dosyaya yazma ve kapatma
    while (curr != NULL) {
        myFile << curr->name << " " << curr->year << " " << curr->rate << endl;
        curr = curr->next;
    }
    myFile.close();
}

void List::saveToFileByRate(string filename) {
    curr = head;
    while (curr != NULL && curr->next != NULL) {
        if ((curr->next->rate) > (curr->rate)) {
            swap(curr->name, curr->next->name);
            swap(curr->year, curr->next->year);
            swap(curr->rate, curr->next->rate);
            printByRate();    //
        }
        curr = curr->next;
    }

    curr = head;

    while (curr != NULL) {
        myFile << curr->name << " " << curr->year << " " << curr->rate << endl;
        curr = curr->next;
    }
    myFile.close();
    }

    void List::printMenu() {
        cout <<
             "\n(1)-Add a movie to the list." <<
             "\n(2)-Update a movie" <<
             "\n(3)-Remove a movie from list" <<
             "\n(4)-Print Methods" <<
             "\n(5)-Save methods to file" <<
             "\n(6)-Exit the program" << endl;
}

void List::saveToFileByName(string filename) {
    curr = head;

    while (curr != NULL&& curr->next != NULL){
        if ((curr->name.compare(curr->next->name)) == true ){          //   b    a     d    c
            //
            swap(curr->name, curr->next->name);
            swap(curr->year, curr->next->year);
            swap(curr->rate, curr->next->rate);
            printByName();
        }else {
            curr = curr->next;
        }
    }
    curr = head;
    while (curr != NULL) {
        myFile << curr->name << " " << curr->year << " " << curr->rate << endl;
        curr = curr->next;
    }
    myFile.close();

}














