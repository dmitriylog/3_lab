// корзина товаров покупателя в магазине

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

    // геттеры
    double getPrice() const{
        return price;
    }

    double getRating() const{
        return rating;
    }

    // сеттеры
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

    //геттеры
    string getName() const{
        return name;
    }

    const vector <Goods>& getGoods() const {
        return goods;
    }

    // сеттеры
    void setName(const string& newName){
        name = newName;
    }

    void addGoods(const Goods& product){
        goods.push_back(product);
    }

    void removeGoods(const string& productName){
        for (auto it = goods.begin();it != goods.end(); ++it){
            if (it->getName() == productName){
                goods.erase(it);
                break;
            }
        }
    }

    void diplayInfo() const {
        cout << "Категория: " << name << endl;
        cout << "Количество товаров: " << goods.size() << endl;
        cout << "Товары: " << endl;

        for (size_t i = 0; i < goods.size(); ++i){
            cout << " " << (i+1) << ". ";
            goods[i].displayInfo();
        }
    }

};

class Busket{
private:
    vector <Goods> bought_products;

public:
    Busket() = default; // конструктор по умолчанию
    Busket(const vector <Goods>& init_products):bought_products(init_products){} // конструктор купленных продуктов

    const vector <Goods>& get_bought_prod() const {
        return bought_products;
    }

    void addProduct(const Goods& product){
        bought_products.push_back(product);
    }

    bool remove_product(const string& prod_name){
        auto it = find_if(bought_products.begin(),bought_products.end(),[prod_name](const Goods& p){return p.getName() == prod_name;});
        if (it != bought_products.end()){
            bought_products.erase(it);
            return true;
        }
        return false;
    }

    void clear_busket(){
        bought_products.clear();
        cout << "Корзина очищена!" << endl;
    }

    void display_busket() const {
        cout << "Корзина покупок" << endl;
        if (bought_products.empty()){
            cout << "Корзина пуста!" << endl;
            return;
        }
        for (size_t i = 0; i<bought_products.size();i++){
            cout << (i+1) << ". ";
            bought_products[i].displayInfo();
        }
    }

};

int main()
{

};
