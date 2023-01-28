#ifndef FILM_H
#define FILM_H

#include <iostream>
using namespace std;
#include <string>

class Film 
{
private:
    
    string Name;
    int Price;
    int Stock;
    string Released;
    string Director;
    bool Age_limit;
    
    
    

public:

    typedef struct 
    {
        string film_name;
        int film_stock;
    }Film_stocks;

    Film_stocks film_stocks[10];

    Film()
    {

        
    }

   Film(string name, int price, int stock, string released, string director, bool age_limit)
    {
        Name = name;
        Price = price;
        Stock = stock;
        Released = released;
        Director = director;
        Age_limit = age_limit;

        
    }

   
    void add_film_stock(string name, int stock)
    {
        
        for (int i = 0; i < 10; i++)
        {
            if (film_stocks[i].film_name == "")
            {
                film_stocks[i].film_name = name;
                film_stocks[i+1].film_stock = stock;
                break;
            }
            
        }
        
    }
    string get_name()
    {
        return Name;
    }
    int get_price()
    {
        return Price;
    }
    int get_stock()
    {
        return Stock;
    }
    string get_released()
    {
        return Released;
    }
    string get_director()
    {
        return Director;
    }
    bool get_age_limit()
    {
        return Age_limit;
    }

    void set_name(string name)
    {
        Name = name;
    }
    void set_price(int price)
    {
        Price = price;
    }
    void set_stock(int stock)
    {
        Stock = stock;
    }
    void set_released(string released)
    {
        Released = released;
    }
    void set_director(string director)
    {
        Director = director;
    }
    void set_age_limit(bool age_limit)
    {
        Age_limit = age_limit;
    }


    void film_info()
    {
        cout << "Film Information " << endl;
        cout << "-----------------------" << endl;
        cout << "Film Name: " << Name << endl;
        cout << "Film Price: " << Price << endl;
        cout << "Film Stock: " << Stock << endl;
        cout << "Film Released: " << Released << endl;
        cout << "Film Director: " << Director << endl;
        cout << "Film Age Limit: " << Age_limit << endl;
    }

    




};
#endif