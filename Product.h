#include<iostream>
#pragma once
#include<sstream>
#include "Template.h"
using namespace std;

class Product
{
protected:
string ID ;
string Name ;
// int Stock  ;
float Price ;
string Type ;
int Quantity;
public:
    Product(string ="", string ="",  float= 0.0, string ="", int = 0);
    ~Product();
    string GetID ();
    string GetName ();
    // int GetStock ();
    float GetPrice ();
    string GetType();
    int GetQuantity();

    void SetID (string);
    void SetName (string);
    // void SetStock (int);
    void SetPrice (float);
    void SetType(string);
    void SetQuantity(int);
    friend ostream& operator<<(ostream&, const Product&);
    friend istream& operator>>(istream&, Product&);
    Product& operator=(const Product&);
    void PutIDQuantity();
    void PutID();
     void Reduce(int); //giảm số lượng còn lại của sẩn phẩm trong kho
    static void ReadDataFromFile(const string &, LinkedList<Product> &);
    // void UpdateProductList(LinkedList<T>& , const T& );
};

Product::Product(string x, string y, float t, string n, int h)
    : ID(x), Name(y), Price(t), Type(n), Quantity(h)
{}

Product::~Product()
{}

string Product::GetID()
{
    return this->ID;
}

string Product::GetName()
{
    return this->Name;
}

// int Product::GetStock()
// {
//     return this->Stock;
// }

float Product::GetPrice()
{
    return this->Price;
}

string Product::GetType()
{
    return this->Type;
}

int Product::GetQuantity()
{
    return this->Quantity;
}

void Product::SetID(string x)
{
    this->ID = x;
}

void Product::SetName(string x)
{
    this->Name = x;
}

// void Product::SetStock(int x)
// {
//     this->Stock = x;
// }

void Product::SetPrice(float x)
{
    this->Price = x;
}

void Product::SetType(string x)
{
    this->Type = x;
}

void Product::SetQuantity(int x)
{
    this->Quantity = x;
}

// ostream& operator<<(ostream& o, const Product& p) 
// {
//     o << "ID: " << p.ID;
//     o << "Name: " << p.Name;
//     o << "Stock: " << p.Stock;
//     o << "Price: " << p.Price;
//     o << "Type: " << p.Type;
//     o << "Quantity: " << p.Quantity;
//     return o;
// }

ostream& operator<<(ostream& o, const Product& p) 
{
    o << p.ID<< "," << p.Name<< "," << p.Price<< "," << p.Type<< endl;
    return o;
}

istream& operator>>(istream& in, Product& p)
 {
    cout << "Enter ID: ";
    getline(in, p.ID);
    fflush(stdin);
    cout << "Enter Name: ";
    getline(in, p.Name);
     fflush(stdin);
    // cout << "Enter Stock: ";
    // in >> p.Stock;
    //  fflush(stdin);
    cout << "Enter Price: ";
    in >> p.Price;
     fflush(stdin);
    cout << "Enter Type: ";
    getline(in, p.Type);
     fflush(stdin);
    cout << "Enter Quantity: ";
    in >> p.Quantity;
     fflush(stdin);
    return in;
}

Product& Product::operator=(const Product& p)
{
    this->ID = p.ID;
    this->Name = p.Name;
    this->Price = p.Price;
    this->Quantity = p.Quantity;
    // this->Stock = p.Stock;
    this->Type = p.Type;
    return *this;
}

void Product::PutIDQuantity()
{
    cout << "Enter ID: ";
    getline(cin, this->ID);
    cout << "Enter Quantity: ";
    cin >> this->Quantity;
}

void Product::ReadDataFromFile(const string &file, LinkedList<Product> &List_Product)
{
    // LinkedList<Book> List_Book;
    ifstream inputFile(file, std::ios::in);
    if (!inputFile.is_open())
    {
        cerr << "Cannot open file to read" << endl;
        return;
    }
    string ID;
    string Name;
    // int Stock;
    float Price;
    string Type;
    int Quantity;

    // Xóa danh sách hiện tại
    // while (head != nullptr) {
    //     Node<T>* temp = head;
    //     head = head->next;
    //     delete temp;
    // }
    List_Product.Clear();

    string line;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        string token;

        // Đọc billID
        if (getline(iss, token, ','))
        {
            ID = token; // Chuyển từ string sang int
        }

        // Đọc dateBill
        if (getline(iss, token, ','))
        {
            Name = token;
        }

        // Đọc nameCashier
        // if (getline(iss, token, ','))
        // {
        //     Stock = stoi(token);
        // }

        // Đọc paymentMethods
        if (getline(iss, token, ','))
        {
            Price = stof(token);
        }

        // Đọc priceBill
        if (getline(iss, token, ','))
        {
            Type = token;
        }

        // Đọc CustomerID
        if (getline(iss, token, ','))
        {
            Quantity = stoi(token); // Chuyển từ string sang int
        }

        // Tiếp tục tương tự cho các thành phần khác

        Product p;
        p.SetID(ID);
        p.SetName(Name);
        // p.SetStock(Stock);
        p.SetPrice(Price);
        p.SetType(Type);
        p.SetQuantity(Quantity);

        List_Product.AddLast(p);
    }
}

void Product::Reduce(int n)
{
    if (n <= this->Quantity)
    {
        this->Quantity -= n;
    }
    else cout << "Khong du so luong cung cap!" << endl;
}

void Product::PutID()
{
     cout << "ID : "; getline(cin, this->ID);
    fflush(stdin);

}

// template <typename T>
// void Product::UpdateProductList(LinkedList<T>& productList, const T& product) {
//     Node<T>* tempProduct = productList.GetHead();

//     while (tempProduct != nullptr) {
//         if (tempProduct->data.GetID() == product.GetID()) {
//             tempProduct->data = product;
//         }
//         tempProduct = tempProduct->next;
//     }
// }
