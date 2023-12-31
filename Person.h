#include<iostream>
#pragma once
using namespace std;

class Person
{
protected:
    string ID;
    string Name ;
    string Gender ;
    string Phone;
    string Address ;

public:
    Person(string ="",string ="",string ="",string ="",string ="");
    ~Person();
    string GetID() const;
    string GetName();
    string GetGender();
    string GetPhone();
    string GetAddress();

    void SetID(string);
    void SetName(string);
    void SetGender(string);
    void SetPhone(string);
    void SetAddress(string);

    friend ostream& operator<<(ostream&, const Person&);
    friend istream& operator>>(istream&,  Person&);
};

Person::Person(string x, string y, string n, string m, string p)
    :ID(x), Name(y), Gender(n), Phone(m), Address(p)
{}

Person::~Person()
{}

string Person::GetID() const
{
    return this->ID;
}

string Person::GetName()
{
    return this->Name;
}

string Person::GetGender()
{
    return this->Gender;
}

string Person::GetPhone()
{
    return this->Phone;
}

string Person::GetAddress()
{
    return this->Address;
}

void Person::SetID(string x)
{
    this->ID = x;
}

void Person::SetName(string x)
{
    this->Name = x;
}

void Person::SetGender(string x)
{
    this->Gender = x;
}

void Person::SetPhone(string x)
{
    this->Phone = x;
}

void Person::SetAddress(string x)
{
    this->Address = x;
}

// ostream& operator<<(ostream& o, const Person& p)
// {
//     o << "ID : " << p.ID << endl;
//     o << "Name : " << p.Name << endl;
//     o << "Gender : " << p.Gender << endl;
//     o << "Phone : " << p.Phone << endl;
//     o << "Address : " << p.Address << endl;
//     return o;
// }
ostream& operator<<(ostream& o, const Person& p)
{
    o << p.ID  <<"," << p.Name <<","<<  p.Gender <<","<<  p.Phone <<"," << p.Address << endl;
    return o;
}
istream& operator>>(istream& in, Person& p)
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
    return in;
}

