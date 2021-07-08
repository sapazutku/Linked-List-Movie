//
// Created by utkus on 5/12/2021.
//
using namespace std;
#ifndef TERMPROJECT1_LIST_H
#define TERMPROJECT1_LIST_H



class List{

private:

typedef struct node{
    int year;
    double rate;
    string name;
    node *next;
}*nodePtr;   // nodePtr = node*


nodePtr head;
nodePtr curr;
nodePtr temp;

// functions
public:
    fstream myFile;

    List();

    void add(string name, double rate, int year);  //addNode

    bool remove(string name); //deleteNode

    void update(string name, double rate);

    void printByYear();

    void print();

    void printByName();

    void printByRate();

    void loadFile(string filename);

    void saveToFileByYear(string filename);

    void saveToFileByName(string filename);

    void saveToFileByRate(string filename);

    void printMenu();


};
#endif //TERMPROJECT1_LIST_H
