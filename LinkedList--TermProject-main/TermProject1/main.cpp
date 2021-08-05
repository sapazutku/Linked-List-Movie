#include <iostream>
#include <cstdlib>
#include <fstream>
#include "List.h"
using namespace std;


int main() {
   

    List Movies;
    string nameOfMovie;
    int yearOfMovie;
    double rateOfMovie;
    int option;
    int option2;

        // menu

        cout << "----------------Movie List----------------" << endl;
        Movies.printMenu();

        cin >> option;
    while (option !=6){
        if (option == 1){
            cout << "Enter the name : ";
            cin >> nameOfMovie;
            cout <<"\nEnter the year of movie : ";
            cin >> yearOfMovie;
            cout << "\nEnter the rate of movie : ";
            cin >> rateOfMovie;

            Movies.add(nameOfMovie,rateOfMovie,yearOfMovie);
            cout <<  "\n" <<nameOfMovie <<" added" << endl;
            //
            Movies.printMenu();
            cin >> option;
        }
        if (option == 2){
            Movies.print();
            cout << "Which movie do you want to update : " << endl;
            cin >> nameOfMovie;
            cout << "\nEnter the rate of movie : ";
            cin >> rateOfMovie;
            Movies.update(nameOfMovie,rateOfMovie);
            cout << "\n" << nameOfMovie << " updated" << endl;
            Movies.printMenu();
            cin >> option;
        }
        if (option == 3){
            Movies.print();
            cout << "Which movie do you want to remove " << endl;
            cin >> nameOfMovie;
            Movies.remove(nameOfMovie);
            cout << nameOfMovie <<"deleted" << endl;
            Movies.printMenu();
            cin >> option;
        }
        if (option == 4){
            cout << "(1)-Sorted by year" <<  //look again
                 "\n(2)-Sorted by rate" <<
                 "\n(3)-Sorted by name" << endl;
            cin >> option2;
            if (option2 == 1){
                Movies.printByYear();
                Movies.print();
                //Movies.printMenu();
            }
            else if (option2 == 2){
                Movies.printByRate();
                Movies.print();
                //Movies.printMenu();
            }
            else if (option2 == 3){
                Movies.printByName();
                Movies.print();
                //Movies.printMenu();
            }
            else{
                cout << "Try again: "<< endl;
                cin >> option2;

            }
            Movies.printMenu();
            cin >> option;
        }
        if (option == 5){
            cout << "(1)-Save to file by name" <<
            "\n(2)-Save to file by rate" <<
            "\n(3)-Save to file by year " << endl;
            cin >> option2;
            if (option2 == 1){
                Movies.loadFile("Test.txt");
                Movies.saveToFileByName("Test.txt");
                cout << "Saved to file" << endl;
                Movies.printMenu();
                cin >> option;
            }
            else if (option2 == 2){
                Movies.loadFile("Test.txt");
                Movies.saveToFileByRate("Test.txt");
                cout << "Saved to file" << endl;
                Movies.printMenu();
                cin >> option;
            }
            else if (option2 == 3){
                Movies.loadFile("Test.txt");
                Movies.saveToFileByYear("Test.txt");
                cout << "Saved to file" << endl;
                Movies.printMenu();
                cin >> option;
            }
            else{
                cout << "Try again: "<< endl;
                break;
            }

        }

    }


}

