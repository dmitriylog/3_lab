// корзина товаров покупателя в магазине

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Goods{
private:
    string name;
    double price;
    double rating;
public:
    Goods(const string& Prname,double Prprice,double Prrating): name(Prname),price(Prprice),rating(Prrating){}

    string getName() const{
        return name;
    }

    double getPrice() const{
        return price;
    }

    double getRating() const{
        return rating;
    }

    void setName(const string& newName){
        name = newName;
    }

    void setPrice(double newPrice){
        price = newPrice;
    }

    void setRating(double newRating){
        rating = newRating;
    }

    void displayInfo() const {
        cout << "Товар: " << name << "\nЦена: " << price << " руб\n Рейтинг: " << rating << endl;
    }

};

class Category{
private:
    string name;
    vector <Goods> goods;
public:
    Category(const string& catName):name(catName){}
    Category(const string& catName, const vector <Goods>& initGoods): name(catName),goods(initGoods){}

};

int main()
{

}
