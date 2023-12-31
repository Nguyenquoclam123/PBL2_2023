#ifndef PURCHASE_H
#define PURCHASE_H
// #pragma once
#include <iostream>
#include "Template.h"
#include "Product.h"
#include "Book.h"
#include "Equipment.h"
using namespace std;
Book book;
Equipment equipment;
class Purchase
{
    private:
        string  productID;
        int PurQuantity; // số lượng sản phẩm mua
        double PurPrice;
    public: 
        Purchase(string ="", int = 0, double =0.0);
        ~Purchase(){}
        string getproductID();
        int getPurQuantity();
        double getPurPrice();
        void setproductID(string);
        void setPurQuantity(int);
        void stePurPrice(double);
        friend istream& operator>>(istream&, Purchase&);
        friend ostream& operator<<(ostream&, const Purchase&);
        bool operator==(const Purchase&);
        Product &GetProductByID(const string &,LinkedList<Book> &,  LinkedList<Equipment> &);
        void UpdateProductByID( Product &, LinkedList<Book> &, LinkedList<Equipment> &);
        bool CheckIDProduct(const string& ,const LinkedList<Book>& ,const LinkedList<Equipment>& );
        string getName();
};

Purchase::Purchase(string x, int y, double z)
{
    this->productID = x;
    this->PurQuantity = y; 
    this->PurPrice = z;
}
string Purchase::getproductID()
{
    return this->productID;
}
int Purchase::getPurQuantity()
{
    return this->PurQuantity;
}
double Purchase::getPurPrice()
{
    return this->PurPrice;
}
void Purchase::setproductID(string x)
{
    this->productID = x;
}
void Purchase::setPurQuantity(int x)
{
    this->PurQuantity = x;
}
void Purchase::stePurPrice(double x)
{
    this->PurPrice = x;
}

bool CheckIDProduct(const string& productID, const LinkedList<Book>& listBooks, const LinkedList<Equipment>& listEquipments) {
    // Kiểm tra trong danh sách sách (Books)
    Node<Book>* tempBook = listBooks.GetHead();
    while (tempBook != nullptr) {
        if (tempBook->data.GetID() == productID) {
            return true;  // Sản phẩm có tồn tại trong danh sách sách
        }
        tempBook = tempBook->next;
    }

    // Kiểm tra trong danh sách thiết bị (Equipments)
    Node<Equipment>* tempEquipment = listEquipments.GetHead();
    while (tempEquipment != nullptr) {
        if (tempEquipment->data.GetID() == productID) {
            return true;  // Sản phẩm có tồn tại trong danh sách thiết bị
        }
        tempEquipment = tempEquipment->next;
    }

    // Nếu không tìm thấy trong cả hai danh sách
    return false;
}


istream& operator>>(istream& in, Purchase& x)
{
    // int index = 0;
    // x.PurPrice = 0;

    while(1)
    {
        Product p;
    LinkedList<Book> List_Book_Store;
    LinkedList<Equipment> List_Equipment_Store;
    book.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Book.txt", List_Book_Store);
    equipment.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Equipment.txt", List_Equipment_Store);
        cout << "nhap ma san pham: ";
        in >> x.productID;
     if(CheckIDProduct(x.productID,List_Book_Store, List_Equipment_Store))
     {
        while ((1))
        {
           cout << "nhap so luong mua: ";
           in >> x.PurQuantity;
           if(x.getPurQuantity()==0)
           {
            cout << "so luong mua khong hop le, Moi ban nhap lai " << endl;
           }
           else
           {
            p = x.GetProductByID(x.productID,List_Book_Store,List_Equipment_Store);
     p.Reduce(x.getPurQuantity());
    x.UpdateProductByID(p,List_Book_Store,List_Equipment_Store);
    List_Book_Store.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Book.txt");
    List_Equipment_Store.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
     x.PurPrice = x.PurQuantity * p.GetPrice();
            break;
           }
        }
        break;
        
    }
    
    else
    {
        cout << "Ma san pham khong ton tai ! Moi ban nhap lai" << endl;
    }
    //  x.PurPrice = x.PurQuantity * p.GetPrice();
    }
    return in;

}

ostream& operator<<(ostream& o, const Purchase& x)
{
   // Product product = 
   o << x.productID << ","<< x.PurQuantity << "," << x.PurPrice << endl;
   return o;
}

bool Purchase::operator==(const Purchase&)
{
    return true;
}

Product &Purchase::GetProductByID(const std::string &productID, LinkedList<Book> &List_Book,LinkedList<Equipment> &List_Equipment)
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
    
    // Không tìm thấy sản phẩm, trả về một đối tượng Product mặc định
    // return Product();
}

void Purchase::UpdateProductByID( Product &product, LinkedList<Book> &List_Book, LinkedList<Equipment> &List_Equipment)
{
    Node<Book> *tempBook = List_Book.GetHead();
    while (tempBook != nullptr)
    {
        if (tempBook->data.GetID() == product.GetID())
        {
            // int x = tempBook->data.GetQuantity()-product.GetQuantity();
            //  tempBook->data.SetQuantity(x);
            tempBook->data.SetQuantity(product.GetQuantity()) ;
             return;
        }
        tempBook = tempBook->next;
    }
    

    Node<Equipment> *tempEquipment = List_Equipment.GetHead();
    while (tempEquipment != nullptr)
    {
        if (tempEquipment->data.GetID() == product.GetID())
        {
            // int x = tempEquipment->data.GetQuantity()-product.GetQuantity();
            //  tempEquipment->data.SetQuantity(x);
            tempEquipment->data.SetQuantity(product.GetQuantity()) ;
             return;
        }
        tempEquipment = tempEquipment->next;
    }
    

    // Không tìm thấy sản phẩm, trả về một đối tượng Product mặc định
    // return Product();
}




#endif
