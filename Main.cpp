#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Book.h"
#include "Equipment.h"
#include "Product.h"
#include "Bill.h"
#include "Customer.h"
#include "Employee.h"
#include "Admin.h"
#include "template.h"
#include <iomanip>
#include "Purchase.h"
// #pragma once

using namespace std;

void menu_Manager_Product_Book()
{
    LinkedList<Book> List_Book;
    Book Book;
    string ID;
    int choice;
    do
    {
        //system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Bill Manager ****                  *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View List Book  |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Add Book        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Find Book       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Delete Book    |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Edit Book       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Change Emloyee_Password|                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            Book.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Book.txt", List_Book);
            List_Book.Display();
            break;
        case 2:
            cout << "Enter the customer information you want to add " << endl;
            cin.ignore();
            cin >> Book;
            if (Book.checkIDBook(Book.GetID()))
                    {
                                    Node<Book> *current = List_Book.GetHead();
                        while (current != nullptr) {
                            if (current->data.GetID() == Book.GetID()) {
                                // Cập nhật số lượng
                                current->data.SetQuantity(current->data.GetQuantity() + Book.GetQuantity());

                                // Ghi danh sách mới vào file
                                List_Book.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt");
                                
                                // cout << "Cap nhat so luong thanh cong." << endl;
                                break; // Kết thúc vòng lặp khi đã cập nhật xong
                            }
                            current = current->next;
                        }
                    }
            else
            {
            List_Book.AddLast(Book);
            List_Book.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt");
            }
            break;
        case 3:
            Book.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Book.txt", List_Book);
            cin.ignore();
            cout << "Enter the customer ID you want to find " << endl;
            getline(cin, ID);
            Book.SetID(ID);
            List_Book.Findinf(Book);
            break;
        case 4:
            Book.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Book.txt", List_Book);
            cin.ignore();
            cout << "Enter the customer ID you want to delete " << endl;
            getline(cin, ID);
            Book.SetID(ID);
            List_Book.DeleteDataFromFile(Book);
            List_Book.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Book.txt");
            List_Book.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Book.txt");
            break;
        case 5:
            cin.ignore();
            cout << "Enter the customer ID you want to edit " << endl;
            getline(cin, ID);
            Book.SetID(ID);
            List_Book.UpdateBill(Book);
            List_Book.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Book.txt");
            List_Book.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Book.txt");
            break;
        case 6:
            // cout << "Enter Room ID: ";
            // cin >> ID;
            // customer::change_user_name(ID);
            // break;
        default:
            break;
        }
        // L.clear();
        // if (choice == 0)
        //     break;
        // system("pause");

    } while (choice != 0);
}

void menu_Manager_Product_Equipment()
{
    LinkedList<Equipment> List_Equipment;
    Equipment Equipment;
    string ID;
    int choice;
    do
    {
        //system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Bill Manager ****                  *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View List Book  |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Add Book        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Find Book       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Delete Book    |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Edit Book       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Change Emloyee_Password|                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            Equipment.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt", List_Equipment);
            List_Equipment.Display();
            break;
        case 2:
            cout << "Enter the customer information you want to add " << endl;
            cin.ignore();
            cin >> Equipment;
            List_Equipment.AddLast(Equipment);
            List_Equipment.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt");
            break;
        case 3:
            Equipment.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt", List_Equipment);
            cin.ignore();
            cout << "Enter the customer ID you want to find " << endl;
            getline(cin, ID);
            Equipment.SetID(ID);
            List_Equipment.Findinf(Equipment);
            break;
        case 4:
            Equipment.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt", List_Equipment);
            cin.ignore();
            cout << "Enter the customer ID you want to delete " << endl;
            getline(cin, ID);
            Equipment.SetID(ID);
            List_Equipment.DeleteDataFromFile(Equipment);
            List_Equipment.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt");
            List_Equipment.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt");
            break;
        case 5:
            cin.ignore();
            cout << "Enter the customer ID you want to edit " << endl;
            getline(cin, ID);
            Equipment.SetID(ID);
            List_Equipment.UpdateBill(Equipment);
            List_Equipment.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt");
            List_Equipment.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt");
            break;
        case 6:
            // cout << "Enter Room ID: ";
            // cin >> ID;
            // customer::change_user_name(ID);
            // break;
        default:
            break;
        }
        // L.clear();
        // if (choice == 0)
        //     break;
        // system("pause");

    } while (choice != 0);
}

void menu_Manager_Customer()
{
    LinkedList<Customer> List_Customer;
    Customer Customer;
    string ID;
    int choice;
    do
    {
        // system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Customer Manager ****                  *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View List Customer  |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Add Customer        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Find Customer       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Delete Customer     |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Edit Customer       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cin.ignore();
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
            cin.ignore();
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            Customer.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt", List_Customer);
            List_Customer.Display();
            break;
        case 2:
            cout << "Enter the customer information you want to add " << endl;
            cin.ignore();
            cin >> Customer;
            List_Customer.AddLast(Customer);
            List_Customer.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt");
            break;
        case 3:
            Customer.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt", List_Customer);
            cin.ignore();
            cout << "Enter the customer ID you want to find " << endl;
            getline(cin, ID);
            Customer.SetID(ID);
            List_Customer.Findinf(Customer);
            break;
        case 4:
            Customer.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt", List_Customer);
            cin.ignore();
            cout << "Enter the customer ID you want to delete " << endl;
            getline(cin, ID);
            Customer.SetID(ID);
            List_Customer.DeleteDataFromFile(Customer);
            List_Customer.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt");
            List_Customer.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt");
            break;

        case 5:      
            cin.ignore();
            cout << "Enter the customer ID you want to edit " << endl;
            getline(cin, ID);
            Customer.SetID(ID);
            List_Customer.UpdateBill(Customer);
            List_Customer.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt");
            List_Customer.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt");
            break;

        default:
            break;
        }
    } while (choice != 0);
}

void menu_Manager_Employee()
{
    LinkedList<Employee> List_Employee;
    Employee Employee;
    string ID;
    int choice;
    do
    {
        //system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Employee Manager ****                  *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View List Employee  |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Add Employee        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Find Employee       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Delete Employee    |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Edit Employee       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Change Emloyee_Password|                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            Employee.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Employee.txt", List_Employee);
            List_Employee.Display();
            break;
        case 2:
            cout << "Enter the customer information you want to add " << endl;
            cin.ignore();
            cin >> Employee;
            List_Employee.AddLast(Employee);
            List_Employee.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Employee.txt");
            break;
        case 3:
            Employee.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Employee.txt", List_Employee);
            cin.ignore();
            cout << "Enter the customer ID you want to find " << endl;
            getline(cin, ID);
            Employee.SetID(ID);
            List_Employee.Findinf(Employee);
            break;
        case 4:
            Employee.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Employee.txt", List_Employee);
            cin.ignore();
            cout << "Enter the customer ID you want to delete " << endl;
            getline(cin, ID);
            Employee.SetID(ID);
            List_Employee.DeleteDataFromFile(Employee);
            List_Employee.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Employee.txt");
            List_Employee.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Employee.txt");
            break;
        case 5:
            cin.ignore();
            cout << "Enter the customer ID you want to edit " << endl;
            getline(cin, ID);
            Employee.SetID(ID);
            List_Employee.UpdateBill(Employee);
            List_Employee.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Employee.txt");
            List_Employee.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Employee.txt");
            break;
        case 6:
            // cout << "Enter Room ID: ";
            // cin >> ID;
            // customer::change_user_name(ID);
            // break;
        default:
            break;
        }
        // L.clear();
        // if (choice == 0)
        //     break;
        // system("pause");

    } while (choice != 0);
}

void menu_Manager_Bill()
{
    Data<Bill> List_Bill;
    LinkedList<Customer> List_Customer;
    Bill bill;
    string ID;
    int choice;
    do
    {
        //system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Bill Manager ****                  *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View List Bill  |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Add Bill        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Find Bill       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Delete Bill    |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Edit Bill       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Change Emloyee_Password|                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        // Data<Bill> List_Bill;
        switch (choice)
        {
        case 1:
            // List_Bill.Clear();
            //  Data<Bill> List_Bill;
            if(List_Bill.empty())

            {
                bill.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Bill.txt", List_Bill);
            }
             List_Bill.show();
            
            break;
        case 2:
            // Data<Bill> List_Bill;
            bill = Bill();
            cout << "Enter the customer information you want to add " << endl;
            cin.ignore();
            cin >> bill;
            // Revenue = bill.Revenue();
            List_Bill.Add(bill);
            List_Bill.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Bill.txt");
            List_Customer.AddLast(bill.GetCustomer());
            List_Customer.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt");
            break;
        case 3:
            // Data<Bill> List_Bill;
            if(List_Bill.empty())

            {
                bill.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Bill.txt", List_Bill);
            }
            cin.ignore();
            cout << "Enter the customer ID you want to find " << endl;
            getline(cin, ID);
            bill.SetID(ID);
            List_Bill.Find(bill);
            break;
        case 4:
            // Data<Bill> List_Bill;
            if(List_Bill.empty())

            {
                bill.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Bill.txt", List_Bill);
            }
            cin.ignore();
            cout << "Enter the customer ID you want to delete " << endl;
            getline(cin, ID);
            bill.SetID(ID);
            List_Bill.DeleteData(bill);
            List_Bill.Data::ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Bill.txt");
            List_Bill.WriteAllDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Bill.txt");
            break;
        case 5:
            // Data<Bill> List_Bill;
            cin.ignore();
            cout << "Enter the customer ID you want to edit " << endl;
            getline(cin, ID);
            bill.SetID(ID);
            List_Bill.UpdateBill(bill);
            List_Bill.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Bill.txt");
            List_Bill.WriteAllDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Bill.txt");
            break;
        case 6:
            // cout << "Enter Room ID: ";
            // cin >> ID;
            // customer::change_user_name(ID);
            // break;
        default:
            break;
        }
        // L.clear();
        // if (choice == 0)
        //     break;
        // system("pause");

    } while (choice != 0);
}

void menu_Manager_Product()
{
    LinkedList<Product> List_Product;
    Product Product;
    string ID;
    int choice;
    do
    {
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Product Manager ****                  *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Manager Book             |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Manager Equipment        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
           menu_Manager_Product_Book();
            break;
        case 2:
            menu_Manager_Product_Equipment();
            break;
        default:
            break;
        }
        // L.clear();
        // if (choice == 0)
        //     break;
        // system("pause");

    } while (choice != 0);
}

void menu_Manager_Revenue()
{
    Data<Bill> List_Bill;
    Bill bill;
    string ID;
    double Revenue=0;
    int choice;
    do
    {
        // system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Revenue Manager ****                  *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) View List Revenue  |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Add Customer        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Find Customer       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Delete Customer     |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Edit Customer       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Change Emloyee_Password|                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            if(List_Bill.empty())

            {
                bill.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Bill.txt", List_Bill);
                for (int i = 0; i < List_Bill.size(); i++)
             {
                Revenue += List_Bill[i].GetPrice();
             }
            }
            //  for (int i = 0; i < List_Bill.size(); i++)
            //  {
            //     Revenue += List_Bill[0].GetPrice();
            //  }
            cout << "Revenue of store is " << Revenue;
            break;
        case 2:
            // add
            // cin >> object2;
            // object2.set_customer_id(Convert::CreateID("customer.txt"));
            // object2.add_customer();
            // break;
        case 3:
            // cout << "Find Information Customer: " << endl;
            // if (!customer::find_customer(L))
            // {
            //     cout << "Not Found!" << endl;
            //     continue;
            // }
            // else
            // {
            //     box_customer(3, 10, L);
            //     gotoXY(0, 0);
            // }
            // break;
        case 4:
            // cout << "Find Information Customer: " << endl;
            // if (!customer::find_customer(L))
            // {
            //     cout << "Not Found!" << endl;
            //     continue;
            // }
            // else
            // {
            //     box_customer(3, 10, L);
            //     gotoXY(0, 2 * L.getSize() + 13);
            // }
            // cout << "Enter Customer ID: ";
            // cin >> ID;
            // customer::delete_customer(ID);
            // break;
        case 5:
            // cout << "Find Information Customer: " << endl;
            // if (!customer::find_customer(L))
            // {
            //     cout << "Not Found!" << endl;
            //     continue;
            // }
            // box_customer(3, 10, L);
            // gotoXY(0, 2 * L.getSize() + 13);
            // L.clear();
            // cout << "Enter Customer ID:";
            // cin >> ID;
            // customer::find_idcustomer(ID, L);
            // system("cls");
            // cout << "Informatin Current Customer: " << endl;
            // box_customer(3, 3, L);
            // gotoXY(0, 2 * L.getSize() + 6);
            // cout << "Enter New Information: " << endl;
            // customer::update_customer(L[0]);
            // break;
        case 6:
            // cout << "Enter Room ID: ";
            // cin >> ID;
            // customer::change_user_name(ID);
            // break;
        default:
            break;
        }
        // L.clear();
        // if (choice == 0)
        //     break;
        // system("pause");

    } while (choice != 0);
}

void menu_Manager_My_Info()
{
    LinkedList<Admin> List_Admin;
    Admin Admin;
    string ID;
    int choice;
    do
    {
        system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Product Manager ****                  *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
       cout << "\t\t\t*\t|  1) View Info Admin  |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Add Admin        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Find Admin       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Delete Admin     |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Edit Admin       |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit                |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 6)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            Admin.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-3\\output\\Admin.txt", List_Admin);
            List_Admin.Display();
            break;
        case 2:
            cout << "Enter the customer information you want to add " << endl;
            cin.ignore();
            cin >> Admin;
            List_Admin.AddLast(Admin);
            List_Admin.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Admin.txt");
            break;
        case 3:
            // Admin.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-3\\output\\Admin.txt", List_Admin);
            // cin.ignore();
            // cout << "Enter the customer ID you want to find " << endl;
            // getline(cin, ID);
            // Admin.SetID(ID);
            // List_Admin.Findinf(Admin);
            // break;
        case 4:
            // Admin.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-3\\output\\Admin.txt", List_Admin);
            // cin.ignore();
            // cout << "Enter the customer ID you want to delete " << endl;
            // getline(cin, ID);
            // Admin.SetID(ID);
            // List_Admin.DeleteDataFromFile(Admin);
            // List_Admin.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-3\\output\\Admin.txt");
            // List_Admin.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-3\\output\\Admin.txt");
            // break;
        case 5:
            // cin.ignore();
            // cout << "Enter the customer ID you want to edit " << endl;
            // getline(cin, ID);
            // Admin.SetID(ID);
            // List_Admin.UpdateBill(Admin);
            // List_Admin.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-3\\output\\Admin.txt");
            // List_Admin.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-3\\output\\Admin.txt");
            // break;
             default:
            break;
        }
        // L.clear();
        // if (choice == 0)
        //     break;
        // system("pause");

    } while (choice != 0);
}

void menu_Add_products_to_inventory()
{
    LinkedList<Product> List_Product;
    LinkedList<Equipment> List_Equipment;
    LinkedList<Book> List_Book;
    Book Book;
    Equipment Equipment;
    Product Product;
    int choice;
    do
    {
        // system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Wellcome Employee"  << " ****             *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Add Book to inventory           |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Add Equipment to inventory      |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Logout                          |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl;
        cout << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 2)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        // system("cls");
        switch (choice)
        {
        case 1:
            cout << "Enter the customer information you want to add " << endl;
            cin.ignore();
            cin >> Book;
            List_Book.AddLast(Book);
            List_Book.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Book.txt");
            break;
        case 2:
            cout << "Enter the customer information you want to add " << endl;
            cin.ignore();
            cin >> Equipment;
            List_Equipment.AddLast(Equipment);
            List_Equipment.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt");
            break;
        default:
            break;
        }
        if (choice == 0)
            break;
        // system("pause");

    } while (choice != 0);
}

void menu_Veiw_Info()
{
    Data<Bill> List_Bill;
    LinkedList<Product> List_Product;
    LinkedList<Customer> List_Customer;
    LinkedList<Book> List_Book;
    LinkedList<Equipment> List_Equipment;
    LinkedList<Employee> List_Employee;
    Product Product;
    Bill Bill;
    Book Book;
    Customer Customer;
    Equipment Equipment;
    Employee Employee;
   // Product Product;
    string ID;
    int choice;
    do
    {
        // system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Wellcome Employee"  << " ****             *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Veiw Info Book           |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Veiw Info Equipment          |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Veiw Info Customer          |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Veiw Info Bill              |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Veiw My Info               |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Logout                      |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl;
        cout << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 3)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        // system("cls");
        switch (choice)
        {
        case 1:
            Book.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Book.txt", List_Book);
            List_Book.Display();
            break;
        case 2:
            Equipment.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt", List_Equipment);
            List_Equipment.Display();
            break;;
        case 3:
            Customer.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt", List_Customer);
            List_Customer.Display();
            break;
        case 4:
        if(List_Bill.empty())
        {
            Bill.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Bill.txt", List_Bill);
        }
            List_Bill.show();
            break;
        case 5:
            Employee.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Employy.txt", List_Employee);
            List_Employee.Display();
            break;
        default:
            break;
        }
        if (choice == 0)
            break;
        // system("pause");

    } while (choice != 0);
}
void menu_Employee(Employee &object2)
{
    Data<Bill> List_Bill;
    LinkedList<Product> List_Product;
    LinkedList<Customer> List_Customer;
    LinkedList<Book> List_Book;
    LinkedList<Equipment> List_Equipment;
    LinkedList<Employee> List_Employee;
    Product Product;
    Bill Bill;
    Book Book;
    Equipment Equipment;
    Employee Employee;
   // Product Product;
    string ID;
    int choice;
    do
    {
        // system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Wellcome Employee" << setw(15) << object2.GetName() << " ****             *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Add products to inventory         |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Make Sales                        |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) View Info                         |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Logout                            |                             *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl;
        cout << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 3)
        {
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        // system("cls");
        switch (choice)
        {
        case 1:
            menu_Add_products_to_inventory();
             break;
        case 2:
            // menu_Veiw_Info();
            //  break;
        case 3:
            menu_Veiw_Info();
             break;
        default:
            break;
        }
        if (choice == 0)
            break;
        // system("pause");

    } while (choice != 0);
}

void menu_admin(Admin &object1)
{
    int choice;
    do
    {
        // system("cls");
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Welcome To Admin " << setw(10) << object1.GetName() << " ****                *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Manager Customer          |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Manager Employee          |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  3) Manager Product           |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  4) Manager Bill              |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  5) Manager Revenue           |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  6) Manager My Info           |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Logout                    |                    *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cin.ignore();
        cout << "Enter Your Choice : ";
        cin >> choice;
        while (choice < 0 || choice > 5)
        {
            cin.ignore();
            cout << "Enter Right Choice : ";
            cin >> choice;
        }
        cout << "\n***********************" << endl;
        system("cls");
        switch (choice)
        {
        case 1:
            // menu_Manager_Customer();
            menu_Manager_Customer();
            break;
        case 2:
            // menu_Manager_Phong_Tro();
            menu_Manager_Employee();
            break;
        case 3:
            // menu_Manager_Dien_Nuoc();
            menu_Manager_Product();
            break;
        case 4:
            // menu_Manager_Payment();
            menu_Manager_Bill();
            break;
        case 5:
            // menu_Manager_Payment();
            menu_Manager_Revenue();
            break;
        case 6:
            // menu_Manager_Payment();
            menu_Manager_My_Info();
            break;
        default:
            break;
        }
        if (choice == 0)
            break;
        system("pause");
    } while (choice != 0);
}

void menu_login()
{
    string user_name, password;
    int choice;

    do
    {
        cout << "\t\t\t*****************************************************************" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t*\t **** Login  ****                                       *" << endl;
        cout << "\t\t\t*\t                                                        *" << endl;
        cout << "\t\t\t* Are You:                                                      *      " << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  1) Admin    |                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  2) Employee |                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*\t|  0) Exit     |                                        *" << endl;
        cout << "			*    	                                                        *" << endl;
        cout << "\t\t\t*****************************************************************" << endl;
        cout << endl;

        cout << "***********************" << endl
             << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Admin admin;
            cin.ignore();
            cout << "Enter Admin: ";
            getline(cin, user_name);
            admin.SetUserName(user_name);

            cout << "Enter Admin Password: ";
            getline(cin, password);
            admin.SetPassWord(password);

            if (admin.login())
            {
                menu_admin(admin);
            }
            else
            {
                cout << "Login failed. Please try again." << endl;
            }
        }
        break;

        case 2:
        {
            Employee employee;
            cin.ignore();
            cout << "Enter Employee: ";
            getline(cin, user_name);
            employee.SetUserName(user_name);

            cout << "Enter Employee Password: ";
            getline(cin, password);
            employee.SetPassWord(password);

            if (employee.login())
            {
                menu_Employee(employee);
            }
            else
            {
                cout << "Login failed. Please try again." << endl;
            }
        }
        break;

        default:
            break;
        }

    } while (choice != 0);
}
int main()
{
   menu_login();
//     Bill p;
// Data<Bill> List_Bill;
// int x;
// while (1)
// {
//    p.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Bill.txt", List_Bill);
//    cout<<"hhh ";
//    cin >> x;
// }
// while (1)
// {
//     // cin.ignore();
//     Bill bill;
// Data<Bill> List_bill;
// cin >> bill;
// List_bill.Add(bill);
// List_bill.show();
// cout <<"kkkk";
// }

// Purchase p;
// cin >> p;


    return 0;
}