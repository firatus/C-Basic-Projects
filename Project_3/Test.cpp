#include <iostream>
#include <string>

using namespace std;
#include "Film.h"
#include "Person.h"
#include "Customer.h"
#include "Store.h"
int main()
{
    Film film1("The Godfather", 20, 10, "1972", "Francis Ford Coppola", true);

    Film film2("The Shawshank Redemption", 15, 5, "1994", "Frank Darabont", false);

    Film film3("The Dark Knight", 25, 15, "2008", "Christopher Nolan", true);

    Film film4("The Godfather: Part II", 20, 10, "1974", "Francis Ford Coppola", true);

    Film film5("The Lord of the Rings: The Return of the King", 30, 20, "2003", "Peter Jackson", false);

    Film film6("The Good, the Bad and the Ugly", 15, 5, "1966", "Sergio Leone", true);

    Film film7("The Lord of the Rings: The Fellowship of the Ring", 30, 20, "2001", "Peter Jackson", false);

    Film film8("The Lord of the Rings: The Two Towers", 30, 20, "2002", "Peter Jackson", false);

    Film film9("Pulp Fiction", 15, 5, "1994", "Quentin Tarantino", true);

    Film film10("Schindler's List", 20, 10, "1993", "Steven Spielberg", false);

    Film film11("Inception", 25, 15, "2010", "Christopher Nolan", true);

    Person person1("John Doe", 20, 123456789, "john@gmail.com");

    Person person2("Jane Doe", 2, 987654321, "adaba@gmail.com");

    Person person3("John Smith", 30, 123456789, "ad@gmail.com");

    Person person4("John Smith", 35, 987654321, "sad@gmail.com");

    Person person5("John Doe", 40, 123456789, "sada@gmail.com");

    Person person6("Jane Doe", 5, 987654321, "gabba@gmail.com");

    Person person7("John Smith", 50, 123456789, "dsad@gmail.com");

    Person person8("Jane Smith", 4, 987654321, "mara@gmail.com");

    Person person9("John Doe", 60, 123456789, "sata@gmail.com");

    Person person10("Jane Doe", 65, 987654321, "kuze@gmail.com");

    Person person11("Ali Smith", 70, 123456789, "ali@gmail.com");

    Person person12("Veli Smith", 75, 987654321, "s@gmail.com");

    Customer customer1(1, person1, 100);

    Customer customer2(2, person2, 200);

    Customer customer3(3, person3, 300);

    Customer customer4(4, person4, 400);

    Customer customer5(5, person5, 500);

    Customer customer6(6, person6, 600);

    Customer customer7(7, person7, 700);

    Customer customer8(8, person8, 800);

    Customer customer9(9, person9, 900);

    Customer customer10(10, person10, 1000);

    Customer customer11(11, person11, 1100);

    film1.film_info();
    film2.film_info();

    cout << "-----------------------" << endl;

    film1.add_film_stock(film1.get_name(), film1.get_stock());
    film2.add_film_stock(film2.get_name(), film2.get_stock());
    film3.add_film_stock(film3.get_name(), film3.get_stock());
    film4.add_film_stock(film4.get_name(), film4.get_stock());
    film5.add_film_stock(film5.get_name(), film5.get_stock());

    person1.person_info();
    person5.person_info();

    cout << "-----------------------" << endl;

    customer1.customer_info(person1);
    customer1.customer_info(person5);
    customer2.add_customer(customer2.Id, person2);
    customer3.add_customer(customer3.Id,person3);
    customer4.add_customer(customer4.Id, person4);
    customer5.add_customer(customer5.Id, person5);
    customer6.add_customer(customer6.Id, person6);
    customer5.delete_customer(customer4.Id,person4);

    customer1.print_customer_list();
    cout << "-----------------------" << endl;

    Store store1;
    Store store2;

    store1.add_film(film1);
    store1.add_film(film2);
    store1.add_film(film3);
    store1.add_film(film4);
    store1.add_film(film5);
    store1.add_film(film6);
    store1.add_film(film7);
    store1.add_film(film8);
    store1.add_film(film9);
    store1.add_film(film10);
    store1.add_film(film11);

    store1.print_film_stock();
    cout << "-----------------------" << endl;

    store1.film_list_info();

    store1.rent_film(film1, customer1);
    store1.rent_film(film2, customer1);
    store1.rent_film(film3, customer2);
    store1.rent_film(film4, customer2);
    store1.rent_film(film5, customer2);
    store1.rent_film(film6, customer3);
    store1.rent_film(film7, customer3);
    store1.rent_film(film8, customer3);

    store1.show_rented_films();
    cout << "-----------------------" << endl;

    customer1.customer_info(person1);

    store1.refund_film(film1, customer1);
    store1.refund_film(film2, customer1);
    store1.refund_film(film3, customer2);
    cout << "-----------------------" << endl;

    store1.delete_film(film1);
    store1.delete_film(film2);
    cout << "-----------------------" << endl;

    store1.film_list_info();
    cout << "-----------------------" << endl;

    store1.print_film_stock();

    store1.film_update(film4, "The Godfather: Part III", 50, 10, "1974", "Francis Ford Coppola", true);
    store1.film_list_info();
    cout << "-----------------------" << endl;

    store1.store_info();

    store2.rent_film(film1, customer4);
    customer4.customer_info(person4);
}