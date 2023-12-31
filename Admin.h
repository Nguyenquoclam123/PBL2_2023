#ifndef ADMIN_H
#define ADMIN_H
#include<iostream>
#include "User.h"
#include "Template.h"
#include<sstream>
#pragma once
using namespace std;
class Template;
class Admin 
{
private:
    string Name;
    string Gmail;
public:
    Admin(string= "", string ="");
    ~Admin();

    string GetName();
    string GetGmail();
    void SetGmail(string);
    void SetName(string);

    friend ostream& operator<<(ostream&, Admin&);
    friend istream& operator>>(istream&, Admin&);
    bool operator==(const Admin&);
    bool operator!=(const Admin&);
    Admin& operator=(const Admin&);
    bool login();
    static void ReadDataFromFile(const string&, LinkedList<Admin>&);
    void show();

};

Admin::Admin( string p, string q)
    : Name(p), Gmail(q)
{}

Admin::~Admin()
{}

string Admin::GetName()
{
    return this->Name;
}

string Admin::GetGmail()
{
    return this->Gmail;
}

void Admin::SetName(string x)
{
    this->Name = x;
}

void Admin::SetGmail(string x)
{
    this->Gmail = x;
}

void Admin::show()
{
     cout << "Name : " << this->Name << endl;
    
    cout << "Gmail : "<< this->Gmail << endl;
    
    // cout << "UserName : "<< this->UserName << endl;
    
    // cout << "PassWord : " << this->PassWord << endl;
    cout << "-------------------------------------" << endl;
}

ostream& operator<<(ostream& o, Admin& p)
{
    o << p.Name <<"," << p.Gmail <<endl;
    return o;
}

istream& operator>>(istream& in, Admin& p)
{
    cout << "Name : "; getline(in,p.Name);
    fflush(stdin);
    cout << "Gmail : "; getline(in, p.Gmail);
    fflush(stdin);
    // cout << "UserName : "; getline(in, p.UserName);
    // fflush(stdin);
    // cout << "PassWord : "; getline(in, p.PassWord);
    // fflush(stdin);
    return in;
}

bool Admin::operator==(const Admin& p)
{
    return (this->Name == p.Name);
}

bool Admin::operator!=(const Admin& p)
{
    return (this->Name != p.Name);
}

Admin& Admin::operator=(const Admin& p)
{
    this->Name = p.Name ; this->Gmail = p.Gmail ;
    return *this;
}

//bool Admin::login() {
        // LinkedList<Admin> List_Admin;

        // try {
        //     this->ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Admin.txt", List_Admin);

        //     Node<Admin>* temp = List_Admin.GetHead();
        //     while (temp != nullptr) {
        //         try {
        //             if (temp->data.GetUserName() == this->GetUserName() && temp->data.GetPassWord() == this->GetPassWord()) {
        //                 std::cout << "Login successfully!" << std::endl;
        //                 return true;
        //             }
        //             temp = temp->next;
        //         } catch (const std::exception& e) {
        //             std::cerr << "Error comparing data: " << e.what() << std::endl;
        //             return false;
        //         }
        //     }
        // } catch (const std::exception& e) {
        //     std::cerr << "Error reading data from file: " << e.what() << std::endl;
        //     return false;
        // }

        // std::cout << "Username or password is incorrect. Please try again!!!" << std::endl;
        // return false;
    //}

// bool Admin::login()
// {
//     LinkedList<Admin> List_Admin;

//     try
//     {
//         this->ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-2\\output\\Admin.txt", List_Admin);
//         Node<Admin>* temp = List_Admin.GetHead();

//         while (temp != nullptr)
//         {
//             try
//             {
//                 if (temp->data.GetUserName() == this->GetUserName() && temp->data.GetPassWord() == this->GetPassWord())
//                 {
//                     cout << "Login successfully!" << endl;
//                     return true;
//                 }
//                 temp = temp->next;
//             }
//             catch (const std::exception& e)
//             {
//                 std::cerr << "Error comparing data: " << e.what() << std::endl;
//                 return false;
//             }
//         }
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << "Error reading data from file: " << e.what() << std::endl;
//         return false;
//     }

//     cout << "Username or password is incorrect. Please try again!!!" << endl;
//     return false;
// }


// bool Admin::login()
// {
//     LinkedList<Admin> List_Admin;
//     this->ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-2\\output\\Admin.txt",List_Admin);
//     Node<Admin>* temp = List_Admin.GetHead();
//   while (temp != nullptr)
//         {
//             if ( temp->data.UserName == this->UserName && temp->data.PassWord  == this->PassWord)
//             {
//                 cout << "Login successfully!" << endl;
//                 return true;
//             }
//              temp = temp->next;
//         }
//     {
//         cout << "Username or password is incorrect. Please try again!!!" << endl;
//         return false;
//     }
// }

// bool Admin::login() {

//     LinkedList<Admin> adminList = ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-2\\output\\Admin.txt");

//     Node<Admin>* temp = adminList.GetHead();
    
//     while (temp != nullptr) {
//         if (temp->data.UserName == this->UserName && temp->data.PassWord == this->PassWord) {
//             cout << "Login successfully!" << endl;
//             return true;
//         }
//         temp = temp->next;
//     }

//     cout << "Username or password is incorrect. Please try again!!!" << endl;
//     return false;
// }


void Admin::ReadDataFromFile(const string& file, LinkedList<Admin>& List_Admin)
{
    //LinkedList<Admin> List_Admin;
    ifstream inputFile(file, std::ios::in);
    if (!inputFile.is_open()) {
        cerr << "Cannot open file to read" << endl;
        return ;
    }
    string Name ;
    string Gmail ;
    // string UserName;
    // string PassWord;
    
    // Xóa danh sách hiện tại
    // while (head != nullptr) {
    //     Node<T>* temp = head;
    //     head = head->next;
    //     delete temp;
    // }

    string line;
while (getline(inputFile, line)) {
    istringstream iss(line);
    string token;

    // Đọc dateBill
    if (getline(iss, token, ',')) {
        Name = token;
    }

    // Đọc nameCashier
    if (getline(iss, token, ',')) {
        Gmail = token;
    }

    // Đọc paymentMethods
    // if (getline(iss, token, ',')) {
    //     UserName = token;
    // }

    // // Đọc priceBill
    // if (getline(iss, token, ',')) {
    //     PassWord= token;
    // }




    // Tiếp tục tương tự cho các thành phần khác

    Admin p;
    
    p.Name = Name;
    p.Gmail = Gmail;
    // p.UserName = UserName;
    // p.PassWord = PassWord;

    List_Admin.AddLast(p);
}
}
#endif // ADMIN_H