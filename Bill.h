#ifndef BILL_H
#define BILL_H
#include <iomanip>
#include "DoHoa.h"
#include <iostream>
#include "Template.h"
#include "Customer.h"
#include "Employee.h"
#include "Product.h"
#include <sstream>
#include "Book.h"
#include "Equipment.h"
#include "Purchase.h"
#include "Data.h"
// #pragma once
using namespace std;

// template <typename T>
// class LinkedList;
// Book book;
// Equipment equipment;
class Bill
{
private:
    string ID;
    float Price;
    string Date;
    string Payment_methods;
    Customer customer;
    Employee employee;
    Data<Purchase> List_Purchase;

public:
    Bill(string = "", float = 0.0, string = "", string = "", Customer = Customer(), Employee = Employee());
    ~Bill();

    string GetID();
    float GetPrice();
    string GetDate();
    string GetPayment_methods();
    Customer GetCustomer();
    Employee GetEmployee();
    Data<Purchase> &GetPurchase();

    void SetID(string);
    void SetPrice(float);
    void SetDate(string);
    void SetPayment_methods(string);
    void SetCustomer(const Customer &);
    void SetEmployy(const Employee &);
    void SetPurchase(const Data<Purchase> &);

    friend ostream &operator<<(ostream &, const Bill &);
    friend istream &operator>>(istream &, Bill &);
    bool operator==(const Bill &);
    bool operator!=(const Bill &);
    Bill &operator=(const Bill &);
    // template<typename T>
    void ReadDataFromFile(const string &, Data<Bill> &);

    Product &GetProductByID(const string &, LinkedList<Book> &, LinkedList<Equipment> &);
    double Revenue();
    void show();
    bool checkIDEmployee(const string& );
    bool checkIDCustomer(const string& );
    bool checkIDBill(const string& );
    
};

Bill::Bill(string x, float y, string n, string m, Customer o, Employee p)
    : ID(x), Price(y), Date(n), Payment_methods(m), customer(o), employee(p)
{
}

Bill::~Bill()
{
}

string Bill::GetID()
{
    return this->ID;
}

float Bill::GetPrice()
{
    return this->Price;
}

string Bill::GetDate()
{
    return this->Date;
}

string Bill::GetPayment_methods()
{
    return this->Payment_methods;
}

Customer Bill::GetCustomer()
{
    return this->customer;
}

Employee Bill::GetEmployee()
{
    return this->employee;
}

Data<Purchase> &Bill::GetPurchase()
{
    return this->List_Purchase;
}

void Bill::SetID(string x)
{
    this->ID = x;
}

void Bill::SetPrice(float x)
{
    this->Price = x;
}

void Bill::SetDate(string x)
{
    this->Date = x;
}

void Bill::SetPayment_methods(string x)
{
    this->Payment_methods = x;
}

void Bill::SetCustomer(const Customer &cus)
{
    this->customer = cus;
}

void Bill::SetEmployy(const Employee &Emp)
{
    this->employee = Emp;
}

void Bill::SetPurchase(const Data<Purchase> &List_Purchase)
{
    // List_Purchase.show();
    this->List_Purchase = List_Purchase;
}

void Bill::show()
{
    cout << "------------------HOA DON " << this->ID<<"---------------------" << endl;
    cout << "Ngay: " << this->Date << endl;
    cout << "Phuong thuc thanh toan: " << this->Payment_methods << endl;
    cout << "Ten khach hang la: " << this->customer.GetName() << endl;
    cout << "Ten nhan vien la: " << this->employee.GetName() << endl;
    cout << "--------------CAC SAN PHAM DA MUA LA-------------" << endl;
    for (int i = 0; i < this->List_Purchase.size(); i++)
    {
        cout << this->List_Purchase[i].getproductID()<<setw(15)<<this->List_Purchase[i].getPurQuantity()<<setw(15)<<this->List_Purchase[i].getPurPrice()<< endl;
    }
    cout << "Tong tien : " << this->Price << endl;
    cout << "-------------------------------------------------" << endl;
}

ostream &operator<<(ostream &o, const Bill &p)
{
    o << p.ID << "," << p.Price << "," << p.Date << "," << p.Payment_methods << "," << p.customer.GetID() << "," << p.employee.GetID() << endl;

    for (int i = 0; i < p.List_Purchase.size(); i++)
    {
        o << p.List_Purchase[i].getproductID() <<","<<p.List_Purchase[i].getPurQuantity()<<","<<p.List_Purchase[i].getPurPrice()<< endl;
    }

    return o;
}

Product &Bill::GetProductByID(const std::string &productID, LinkedList<Book> &List_Book, LinkedList<Equipment> &List_Equipment)
{

    Node<Book> *tempBook = List_Book.GetHead();
    while (tempBook != nullptr)
    {
        if (tempBook->data.GetID() == productID)
        {
            return tempBook->data;
        }
        tempBook = tempBook->next;
    }

    Node<Equipment> *tempEquipment = List_Equipment.GetHead();
    while (tempEquipment != nullptr)
    {
        if (tempEquipment->data.GetID() == productID)
        {
            return tempEquipment->data;
        }
        tempEquipment = tempEquipment->next;
    }

    // Nếu không tìm thấy, trả về một tham chiếu đến đối tượng Product mới
    // Lưu ý: Điều này có thể không an toàn, tùy thuộc vào cấu trúc dữ liệu của bạn.
    // Bạn có thể cần xử lý trường hợp không tìm thấy khác nhau.
    return *(new Product());
}

istream &operator>>(istream &in, Bill &p)
{
    // cout << "ID: ";
    // getline(in, p.ID);
    // fflush(stdin);
    while (true) {
        cout << "Enter Bill ID ! " << endl;
        getline(in, p.ID); // Giả sử đã định nghĩa hàm operator>> cho lớp Employee


        if (p.checkIDBill(p.ID)) {
            cout << "ID Bill da ton tai ! Vui long ban nhap lai !" << endl;
        } else {
             cout << "ID Bill hop le !" << endl;
            break; // Thoát khỏi vòng lặp nếu ID hợp lệ
        }
    }
    // cout << "Price: ";
    // in >> p.Price;
    // fflush(stdin);
    cout << "Date: ";
    getline(in, p.Date);
    fflush(stdin);
    cout << "Payment Methods: ";
    getline(in, p.Payment_methods);
    fflush(stdin);

    cout << "Customer Information: " << endl;
    // p.customer.PutID(); // Giả sử đã định nghĩa hàm operator>> cho lớp Customer
    in >> p.customer;
    // cout << "Employee Information: " << endl;
    // p.employee.PutID(); // Giả sử đã định nghĩa hàm operator>> cho lớp Employee
    // if(p.checkIDEmployee(p.employee.GetID()))
    // {
    //     return;
    // }
    // else
    // {

    // }
    while (true) {
        cout << "Enter Employee ID ! " << endl;
         p.employee.PutID(); // Giả sử đã định nghĩa hàm operator>> cho lớp Employee


        if (!p.checkIDEmployee(p.employee.GetID())) {
            cout << "ID Nhan vien khong dung ! Vui long ban nhap lai !" << endl;
        } else {
            // cout << "Employee ID is valid." << endl;
            break; // Thoát khỏi vòng lặp nếu ID hợp lệ
        }
    }
    cout << "Purchase Information: " << endl;

    int KT = 1;
    double producttotal = 0;
    Purchase Newpur;
    // delete p.List_Purchase[];

    while (KT)
    {
        in >> Newpur;
        p.List_Purchase.Add(Newpur);
        cout << "Nhap so 1 de tiep tuc nhap san pham trong don hang" << endl;
        cout << "Nhap so 0 de ket thuc" << endl;
        // fflush(stdin);
        while (1)
        {
            // cin.ignore();
            cout << "moi ban nhap lua chon: ";
            cin >> KT;
            if (KT == 1 || KT == 0)
            {
                break;
            }
            else
            {
                cout << "Ban da nhap sai, Moi ban nhap lai" << endl;
            }
        }

    }
    for (int i = 0; i < p.List_Purchase.size(); i++)
    {
        p.Price += p.List_Purchase[i].getPurPrice();
    }

    return in;
}

bool Bill::operator==(const Bill &p)
{
    return (this->ID == p.ID);
}

bool Bill::operator!=(const Bill &p)
{
    return (this->ID != p.ID);
}

Bill &Bill::operator=(const Bill &p)
{
    this->ID = p.ID;
    this->Payment_methods = p.Payment_methods;
    this->Date = p.Date;
    this->Price = p.Price;
    this->customer = p.customer;
    this->employee = p.employee;
    this->List_Purchase = p.List_Purchase;
    return *this;
}

double Bill::Revenue()
{
    double Revenue;
    Revenue += this->Price;
    return Revenue;
}

void Bill::ReadDataFromFile(const string &file, Data<Bill> &List_Bill)
{
    // List_Bill.Clearr();
    ifstream inputFile(file, std::ios::in);

    if (inputFile.is_open())
    {
        string line;

        while (getline(inputFile, line))
        {
            Bill p;
            istringstream iss(line);
            string token;

            // Read Bill information
            if (getline(iss, token, ','))
            {
                if (token.empty())
                    break;
                p.SetID(token);
            }

            if (getline(iss, token, ','))
            {
                p.SetPrice(stof(token));
            }

            if (getline(iss, token, ','))
            {
                p.SetDate(token);
            }

            if (getline(iss, token, ','))
            {
                p.SetPayment_methods(token);
            }

            if (getline(iss, token, ','))
            {
                Customer customer;
                customer.SetID(token);
                p.SetCustomer(customer);
            }

            if (getline(iss, token))
            {
                Employee employee;
                employee.SetID(token);
                p.SetEmployy(employee);
            }

            Data<Purchase> List_Purchase;
            
            // Parse product information
            while (getline(inputFile, line))
            {
                if (line.empty())
                {
                    break; // Stop reading products if an empty line is encountered
                }

                Purchase pur;
                istringstream prodIss(line);
                string productID, quantityStr, pricePur;

                // Read product ID
                getline(prodIss, productID, ',');
                pur.setproductID(productID);

                // Read product quantity
                getline(prodIss, quantityStr, ',');
                pur.setPurQuantity(stoi(quantityStr));

                // Read product price
                getline(prodIss, pricePur);
                pur.stePurPrice(stod(pricePur));

                List_Purchase.Add(pur);
            }

            // Set Bill information
            // List_Purchase.show();
            p.SetPurchase(List_Purchase);
            // cout << p;
            List_Purchase.Clearr();
            List_Bill.Add(p);
            
        }

        // List_Bill.show();
    }
    else
    {
        cout << "Cannot open file to read" << endl;
    }

    inputFile.close();
}


bool Bill::checkIDEmployee(const string& id) 
{
    std::ifstream file("D:\\C++\\PBL2-6\\output\\Employee.txt"); // Thay đổi đường dẫn file.txt của bạn

    if (!file.is_open()) {
        std::cerr << "Error opening file.txt" << std::endl;
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string existingID;
        getline(ss, existingID, ','); // Giả sử ID được lưu trữ như là một giá trị phân tách bằng dấu phẩy
        if (existingID == id) {
            file.close();
            return true; // ID đã tồn tại
        }
    }

    file.close();
    return false; // ID không tồn tại
}

bool Bill::checkIDCustomer(const string& id) 
{
    std::ifstream file("D:\\C++\\PBL2-6\\output\\Customer.txt"); // Thay đổi đường dẫn file.txt của bạn

    if (!file.is_open()) {
        std::cerr << "Error opening file.txt" << std::endl;
        return false;
    }

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string existingID;
        getline(ss, existingID, ','); // Giả sử ID được lưu trữ như là một giá trị phân tách bằng dấu phẩy
        if (existingID == id) {
            file.close();
            return true; // ID đã tồn tại
        }
    }

    file.close();
    return false; // ID không tồn tại
}

bool Bill::checkIDBill(const string& id) 
{
    std::ifstream file("D:\\C++\\PBL2-6\\output\\Bill.txt"); // Thay đổi đường dẫn file.txt của bạn

    if (!file.is_open()) {
        std::cerr << "Error opening file.txt" << std::endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string billID;
        getline(ss, billID, ','); // Giả sử ID hóa đơn được lưu trữ như là một giá trị phân tách bằng dấu phẩy
        if (billID == id) {
            file.close();
            return true; // ID hóa đơn đã tồn tại
        }
    }

    file.close();
    return false; // ID hóa đơn không tồn tại
}

#endif
