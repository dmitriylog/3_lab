// ������� ������� ���������� � ��������

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

    // �������
    double getPrice() const{
        return price;
    }

    double getRating() const{
        return rating;
    }

    // �������
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
        cout << "�����: " << name << "\n����: " << price << " ���\n �������: " << rating << endl;
    }

};

class Category{
private:
    string name;
    vector <Goods> goods;
public:
    Category(const string& catName):name(catName){}
    Category(const string& catName, const vector <Goods>& initGoods): name(catName),goods(initGoods){}

    //�������
    string getName() const{
        return name;
    }

    const vector <Goods>& getGoods() const {
        return goods;
    }

    // �������
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
        cout << "���������: " << name << endl;
        cout << "���������� �������: " << goods.size() << endl;
        cout << "������: " << endl;

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
    Busket() = default; // ����������� �� ���������
    Busket(const vector <Goods>& init_products):bought_products(init_products){} // ����������� ��������� ���������

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
        cout << "������� �������!" << endl;
    }

    void display_busket() const {
        cout << "������� �������" << endl;
        if (bought_products.empty()){
            cout << "������� �����!" << endl;
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
