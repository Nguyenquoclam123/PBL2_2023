#pragma once
#include <stdio.h>
#include <string.h>
#include <fstream>

using namespace std;

class User
{
    public:
        string username;
        string password;
        User* next;
    public:
        User(string = "", string = "");
        ~User();
};

User::User(string u, string p)
{
    this->username=u;
    this->password=p;
    next=NULL;
}

User::~User() {}