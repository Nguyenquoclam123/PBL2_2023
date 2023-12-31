#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include "Template.h"
#include<vector>
#include "User.h"
#include "Person.h"
#include "Bill.h"
#include<sstream>
//#pragma once
using namespace std;
template <typename T>
class LinkedList;
template <typename T>
class Node;
class Employee : public Person 
{
private:
int Sarary ;
// float Revenue ;
//LinkedList<Bill> billcus;
public:
    Employee(string ="",string ="",string ="",string ="",string ="", int = 0);
    ~Employee();
    int GetSarary ();
    // float GetRevenue ();

    void SetSarary (int);
    // void SetRevenur (float);

    friend ostream& operator<<(ostream&, Employee&);
    friend istream& operator>>(istream&, Employee&);
    void PutID();
    bool operator!=(const Employee&);
    bool operator==(const Employee&);
    Employee& operator=(const Employee&);
    //template<typename T>
    static void ReadDataFromFile(const string&, LinkedList<Employee>&);
    //template<typename T>
    bool login();
    void show();
};

Employee::Employee(string x, string y, string n, string m, string p, int q)
    :Person(x,y,n,m,p),  Sarary(q)
{}

Employee::~Employee()
{}

int Employee::GetSarary()
{
    return this->Sarary;
}

// float Employee::GetRevenue()
// {
//     return this->Revenue;
// }

void Employee::SetSarary(int x)
{
    this->Sarary = x;
}

// void Employee::SetRevenur(float x)
// {
//     this->Revenue = x;
// }

void  Employee::show()
{
    cout << "ID : " << this->ID << endl;
    cout << "Name : " << this->Name << endl;
    cout << "Gender : " << this->Gender << endl;
    cout << "Phone : " << this->Phone << endl;
    cout << "Address : " << this->Address << endl;
    // cout << "UserName : " << this->UserName << endl;
    // cout << "PassWord : " << this->PassWord << endl;
    // p.billcus.Display();
    cout << "-------------------------------------" << endl;
    
}
ostream& operator<<(ostream& o, Employee& p)
{
    o <<  p.ID <<"," << p.Name << "," << p.Gender << "," << p.Phone <<  "," << p.Address << "," << p.Sarary  << endl;
   // p.billcus.Display();
    return o;
}

istream& operator>>(istream& in, Employee& p)
{
    cout << "ID : "; getline(in,p.ID);
    fflush(stdin);
    cout << "Name : "; getline(in, p.Name);
    fflush(stdin);
    cout << "Gender : "; getline(in, p.Gender);
    fflush(stdin);
    cout << "Phone : "; getline(in, p.Phone);
    fflush(stdin);
    cout << "Address : "; getline(in, p.Address);
    fflush(stdin);
    cout << "Sarary : " ; in >> p.Sarary;
    fflush(stdin);
    // cout << "Revenue : " ; in >> p.Revenue;
    // fflush(stdin);
    // cout << "UserName : " ; getline(in, p.UserName);
    // fflush(stdin);
    // cout << "PassWord : " ; getline(in, p.PassWord);
    // fflush(stdin);
    return in;
}

void Employee::PutID()
{
     cout << "ID : "; getline(cin, this->ID);
    fflush(stdin);
    
}

bool Employee::operator!=(const Employee& p)
{
    return (this->ID != p.ID);
}

bool Employee::operator==(const Employee& p)
{
    return (this->ID == p.ID);
}

Employee& Employee::operator=(const Employee& p)
{
    this->Address = p.Address;
    this->Gender = p.Gender;
    this->ID = p.ID;
    this->Name = p.Name;
    // this->PassWord = p.PassWord;
    this->Phone = p.Phone;
    // this->Revenue = p.Revenue;
    this->Sarary = p.Sarary;
    // this->UserName = p.UserName;
    return *this;
}

//bool Employee::login() {
    // LinkedList<Employee> List_Employee;

    // try {
    //     this->ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Employee.txt", List_Employee);

    //     Node<Employee>* temp = List_Employee.GetHead();
    //     while (temp != nullptr) {
    //         try {
    //             if (temp->data.GetUserName() == GetUserName() && temp->data.GetPassWord() == GetPassWord()) {
    //                 cout << "Login successfully!" << endl;
    //                 return true;
    //             }
    //             temp = temp->next;
    //         } catch (const std::exception& e) {
    //             cerr << "Error comparing data: " << e.what() << endl;
    //             return false;
    //         }
    //     }
    // } catch (const std::exception& e) {
    //     cerr << "Error reading data from file: " << e.what() << endl;
    //     return false;
    // }

    // cout << "Username or password is incorrect. Please try again!!!" << endl;
    // return false;
//}



void Employee::ReadDataFromFile(const string& file, LinkedList<Employee>& List_Employee) {
      ifstream inputFile(file, std::ios::in);
    if (!inputFile.is_open()) {
        cerr << "Khong the mo file de doc" << endl;
        return;
    }

    string ID;
    string Name ;
    string Gender ;
    string Phone;
    string Address ;
    int Sarary ;
    // float Revenue ;
    // string UserName;
    // string PassWord;

    List_Employee.Clear();
   
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string token;

        // Đọc billID
    if (getline(iss, token, ',')) {
            ID = token; // Chuyển từ string sang int
        }

        // Đọc dateBill
        if (getline(iss, token, ',')) {
            Name = token;
        }

        // Đọc nameCashier
        if (getline(iss, token, ',')) {
            Gender = token;
        }

        // Đọc paymentMethods
        if (getline(iss, token, ',')) {
            Phone = token;
        }

        // Đọc priceBill
        if (getline(iss, token, ',')) {
            Address = token;
        }

        // Đọc CustomerID
        if (getline(iss, token, ',')) {
            Sarary = stoi(token); // Chuyển từ string sang int
        }

        // Đọc NameCus
        // if (getline(iss, token, ',')) {
        // Revenue = stof(token);
        // }

        // Đọc PhoneCus
        // if (getline(iss, token, ',')) {
        //     UserName = token;
        // }

        // // Đọc GenderCus
        // if (getline(iss, token, ',')) {
        //     PassWord = token;
        // }


    // Tiếp tục tương tự cho các thành phần khác

   Employee p;
   p.SetID(ID);
   p.SetName(Name);
   p.SetGender(Gender);
   p.SetPhone(Phone);
   p.SetAddress(Address);
   p.SetSarary(Sarary);
//    p.SetRevenur(Revenue);
//    p.SetUserName(UserName);
//    p.SetPassWord(PassWord);

    List_Employee.AddLast(p);
}
}
#endif
