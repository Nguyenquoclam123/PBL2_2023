#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<vector>
#include "Person.h"
//#include "Bill.h"
#include "Template.h"
// #include "TClass.cpp"
#include<sstream>
//#pragma once
using namespace std;
class Bill; 
class Customer : virtual public Person
{
private:
// float Totalvalue ; 
// int Points ;
//LinkedList<Bill> billcus;
public:
    
    Customer(string ="",string ="",string ="",string ="",string ="");
    ~Customer();
    // float GetTotalvalue ();
    // int GetPoints ();

    // void SetTotalvalue (float);
    // void SetPoints (int);

    friend ostream& operator<<(ostream&, Customer&);
    friend istream& operator>>(istream&, Customer&);
    void PutID();
    //bool operator==(const Customer&);
    bool operator!=(const Customer&);
    Customer& operator=(const Customer&);
    
    bool operator==(const Customer&);
    static void ReadDataFromFile(const string&, LinkedList<Customer>& );
    void show();
    bool checkIDCustomer(const string& );
    void GetCustomerInfoFromStock(const string &, LinkedList<Customer> &);
};


Customer::Customer(string x, string y, string n, string m, string p)
    :Person(x,y,n,m,p)
{}

Customer::~Customer()
{}

// float Customer::GetTotalvalue ()
// {
//     return this->Totalvalue;
// }

// int Customer::GetPoints()
// {
//     return this->Points;
// }

// void Customer::SetTotalvalue(float x)
// {
//     this->Totalvalue = x;
// }

// void Customer::SetPoints(int x)
// {
//     this->Points = x;
// }

// ostream& operator<<(ostream& o,  Customer& p)
// {
//     o << "ID : " << p.ID << endl;
//     o << "Name : " << p.Name << endl;
//     o << "Gender : " << p.Gender << endl;
//     o << "Phone : " << p.Phone << endl;
//     o << "Address : " << p.Address << endl;
//     o << "Totalvalue : " << p.Totalvalue << endl;
//     o << "Points : " << p.Points << endl;
//     p.billcus.Display();
//     return o;
// }
ostream& operator<<(ostream& o,  Customer& p)
{
    o << p.ID <<","<<  p.Name << "," << p.Gender <<","<<  p.Phone << "," << p.Address << endl;
   // p.billcus.Display();
    return o;
}

istream& operator>>(istream& in, Customer& p)
{
    
    LinkedList<Customer> List_Customer_Store;
    p.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Customer.txt", List_Customer_Store);
    // cout << "ID : "; getline(in, p.ID);
    // fflush(stdin);
    while (true) 
    {
        cout << "Enter Customer ID : " ;
        getline(in, p.ID); // Giả sử đã định nghĩa hàm operator>> cho lớp Employee


        if (p.checkIDCustomer(p.ID)) {
            cout << "ID Customer da ton tai ! Ban co muon tiep tuc thuc hien hay khong !" << endl;
            int x;
            cout << "Nhan phim 1 neu dong y lay thong tin cua khach hang voi ID da ton tai. Nhan phim 0 de nhap lai!" << endl;
            cout <<"Lua chon cua ban la :"; cin >> x;
            cin.ignore();
            if(x==1)
            {
                p.GetCustomerInfoFromStock(p.ID,List_Customer_Store);
            break;
            }
            else if(x==0);
            else cout << "Nhap lua chon sai ! Vui long nhap lai !" << endl;
            
        } else {
                cout << "Name : "; getline(in, p.Name);
                fflush(stdin);
                cout << "Gender : "; getline(in, p.Gender);
                fflush(stdin);
                cout << "Phone : "; getline(in, p.Phone);
                fflush(stdin);
                cout << "Address : "; getline(in, p.Address);
                fflush(stdin);
            //  cout << "ID Bill hop le !" << endl;
            break; // Thoát khỏi vòng lặp nếu ID hợp lệ
        }
    }
   
    // cout << "Totalvalue : "; in >> p.Totalvalue;
    // fflush(stdin);
    // cout << "Points : "; in >> p.Points;
    // fflush(stdin);
    return in;
}

void Customer::PutID()
{
     cout << "ID : "; getline(cin, this->ID);
    fflush(stdin);

}

bool Customer::operator==(const Customer& p)
{
    return (this->ID == p.ID);
}

bool Customer::operator!=(const Customer& p)
{
    return (this->ID != p.ID);
}

Customer& Customer::operator=(const Customer& p)
{
    this->Address = p.Address;
    this->Gender = p.Gender;
    this->ID = p.ID;
    this->Name = p.Name;
    this->Phone = p.Phone;
    // this->Points = p.Points;
    // this->Totalvalue = p.Totalvalue;
    return *this;
}

void Customer::show()
{
    cout << "ID: " << this->ID << endl;
    cout << "Name: " << this->Name << endl;
    cout << "Gender: " << this->Gender << endl;
    cout << "Phone: " << this->Phone << endl;
    cout << "Address: " << this->Address << endl;
    cout << "-------------------------------------" << endl;
}

void Customer::ReadDataFromFile(const string& file, LinkedList<Customer>& List_Customer )
{
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
    // float Totalvalue ; 
    // int Points ;

    //Xóa danh sách hiện tại
    // while (head != nullptr) {
    //     Node<T>* temp = head;
    //     head = head->next;
    //     delete temp;
    // }
    List_Customer.Clear();
   
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
    // if (getline(iss, token, ' ')) {
    //     Totalvalue = stof(token); // Chuyển từ string sang int
    // }

    // // Đọc NameCus
    // if (getline(iss, token, ' ')) {
    // Points = stoi(token);
    // }


    // Tiếp tục tương tự cho các thành phần khác

    Customer p;
    p.SetID(ID);
    p.SetName(Name);
    p.SetGender(Gender);
    p.SetPhone(Phone);
    p.SetAddress(Address);
    // p.SetTotalvalue(Totalvalue);
    // p.SetPoints(Points);

    List_Customer.AddLast(p);
}

}


bool Customer::checkIDCustomer(const string& id) 
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

void Customer::GetCustomerInfoFromStock(const string &id, LinkedList<Customer> &CustomerList) {
    // Tìm kiếm sách có ID tương ứng trong danh sách
    Node<Customer> *current = CustomerList.GetHead();
    while (current != nullptr) {
        if (current->data.GetID() == id) {
            // Nếu tìm thấy, gán thông tin cho đối tượng hiện tại
            
            this->SetName(current->data.GetName());
            this->SetGender(current->data.GetGender());
            this->SetPhone(current->data.GetPhone());
            this->SetAddress(current->data.GetAddress());
            // return true;
        }
        current = current->next;
    }

    // Nếu không tìm thấy sách có ID tương ứng
    // return false;
}
#endif

