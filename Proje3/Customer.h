#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

class Customer : public Person
{

private:
    int Right_Film = 5;
    int Balance;

public:
    int Id;
    Person person;
    string Customer_List[10];
    string previous_film_list[10];
    string right_film_list[10];

    Customer()
    {
    }
    Customer(int id, Person person, int balance)
    {
        Id = id;
        person = person;
        Balance = balance;

        if (person.get_age() < 18)
        {
            cout << "You are under 18. Your balance limited" << endl;
            set_balance(get_balance() * 0.5);
        }

        add_customer(id, person);
    }

    void customer_info(Person person)
    {
        cout << "Customer Information" << endl;
        cout << "-----------------------" << endl;
        cout << "Id: " << Id << endl;
        cout << "Name and Surname: " << person.get_name_surname() << endl;
        cout << "Age: " << person.get_age() << endl;
        cout << "Phone Number: " << person.get_phone_number() << endl;
        cout << "Mail: " << person.get_mail() << endl;
        cout << "Balance: " << get_balance() << endl;
        cout << "Right Film: " << get_right_film() << endl;
    }

    void add_customer(int id, Person person)
    {

        for (int i = 0; i < 10; i++)
        {
            if (Customer_List[i] == "")
            {
                Customer_List[i] = to_string(id) + " " + person.get_name_surname();
                cout << "Customer added to the system" << endl;
                break;
            }
            else if (Customer_List[i] != "" && i == 9)
            {
                cout << "System customer capacity is full" << endl;
                break;
            }

            else if (Customer_List[i] != "")
            {
                continue;
            }
        }
    }

    void delete_customer(int id, Person person)
    {
        for (int i = 0; i < 10; i++)
        {
            if (Customer_List[i] == to_string(id) + " " + person.get_name_surname())
            {
                Customer_List[i] = "";
                cout << "Customer deleted from the system" << endl;
            }
            else
            {
                cout << "This customer is not in the system" << endl;
                break;
            }
        }
    }

    void print_customer_list()
    {
        cout << "Customer List" << endl;
        cout << "-----------------------" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (Customer_List[i] != "")
            {
                cout << Customer_List[i] << endl;
            }
        }
    }

    int get_balance()
    {
        return Balance;
    }
    void set_balance(int balance)
    {
        Balance = balance;
    }
    void set_balance(int &balance)
    {
        Balance = balance;
    }
    int get_right_film()
    {
        return Right_Film;
    }
    void set_right_film(int right_film)
    {
        Right_Film = right_film;
    }
};
#endif