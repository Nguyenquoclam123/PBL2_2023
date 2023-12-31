#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "Product.h"
#include <sstream>
#include "Template.h"
// #pragma once
using namespace std;

class Book : virtual public Product
{
private:
    string Author;
    string Publisher;
    string Language;

public:
    Book(string = "", string = "",  float = 0.0, string = "", int = 0, string = "", string = "", string = "");
    ~Book();
    string GetAuthor();
    string GetPublisher();
    string GetLanguage();

    void SetAuthor(string);
    void SetPublisher(string);
    void SetLanguage(string);
    
     bool checkIDBook(const string& );

    friend ostream &operator<<(ostream &, const Book &);
    friend istream &operator>>(istream &, Book &);

    bool operator==(const Book &);
    bool operator!=(const Book &);
    Book &operator=(const Book &);

    static void ReadDataFromFile(const string &, LinkedList<Book> &);
    // void UpdateBooktList(LinkedList<Book>&, Book& );
    void show();
    void GetBookInfoFromStock(const string &, LinkedList<Book> &);
    void UpdateOrAddBook(LinkedList<Book> & );
   
};

Book::Book(string x, string y,  float t, string n, int h, string m, string p, string q)
    : Product(x, y, t, n, h), Author(m), Publisher(p), Language(q)
{
}

Book::~Book()
{
}

string Book::GetAuthor()
{
    return this->Author;
}

string Book::GetPublisher()
{
    return this->Publisher;
}

string Book::GetLanguage()
{
    return this->Language;
}

void Book::SetAuthor(string x)
{
    this->Author = x;
}

void Book::SetPublisher(string x)
{
    this->Publisher = x;
}

void Book::SetLanguage(string x)
{
    this->Language = x;
}


void  Book::show()
{
    cout << "ID: " << this->ID << endl;
    cout << "Name: " << this->Name << endl;
    cout << "Price: " << this->Price << endl;
    cout << "Type: " << this->Type << endl;
    cout << "Quantity: " << this->Quantity << endl;
    cout<< "Author: " << this->Author << endl;
    cout << "Publisher: " << this->Publisher << endl;
    cout << "Language: " << this->Language << endl;
    cout << "-------------------------------------" << endl;
   
}

bool Book::operator==(const Book &p)
{
    return (this->ID == p.ID);
}

bool Book::operator!=(const Book &p)
{
    return (this->ID != p.ID);
}

Book &Book::operator=(const Book &p)
{
    this->ID = p.ID;
    this->Language = p.Language;
    // this->Stock = p.Stock;
    this->Type = p.Type;
    this->Quantity = p.Quantity;
    this->Name = p.Name;
    this->Price = p.Price;
    this->Publisher = p.Publisher;
    return *this;
}

ostream &operator<<(ostream &o, const Book &p)
{
    o << p.ID << "," << p.Name << ","<< p.Quantity <<"," << p.Price << "," << p.Type << "," << p.Author << "," << p.Publisher << "," << p.Language << endl;

    return o;
}

// istream &operator>>(istream &in, Book &p)
// {
//     cout << "Enter ID: ";
//     getline(in, p.ID);
//     fflush(stdin);
//     cout << "Enter Name: ";
//     getline(in, p.Name);
//     fflush(stdin);
//     // cout << "Enter Stock: ";
//     // in >> p.Stock;
//     // fflush(stdin);
//     cout << "Enter Price: ";
//     in >> p.Price;
//     fflush(stdin);
//     cout << "Enter Type: ";
//     getline(in, p.Type);
//     fflush(stdin);
//     cout << "Enter Quantity: ";
//     in >> p.Quantity;
//     fflush(stdin);
//     cout << "Enter Author: ";
//     getline(in, p.Author);
//     fflush(stdin);
//     cout << "Enter Publisher: ";
//     getline(in, p.Publisher);
//     fflush(stdin);
//     cout << "Enter Language: ";
//     getline(in, p.Language);
//     fflush(stdin);
//     return in;
// }

bool Book::checkIDBook(const string& id) 
{
    ifstream file("D:\\C++\\PBL2-6\\output\\Book.txt");
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

istream &operator>>(istream &in, Book &p) {
    Book book;
    LinkedList<Book> List_Book_Store;
    book.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Book.txt", List_Book_Store);
    cout << "Enter ID: ";
    getline(in, p.ID);
    fflush(stdin);
    if (p.checkIDBook(p.ID)) {
        // If ID exists, only ask for Quantity
        cout << "Sach nay da co trong kho. Vui long nhap luong !" << endl;
        cout << "Enter Quantity: ";
        in >> p.Quantity;
        fflush(stdin);
        p.GetBookInfoFromStock(p.ID,List_Book_Store);

    } else {
        // If ID doesn't exist, ask for all information
        cout << "Enter Name: ";
        getline(in, p.Name);
        fflush(stdin);
        cout << "Enter Price: ";
        in >> p.Price;
        fflush(stdin);
        cout << "Enter Type: ";
        getline(in, p.Type);
        fflush(stdin);
        cout << "Enter Quantity: ";
        in >> p.Quantity;
        fflush(stdin);
        cout << "Enter Author: ";
        getline(in, p.Author);
        fflush(stdin);
        cout << "Enter Publisher: ";
        getline(in, p.Publisher);
        fflush(stdin);
        cout << "Enter Language: ";
        getline(in, p.Language);
        fflush(stdin);
    }

    return in;
}


void Book::ReadDataFromFile(const string &file, LinkedList<Book> &List_Book)
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
    string Author;
    string Publisher;
    string Language;

    // Xóa danh sách hiện tại
    // while (head != nullptr) {
    //     Node<T>* temp = head;
    //     head = head->next;
    //     delete temp;
    // }
    List_Book.Clear();

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
            Price = stof(token);
        }

        // Đọc priceBill
        if (getline(iss, token, ','))
        {
            Type = token;
        }

        // Đọc CustomerID
        // if (getline(iss, token, ','))
        // {
        //     Quantity = stoi(token); // Chuyển từ string sang int
        // }

        // Đọc NameCus
        if (getline(iss, token, ','))
        {
            Author = token;
        }

        if (getline(iss, token, ','))
        {
            Publisher = token;
        }

        if (getline(iss, token, ','))
        {
            Language = token;
        }

        // Tiếp tục tương tự cho các thành phần khác

        Book p;
        p.SetID(ID);
        p.SetName(Name);
        p.SetQuantity(Quantity);
        p.SetPrice(Price);
        p.SetType(Type);
        //p.SetQuantity(Quantity);
        p.SetAuthor(Author);
        p.SetPublisher(Publisher);
        p.SetLanguage(Language);

        List_Book.AddLast(p);
    }
}

// void Book::UpdateBooktList(LinkedList<Book>& List_Book, Book& book)
// {
//     Node<Book> *tempBook = List_Book.GetHead();
//     while (tempBook != nullptr)
//     {
//         if (tempBook->data.GetID() == book.GetID())
//         {
//             tempBook->data = book;
//         }
//         tempBook = tempBook->next;
//     }
// }

void Book::GetBookInfoFromStock(const string &id, LinkedList<Book> &bookList) {
    // Tìm kiếm sách có ID tương ứng trong danh sách
    Node<Book> *current = bookList.GetHead();
    while (current != nullptr) {
        if (current->data.GetID() == id) {
            // Nếu tìm thấy, gán thông tin cho đối tượng hiện tại
            this->SetLanguage(current->data.GetLanguage()) ;
            this->SetAuthor(current->data.GetAuthor());
            this->SetName(current->data.GetName());
            this->SetPrice(current->data.GetPrice());
            this->SetPublisher(current->data.GetPublisher());
            this->SetType(current->data.GetType());
            this->SetQuantity(current->data.GetQuantity()+this->GetQuantity());
            // return true;
        }
        current = current->next;
    }

    // Nếu không tìm thấy sách có ID tương ứng
    // return false;
}

void Book::UpdateOrAddBook(LinkedList<Book> &bookList) 
{
        Node<Book> *current = bookList.GetHead();
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

#endif // BOOK_H