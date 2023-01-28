#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;


class Person
{

    private:

    string Name_surname;
    int Age;
    int Phone_number;
    string Mail;
    
    
    public:
    Person(string name_surname, int age, int phone_number, string mail){
        Name_surname = name_surname;
        Age = age;
        Phone_number = phone_number;
        Mail = mail;
    }
    Person(){
        
    }

    void person_info(){
        cout << "Person Information" << endl;
        cout << "-----------------------" << endl;
        cout << "Name and Surname: " << Name_surname << endl;
        cout << "Age: " << Age << endl;
        cout << "Phone Number: " << Phone_number << endl;
        cout << "Mail: " << Mail << endl;
    }

    string get_name_surname(){
        return Name_surname;
    }
    int get_age(){
        return Age;
    }
    int get_phone_number(){
        return Phone_number;
    }
    string get_mail(){
        return Mail;
    }
    

    
    
};
#endif