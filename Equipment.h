#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <iostream>
#include "Product.h"
#include "Template.h"
#include <sstream>
// #pragma once
using namespace std;

class Equipment : virtual public Product
{
private:
    string Producer;
    string Size;

public:
    Equipment(string = "", string = "", float = 0.0, string = "", int = 0, string = "", string = "");
    ~Equipment();
    string GetProducer();
    string GetSize();

    void SetProducer(string);
    void SetSize(string);

    friend ostream &operator<<(ostream &, const Equipment &);
    friend istream &operator>>(istream &, Equipment &);
    bool operator==(const Equipment &);
    bool operator!=(const Equipment &);
    Equipment &operator=(const Equipment &);
    // template<typename T>
    static void ReadDataFromFile(const string &, LinkedList<Equipment> &);
    // void UpdateEquipmentList(LinkedList<Equipment>& List_Equipment, Equipment& );
    void show();
    bool checkIDEquipment(const string& );
    void GetEquipmentInfoFromStock(const string &, LinkedList<Equipment> &);
    void UpdateOrAddEquipment(LinkedList<Equipment> & );
};

Equipment::Equipment(string x, string y, float t, string n, int h, string m, string p)
    : Product(x, y, t, n, h), Producer(m), Size(p)
{
}

Equipment::~Equipment()
{
}

string Equipment::GetProducer()
{
    return this->Producer;
}

string Equipment::GetSize()
{
    return this->Size;
}

void Equipment::SetProducer(string x)
{
    this->Producer = x;
}

void Equipment::SetSize(string x)
{
    this->Size = x;
}

void  Equipment::show()
{
    cout << "ID: " << this->ID << endl;
    cout << "Name: " << this->Name << endl;
    cout << "Price: " << this->Price << endl;
    cout << "Type: " << this->Type << endl;
    cout << "Quantity: " << this->Quantity << endl;
    cout<< "Producer: " << this->Producer << endl;
    cout << "Size: " << this->Size << endl;
    cout << "-------------------------------------" << endl;

   
}

ostream &operator<<(ostream &o, const Equipment &p)
{
    o << p.ID << "," << p.Name << "," << p.Quantity << "," << p.Price << "," << p.Type << "," << p.Producer << "," << p.Size << endl;

    return o;
}

istream &operator>>(istream &in, Equipment &p)
{
    Equipment equipment;
    LinkedList<Equipment> List_Equipment_Store;
    equipment.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Equipment.txt", List_Equipment_Store);
    cout << "Enter ID: ";
    getline(in, p.ID);

    if (p.checkIDEquipment(p.ID)) {
        // If ID exists, only ask for Quantity
        cout << "Dung cu nay da co trong kho. Vui long nhap luong !" << endl;
        cout << "Enter Quantity: ";
        in >> p.Quantity;
        fflush(stdin);
        p.GetEquipmentInfoFromStock(p.ID,List_Equipment_Store);

    } else {
    cout << "Enter Name: ";
    getline(in, p.Name);
    fflush(stdin);
     cout << "Enter Quantity: ";
    in >> p.Quantity;
    fflush(stdin);
    // cout << "Enter Stock: ";
    // in >> p.Stock;
    // fflush(stdin);
    cout << "Enter Price: ";
    in >> p.Price;
    fflush(stdin);
    cout << "Enter Type: ";
    getline(in, p.Type);
    fflush(stdin);
    // cout << "Enter Quantity: ";
    // in >> p.Quantity;
    // fflush(stdin);
    cout << "Enter Producer: ";
    getline(in, p.Producer);
    fflush(stdin);
    cout << "Enter Size: ";
    getline(in, p.Size);
    fflush(stdin);
    }
    return in;
}

bool Equipment::operator==(const Equipment &p)
{
    return (this->ID == p.ID);
}

bool Equipment::operator!=(const Equipment &p)
{
    return (this->ID != p.ID);
}

Equipment &Equipment::operator=(const Equipment &p)
{
    this->ID = p.ID;
    this->Name = p.Name;
    this->Producer = p.Producer;
    this->Price = p.Price;
    this->Quantity = p.Quantity;
    this->Size = p.Size;
    // this->Stock = p.Stock;
    this->Type = p.Type;
    return *this;
}

void Equipment::ReadDataFromFile(const string &file, LinkedList<Equipment> &List_Equipment)
{
    // LinkedList<Equipment> List_Equiment;
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
    string Producer;
    string Size;

    // Xóa danh sách hiện tại
    // while (head != nullptr) {
    //     Node<T>* temp = head;
    //     head = head->next;
    //     delete temp;
    // }
    List_Equipment.Clear();

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
        if (getline(iss, token, ','))
        {
            Quantity = stoi(token);
        }

        // Đọc paymentMethods
        if (getline(iss, token, ','))
        {
            Price = stoi(token);
        }

        // Đọc priceBill
        if (getline(iss, token, ','))
        {
            Type = token;
        }

        // Đọc CustomerID
        // if (getline(iss, token, ',')) {
        //     Quantity = stoi(token); // Chuyển từ string sang int
        // }

        // Đọc NameCus
        if (getline(iss, token, ','))
        {
            Producer = token;
        }

        if (getline(iss, token, ','))
        {
            Size = token;
        }

        // Tiếp tục tương tự cho các thành phần khác

        Equipment p;
        p.SetID(ID);
        p.SetName(Name);
        p.SetProducer(Producer);
        p.SetPrice(Price);
        // p.SetQuantity(Quantity);
        p.SetSize(Size);
        p.SetQuantity(Quantity);
        p.SetType(Type);

        List_Equipment.AddLast(p);
    }
}

// void Equipment::UpdateEquipmentList(LinkedList<Equipment>& List_Equipment, Equipment& Equipment)
// {
//     Node<Equipment> *tempEquipment = List_Equipment.GetHead();
//     while (tempEquipment != nullptr)
//     {
//         if (tempEquipment->data.GetID() == Equipment.GetID())
//         {
//             tempEquipment->data = Equipment;
//         }
//         tempEquipment = tempEquipment->next;
//     }
// }

bool Equipment::checkIDEquipment(const string& id) 
{
    ifstream file("D:\\C++\\PBL2-6\\output\\Equipment.txt");
    if (!file.is_open()) {
        cerr << "Error opening file.txt" << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string existingID;
        getline(ss, existingID, ','); // assuming ID is stored as a comma-separated value in the file
        if (existingID == id) {
            file.close();
            return true; // ID exists
        }
    }

    file.close();
    return false; // ID does not exist
}

void Equipment::GetEquipmentInfoFromStock(const string &id, LinkedList<Equipment> &EquipmentList) {
    // Tìm kiếm sách có ID tương ứng trong danh sách
    Node<Equipment> *current = EquipmentList.GetHead();
    while (current != nullptr) {
        if (current->data.GetID() == id) {
            // Nếu tìm thấy, gán thông tin cho đối tượng hiện tại
            this->SetSize(current->data.GetSize()) ;
            this->SetProducer(current->data.GetProducer());
            this->SetName(current->data.GetName());
            this->SetPrice(current->data.GetPrice());
            this->SetType(current->data.GetType());
            this->SetQuantity(current->data.GetQuantity()+this->GetQuantity());
            // return true;
        }
        current = current->next;
    }

    // Nếu không tìm thấy sách có ID tương ứng
    // return false;
}

void Equipment::UpdateOrAddEquipment(LinkedList<Equipment> &EquipmentList) 
{
        Node<Equipment> *current = EquipmentList.GetHead();
        while (current != nullptr) {
            if (current->data.GetID() == this->GetID()) {
                // Nếu ID tồn tại, cập nhật thông tin của sách
                current->data = *this;
                return;
            }
            current = current->next;
        }

        // Nếu ID không tồn tại, thêm sách mới vào danh sách
        // AddLast(newBook);
}

#endif // EQUIPMENT_