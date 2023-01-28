#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>
#include "Film.h"
#include "Customer.h"
using namespace std;

class Store: public Film , public Customer
{



int store_balance = 0;





public:

    Customer customer;

    
    string rented_films[5];
    string film_list[10];
    int total_film_number = 0;
    Store()
    {
        
    }

    void store_info()
    {
        cout << "Store Information" << endl;
        cout << "-----------------------" << endl;
        cout << "Store Balance: " << get_store_balance() << endl;
        cout << "Total Film Number: " << total_film_number << endl;
    }

    void add_film(Film film)
{
    if (total_film_number > 10)
    {
        cout << "System film capacity is full" << endl;
    }
    
    else
    {

        
        for (int i = 0; i < 10; i++)
        {
            if (film_list[i] == film.get_name())
            {
                cout << "This film is already in the system" << endl;
                film.set_stock(film.get_stock() + 1);
                break;
            }

            else if (film_list[i] == "")
            {
                film_list[i] = film.get_name();
                total_film_number++;  
                break;      
            }
            


            
        }
        film.add_film_stock(film.get_name(), film.get_stock());
        
        
    }

}

    void refund_film(Film film, Customer customer)
    {
        for (int i = 0; i < 5; i++)
        {
            if (rented_films[i] == film.get_name())
            {
                rented_films[i] = "";
                customer.set_balance(customer.get_balance() - film.get_price());
                set_store_balance(get_store_balance() - film.get_price());
                film.set_stock(film.get_stock() + 1);
                cout << "Film returned" << endl;
                break;
            }
            
        }
        
    }
    int get_store_balance()
    {
        return store_balance;
    }

    void delete_film(Film film)
    {
        for (int i = 0; i < 10; i++)
        {
            if (film_list[i] == film.get_name())
            {
                film_list[i] = "";
                total_film_number--;
                break;
            }
            
        }
        
    }

    void film_list_info()
    {
        cout << "Film Lists" << endl;
        cout << "-----------------------" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (film_list[i] != "")
            {
                cout << film_list[i] << endl;
            }
            
        }
        
    }   

    void film_update(Film film, string name, int price, int stock, string released, string director, bool age_limit)
    {
        for (int i = 0; i < 10; i++)
        {
            if (film_list[i] == film.get_name())
            {
                film_list[i] = name;
                break;
            }
            
        }
        set_name(name);
        set_price(price);
        set_stock(stock);
        set_released(released);
        set_director(director);
        set_age_limit(age_limit);
    }

    // Customer kiralama işlemleri yapılacak
    // void rent_film(Film film, Customer customer

    void rent_film(Film &film, Customer &customer)
    {
        

        if (customer.get_balance() < film.get_price())
        {
            cout << "You don't have enough money" << endl;
        }
        else if (film.get_stock() == 0)
        {
            cout << "There is no film in stock" << endl;
        }
        else if (customer.get_right_film() == 0)
        {
            cout << "You can't rent film" << endl;
        }
        else
        {
            for (int i = 0; i < 5; i++)
            {
                if (rented_films[i] == "")
                {
                    rented_films[i] = film.get_name();
                    break;
                }
                else if (rented_films[i] != "")
                {
                    cout << "You can't rent more than 5 films" << endl;
                    break;
                }
                
            }
            film.set_stock(film.get_stock() - 1);
            customer.set_balance(customer.get_balance() - film.get_price());
            customer.set_right_film(customer.get_right_film() - 1);
            set_store_balance(get_store_balance() + film.get_price());
            
        }
        
    }
    void set_store_balance(int balance)
    {
        store_balance = balance;
    }

    void show_rented_films()
    {
        cout << "Rented Films" << endl;
        cout << "-----------------------" << endl;
        for (int i = 0; i < 5; i++)
        {
            if (rented_films[i] != "")
            {
                cout << rented_films[i] << endl;
            }
            
        }
        
    }

    
    void print_film_stock()
    {
        cout << "Film Stocks"<< endl;
        cout << "-----------------------" << endl;

        for (int i = 0; i < 10; i++)
        {
            if (film_stocks[i].film_name != "")
            {
                cout << film_stocks[i].film_name << " " << film_stocks[i].film_stock << endl;
            }
            
        }
        
    }

};
#endif