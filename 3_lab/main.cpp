// ������� ������� ���������� � ��������

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ����� ������
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
        cout << "\n�����: " << name << "\n����: " << price << " $\n �������: " << rating << endl;
    }

};

// ����� ��������� �������
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
        cout << "\n���������: " << name << endl;
        cout << "\n���������� �������: " << goods.size() << endl;
        cout << "\n������: " << endl;

        for (size_t i = 0; i < goods.size(); ++i){
            cout << " " << (i+1) << ". ";
            goods[i].displayInfo();
        }
    }

};

// ����� �������
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

    //�������� ���� �� ������ ��������� ���������
    bool isEmpty() const {
        return bought_products.empty();
    }

    double getTotalPrice() const {
        double total = 0.0;
        for (const auto& product : bought_products){
            total += product.getPrice();
        }
        return total;
    }

    size_t getProductCount() const {
        return bought_products.size();
    }

};

// ����� ������������
class User {
private:
    string login;
    string password;
    Busket busket;
public:
    //������������

    //����������� ��� ������������ ��� �������
    User(const string& userLog, const string& userPass) : login(userLog),password(userPass) {}

    //����������� � ��������
    User(const string& userLog, const string& userPass, const Busket& userBask) : login(userLog), password(userPass), busket(userBask) {}

    //�������
    string getLog() const{
        return login;
    }


    string getPass() const{
        return password;
    }

    const Busket& getBusk() const{
        return busket;
    }

    //�������
    void setLog(const string& newLog){
        login = newLog;
    }

    void setPass(const string& newPass){
        password = newPass;
    }

    void setBusk(const Busket& newBusk){
        busket = newBusk;
    }

    // ��� ������ � �������� ������������
    void addToBusket(const Goods& product){
        busket.addProduct(product);
        cout << "\n=== ����� '" << product.getName() << "' �������� � ������� ������������ === " << login << endl;
    }

    bool removeFromBusket(const string& productName){
        bool result = busket.remove_product(productName);
        if (result) {
            cout << "\n=== ����� '" << productName << "' ������ �� ������� ������������ === " << login << endl;
        }
        return result;
    }

    void clearUserBusket(){
        busket.clear_busket();
        cout << "\n=== ������� ������������ " << login << " ������� === " << endl;
    }

    void displayUserBusket() const {
        cout << "\n === ������� ������������: " << login << " === " << endl;
        busket.display_busket();
        if (!busket.isEmpty()){
            cout << "\n����� ���������: " << busket.getTotalPrice() << " $ " << endl;
            cout << "\n���������� �������: " << busket.getProductCount() << endl;
        }
        cout << " ------------------------------- " << endl;
    }

    void displayUserInfo() const {
        cout << "������������: " << login << endl;
        cout << "�������: " << (busket.isEmpty()? "�����":to_string(busket.getProductCount())+ " �������") << endl;
        if(!busket.isEmpty()){
            cout << "����� ��������� �������: " << busket.getTotalPrice() << " $ " << endl;
        }
    }

};

int main()
{
    system("chcp 1251");
    system("cls");

    // �������� �������
    Goods laptop("ASUS Vivobook laptop", 75000,4.95);
    Goods mouse("LogiTech mouse", 700,4.7);
    Goods cooler("ASUS Cooler", 3500,4.87);
    Goods flash_USB("Flash-USB 64GB",1000,4.95);
    Goods headphones("Headphones JBL", 20000,4.95);

    // ���������� � ���������
    Category Tech("Technics");
    Tech.addGoods(laptop);
    Tech.addGoods(mouse);
    Tech.addGoods(cooler);
    Tech.addGoods(flash_USB);
    Tech.addGoods(headphones);
    Tech.diplayInfo();

    // �������� �������������
    User dmitriy("dmitriy","password8081");
    dmitriy.displayUserInfo();

    dmitriy.addToBusket(laptop);
    dmitriy.addToBusket(headphones);
    dmitriy.addToBusket(flash_USB);
    dmitriy.displayUserBusket();
    dmitriy.clearUserBusket();


};
