#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include "DoHoa.h"
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
// #include "ManageUI.h"

using namespace std;

int main()
{
    // system("cls");
    ManageUI m;
    while (1)
    {
        system("cls");
        vector<string> menuOptions2 = { "ADMIN", "EMPLOYEE", "THOAT" };
        int selectedOption2 = XuLyBanPhim2(menuOptions2);
        if (selectedOption2 == 2)
            break;
        if (selectedOption2 == 0) // CHỦ CỬA HÀNG
        {
            while (1)
            {
                system("cls");
                ToMau(1, 1, "CHU CUA HANG", 240);
                vector<string> menuOptions = { "DANG NHAP", "DANG KI TAI KHOAN", "THOAT" };
                int e = XuLyBanPhim2(menuOptions);
                if (e == 2)
                    break;
                m.ReadFromFile("D:\\C++\\PBL2-6\\output\\Adminlogin.txt");
                if (e == 0) // ĐĂNG NHẬP
                {
                    string username;
                    string password;
                    char ch;
                    cout << "Ten dang nhap:";
                    cin >> username;
                    cout << "Mat khau     :";
                    while (1)
                    {
                        ch = _getch();
                        if (ch == 13)
                            break;

                        else if (ch == 8)
                        {
                            if (!password.empty())
                            {
                                password.pop_back();
                                cout << "\b \b";
                            }
                        }
                        else
                        {
                            password.push_back(ch);
                            cout << "*";
                        }
                    }
                    cout << endl;
                    try
                    {
                        int i = 1;
                        while (1)
                        {
                            if (!m.LogIn(username, password))
                            {
                                cout << "Dang nhap that bai! Hay dang nhap lai." << endl;
                                cout << "Ten dang nhap:";
                                cin >> username;
                                cout << "Mat khau:";
                                while (1)
                                {
                                    ch = _getch();
                                    if (ch == 13)
                                        break;

                                    else if (ch == 8)
                                    {
                                        if (!password.empty())
                                        {
                                            password.pop_back();
                                            cout << "\b \b";
                                        }
                                    }
                                    else
                                    {
                                        password.push_back(ch);
                                        cout << "*";
                                    }
                                }
                                cout << endl;
                                i++;
                            }
                            else
                            {
                                throw string("Dang nhap thanh cong.");
                                break;
                            }
                            if (i >= 5)
                            {
                                cout << "Ban da dang nhap sai qua nhieu lan!" << endl;
                                system("pause");
                                break;
                            }
                        }
                    }
                    catch (string& e)
                    {
                        cout << e << endl;
                        system("pause");
                        system("cls");
                    }
                    Loading();
                    system("cls");
                    while (1)
                    {
                        system("cls");
                        for (int i = 0; i <= 10; i += 2)
                        {
                            Khung(40, 2 + i, 70, 4 + i, 250);
                        }
                        vector<string> menuoptions = { "LAM VIEC VOI KHACH HANG", "LAM VIEC VOI SAN PHAM", "LAM VIEC VOI NHAN VIEN", "LAM VIEC VOI HOA DON", "DOANH THU", "THOAT" };
                        int selectedoption = XuLyBanPhim1(menuoptions);
                        if (selectedoption == 5)
                            break;
                        system("cls");
                        if (selectedoption == 4)
                        {
                            while (1)
                            {
                                system("cls");
                                for (int i = 0; i <= 2; i += 2)
                                {
                                    Khung(40, 2 + i, 75, 4 + i, 250);
                                }
                                vector<string> menuoption = { "KIEM TRA DOANH THU", "THOAT" };
                                int k = XuLyBanPhim1(menuoption);
                                if (k == 1)
                                    break;
                                Data<Bill> List_Bill;
                                Bill bill;
                                string ID;
                                double Revenue = 0;
                                if (k == 0)
                                {
                                    system("cls");
                                    if (List_Bill.empty())
                                    {
                                        bill.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Bill.txt", List_Bill);
                                        for (int i = 0; i < List_Bill.size(); i++)
                                        {
                                            Revenue += List_Bill[i].GetPrice();
                                        }
                                    }

                                    cout << "Revenue of store is " << Revenue << endl;
                                    break;
                                }
                            }
                            system("pause");
                        }
                        if (selectedoption == 0)
                        {
                            while (1)
                            {
                                system("cls");
                                for (int i = 0; i <= 10; i += 2)
                                {
                                    Khung(40, 2 + i, 75, 4 + i, 250);
                                }
                                vector<string> menuoption = { "THEM KHACH HANG", "XOA KHACH HANG", "SUA THONG TIN KHACH HANG", "XUAT THONG TIN KHACH HANG", "TIM THONG TIN KHACH HANG", "THOAT" };
                                int k = XuLyBanPhim1(menuoption);
                                if (k == 5)
                                    break;
                                LinkedList<Customer> List_Customer;
                                Customer Customer;
                                string ID;

                                switch (k)
                                {
                                case 0:
                                    system("cls");
                                    cout << "Enter the customer information you want to add " << endl;
                                    fflush(stdin);
                                    cin >> Customer;
                                    if (Customer.checkIDCustomer(Customer.GetID()))
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        List_Customer.AddLast(Customer);
                                        List_Customer.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Customer.txt");
                                    }
                                    break;

                                case 1:
                                    system("cls");
                                    Customer.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Customer.txt", List_Customer);
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to delete " << endl;
                                    getline(cin, ID);
                                    Customer.SetID(ID);
                                    List_Customer.DeleteDataFromFile(Customer);
                                    List_Customer.ClearFile("D:\\C++\\PBL2-6\\output\\Customer.txt");
                                    List_Customer.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Customer.txt");
                                    break;
                                case 2:
                                    system("cls");
                                    Customer.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Customer.txt", List_Customer);
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to edit " << endl;
                                    getline(cin, ID);
                                    Customer.SetID(ID);
                                    List_Customer.UpdateBill(Customer);
                                    List_Customer.ClearFile("D:\\C++\\PBL2-6\\output\\Customer.txt");
                                    List_Customer.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Customer.txt");
                                    break;
                                case 3:
                                    system("cls");
                                    Customer.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Customer.txt", List_Customer);
                                    List_Customer.Display();
                                    break;

                                case 4:
                                    system("cls");
                                    Customer.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Customer.txt", List_Customer);
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to find " << endl;
                                    getline(cin, ID);
                                    Customer.SetID(ID);
                                    List_Customer.Findinf(Customer);
                                    break;

                                default:
                                    break;
                                }
                                system("pause");
                            }
                        }
                        if (selectedoption == 3)
                        {
                            while (1)
                            {
                                system("cls");
                                for (int i = 0; i <= 10; i += 2)
                                {
                                    Khung(40, 2 + i, 75, 4 + i, 250);
                                }
                                vector<string> menuoption = { "THEM HOA DON", "XOA HOA DON", "SUA THONG TIN HOA DON", "XUAT THONG TIN HOA DON", "TIM THONG TIN HOA DON", "THOAT" };
                                int k = XuLyBanPhim1(menuoption);
                                if (k == 5)
                                    break;
                                Data<Bill> List_Bill;
                                LinkedList<Customer> List_Customer;
                                Bill bill;
                                string ID;

                                switch (k)
                                {
                                case 0:
                                    system("cls");
                                    bill = Bill();
                                    cout << "Enter the customer information you want to add " << endl;
                                    fflush(stdin);
                                    cin >> bill;
                                    // Revenue = bill.Revenue();
                                    List_Bill.Add(bill);
                                    List_Bill.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Bill.txt");
                                    if (bill.GetCustomer().checkIDCustomer(bill.GetCustomer().GetID()))
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        List_Customer.AddLast(bill.GetCustomer());
                                        List_Customer.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Customer.txt");
                                    }
                                    break;

                                case 1:
                                    system("cls");
                                    if (List_Bill.empty())

                                    {
                                        bill.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Bill.txt", List_Bill);
                                    }
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to delete " << endl;
                                    getline(cin, ID);
                                    bill.SetID(ID);
                                    List_Bill.DeleteData(bill);
                                    List_Bill.Data::ClearFile("D:\\C++\\PBL2-6\\output\\Bill.txt");
                                    List_Bill.WriteAllDataToFile("D:\\C++\\PBL2-6\\output\\Bill.txt");
                                    break;
                                case 2:
                                    system("cls");
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to edit " << endl;
                                    getline(cin, ID);
                                    bill.SetID(ID);
                                    List_Bill.UpdateBill(bill);
                                    List_Bill.ClearFile("D:\\C++\\PBL2-6\\output\\Bill.txt");
                                    List_Bill.WriteAllDataToFile("D:\\C++\\PBL2-6\\output\\Bill.txt");
                                    break;

                                case 3:
                                    system("cls");
                                    if (List_Bill.empty())

                                    {
                                        bill.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Bill.txt", List_Bill);
                                    }
                                    List_Bill.show();

                                    break;
                                    // Data<Bill> List_Bill;

                                case 4:
                                    system("cls");
                                    if (List_Bill.empty())

                                    {
                                        bill.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Bill.txt", List_Bill);
                                    }
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to find " << endl;
                                    getline(cin, ID);
                                    bill.SetID(ID);
                                    List_Bill.Find(bill);
                                    break;
                                default:
                                    break;
                                }
                                system("pause");
                            }
                        }
                        if (selectedoption == 2)
                        {
                            while (1)
                            {
                                system("cls");
                                for (int i = 0; i <= 10; i += 2)
                                {
                                    Khung(40, 2 + i, 75, 4 + i, 250);
                                }
                                vector<string> menuoption = { "THEM NHAN VIEN", "XOA NHAN VIEN", "SUA THONG TIN NHAN VIEN", "XUAT THONG TIN NHAN VIEN", "TIM THONG TIN NHAN VIEN", "THOAT" };
                                int k = XuLyBanPhim1(menuoption);
                                if (k == 5)
                                    break;
                                LinkedList<Employee> List_Employee;
                                Employee Employee;
                                string ID;

                                switch (k)
                                {
                                case 0:
                                    system("cls");
                                    cout << "Enter the customer information you want to add " << endl;
                                    fflush(stdin);
                                    cin >> Employee;
                                    List_Employee.AddLast(Employee);
                                    List_Employee.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Employee.txt");
                                    break;

                                case 1:
                                    system("cls");
                                    Employee.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Employee.txt", List_Employee);
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to delete " << endl;
                                    getline(cin, ID);
                                    Employee.SetID(ID);
                                    List_Employee.DeleteDataFromFile(Employee);
                                    List_Employee.ClearFile("D:\\C++\\PBL2-6\\output\\Employee.txt");
                                    List_Employee.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Employee.txt");
                                    break;
                                case 2:
                                    system("cls");
                                    Employee.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Employee.txt", List_Employee);
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to edit " << endl;
                                    getline(cin, ID);
                                    Employee.SetID(ID);
                                    List_Employee.UpdateBill(Employee);
                                    List_Employee.ClearFile("D:\\C++\\PBL2-6\\output\\Employee.txt");
                                    List_Employee.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Employee.txt");
                                    break;

                                case 3:
                                    system("cls");
                                    Employee.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Employee.txt", List_Employee);
                                    List_Employee.Display();
                                    break;
                                case 4:
                                    system("cls");
                                    Employee.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Employee.txt", List_Employee);
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to find " << endl;
                                    getline(cin, ID);
                                    Employee.SetID(ID);
                                    List_Employee.Findinf(Employee);
                                    break;
                                default:
                                    break;
                                }
                                system("pause");
                            }
                        }
                        if (selectedoption == 1)
                        {
                            while (1)
                            {
                                system("cls");
                                for (int i = 0; i <= 4; i += 2)
                                {
                                    Khung(40, 2 + i, 70, 4 + i, 250);
                                }
                                vector<string> menuoption = { "SACH", "DUNG CU HOC TAP", "THOAT" };
                                int option = XuLyBanPhim1(menuoption);
                                if (option == 2)
                                    break;
                                if (option == 0)
                                {
                                    while (1)
                                    {
                                        system("cls");
                                        for (int i = 0; i <= 10; i += 2)
                                        {
                                            Khung(40, 2 + i, 75, 4 + i, 250);
                                        }
                                        vector<string> menuoption1 = { "THEM SACH", "XOA SACH", "SUA THONG TIN SACH", "XUAT THONG TIN SACH", "TIM THONG TIN SACH", "THOAT" };
                                        int k = XuLyBanPhim1(menuoption1);
                                        if (k == 5)
                                            break;
                                        LinkedList<Book> List_Book;
                                        Book Book;
                                        string ID;
                                        switch (k)
                                        {
                                        case 0:

                                            system("cls");
                                            cout << "Enter the customer information you want to add " << endl;
                                            fflush(stdin);
                                            cin >> Book;
                                            if (Book.checkIDBook(Book.GetID()))
                                            {
                                                Book.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Book.txt", List_Book);
                                                Book.UpdateOrAddBook(List_Book);
                                                // List_Book.Display();
                                                List_Book.ClearFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                                List_Book.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                            }
                                            else
                                            {
                                                List_Book.AddLast(Book);
                                                List_Book.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                            }
                                            break;

                                        case 1:
                                            system("cls");
                                            Book.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Book.txt", List_Book);
                                            fflush(stdin);
                                            cout << "Enter the customer ID you want to delete " << endl;
                                            getline(cin, ID);
                                            Book.SetID(ID);
                                            List_Book.DeleteDataFromFile(Book);
                                            List_Book.ClearFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                            List_Book.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                            break;
                                        case 2:
                                            system("cls");
                                            Book.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Book.txt", List_Book);
                                            fflush(stdin);
                                            cout << "Enter the customer ID you want to edit " << endl;
                                            getline(cin, ID);
                                            Book.SetID(ID);
                                            List_Book.UpdateBill(Book);
                                            List_Book.ClearFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                            List_Book.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                            break;

                                        case 3:
                                            system("cls");
                                            Book.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Book.txt", List_Book);
                                            List_Book.Display();
                                            break;
                                        case 4:
                                            system("cls");
                                            Book.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Book.txt", List_Book);
                                            fflush(stdin);
                                            cout << "Enter the customer ID you want to find " << endl;
                                            getline(cin, ID);
                                            Book.SetID(ID);
                                            List_Book.Findinf(Book);
                                            break;

                                        default:
                                            break;
                                        }
                                        system("pause");
                                    }
                                }
                                if (option == 1)
                                {
                                    while (1)
                                    {
                                        system("cls");
                                        for (int i = 0; i <= 10; i += 2)
                                        {
                                            Khung(40, 2 + i, 75, 4 + i, 250);
                                        }
                                        vector<string> menuoption1 = { "THEM DUNG CU", "XOA DUNG CU", "SUA THONG TIN DUNG CU", "XUAT THONG TIN DUNG CU", "TIM THONG TIN DUNG CU", "THOAT" };
                                        int k = XuLyBanPhim1(menuoption1);
                                        if (k == 5)
                                            break;
                                        LinkedList<Equipment> List_Equipment;
                                        Equipment Equipment;
                                        string ID;

                                        switch (k)
                                        {
                                        case 0:
                                            system("cls");
                                            cout << "Enter the customer information you want to add " << endl;
                                            fflush(stdin);
                                            cin >> Equipment;
                                            if (Equipment.checkIDEquipment(Equipment.GetID()))
                                            {
                                                Equipment.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Equipment.txt", List_Equipment);
                                                Equipment.UpdateOrAddEquipment(List_Equipment);
                                                // List_Book.Display();
                                                List_Equipment.ClearFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
                                                List_Equipment.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
                                            }
                                            else
                                            {
                                                List_Equipment.AddLast(Equipment);
                                                List_Equipment.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
                                            }
                                            break;

                                        case 1:
                                            system("cls");
                                            Equipment.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Equipment.txt", List_Equipment);
                                            fflush(stdin);
                                            cout << "Enter the customer ID you want to delete " << endl;
                                            getline(cin, ID);
                                            Equipment.SetID(ID);
                                            List_Equipment.DeleteDataFromFile(Equipment);
                                            List_Equipment.ClearFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
                                            List_Equipment.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
                                            break;
                                        case 2:
                                            system("cls");
                                            Equipment.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Equipment.txt", List_Equipment);
                                            fflush(stdin);
                                            cout << "Enter the customer ID you want to edit " << endl;
                                            getline(cin, ID);
                                            Equipment.SetID(ID);
                                            List_Equipment.UpdateBill(Equipment);
                                            List_Equipment.ClearFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
                                            List_Equipment.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
                                            break;

                                        case 3:
                                            system("cls");
                                            Equipment.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Equipment.txt", List_Equipment);
                                            List_Equipment.Display();
                                            break;
                                        case 4:
                                            system("cls");
                                            Equipment.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Equipment.txt", List_Equipment);
                                            fflush(stdin);
                                            cout << "Enter the customer ID you want to find " << endl;
                                            getline(cin, ID);
                                            Equipment.SetID(ID);
                                            List_Equipment.Findinf(Equipment);
                                            break;

                                        default:
                                            break;
                                        }
                                        system("pause");
                                    }
                                }
                            }
                        }
                    }
                    system("pause");
                }
                if (e == 1) // ĐĂNG KÍ
                {
                    string username;
                    string password;
                    while (1)
                    {
                        cout << "Ten dang nhap:";
                        cin >> username;
                        char ch;
                        if (m.Check(username))
                            cout << "Tai khoan da ton tai! Moi nhap lai." << endl;
                        else
                        {
                            cout << "Mat khau:";
                            while (1)
                            {
                                ch = _getch();
                                if (ch == 13)
                                    break;

                                else if (ch == 8)
                                {
                                    if (!password.empty())
                                    {
                                        password.pop_back();
                                        cout << "\b \b";
                                    }
                                }
                                else
                                {
                                    password.push_back(ch);
                                    cout << "*";
                                }
                            }
                            cout << endl;
                            m.AddUser(username, password);
                            cout << "Dang ki thanh cong!" << endl;
                            m.SaveToFile("Employee.txt");
                            system("pause");
                            break;
                        }
                    }
                }
            }
        }
        if (selectedOption2 == 1) // NHÂN VIÊN
        {
            while (1)
            {
                system("cls");
                ToMau(1, 1, "NHAN VIEN", 240);
                vector<string> menuOptions = { "DANG NHAP", "DANG KI TAI KHOAN", "THOAT" };
                int e = XuLyBanPhim2(menuOptions);
                if (e == 2)
                    break;
                m.ReadFromFile("Employee.txt");
                if (e == 0) // ĐĂNG NHẬP
                {
                    string username;
                    string password;
                    char ch;
                    cout << "Ten dang nhap:";
                    cin >> username;
                    cout << "Mat khau     :";
                    while (1)
                    {
                        ch = _getch();
                        if (ch == 13)
                            break;

                        else if (ch == 8)
                        {
                            if (!password.empty())
                            {
                                password.pop_back();
                                cout << "\b \b";
                            }
                        }
                        else
                        {
                            password.push_back(ch);
                            cout << "*";
                        }
                    }
                    cout << endl;
                    try
                    {
                        int i = 0;
                        while (1)
                        {
                            if (!m.LogIn(username, password))
                            {
                                cout << "Dang nhap that bai! Hay dang nhap lai." << endl;
                                cout << "Ten dang nhap:";
                                cin >> username;
                                cout << "Mat khau:";
                                while (1)
                                {
                                    ch = _getch();
                                    if (ch == 13)
                                        break;

                                    else if (ch == 8)
                                    {
                                        if (!password.empty())
                                        {
                                            password.pop_back();
                                            cout << "\b \b";
                                        }
                                    }
                                    else
                                    {
                                        password.push_back(ch);
                                        cout << "*";
                                    }
                                }
                                cout << endl;
                                i++;
                            }
                            else
                            {
                                throw string("Dang nhap thanh cong.");
                                break;
                            }
                            if (i >= 5)
                            {
                                cout << "Ban da dang nhap sai qua nhieu lan!" << endl;
                                system("pause");
                                exit(0);
                            }
                        }
                    }
                    catch (string& e)
                    {
                        cout << e << endl;
                        system("pause");
                        system("cls");
                    }
                    Loading();
                    system("cls");
                    while (1)
                    {
                        system("cls");
                        for (int i = 0; i <= 6; i += 2)
                        {
                            Khung(40, 2 + i, 70, 4 + i, 250);
                        }
                        vector<string> menuoptions = { "LAM VIEC VOI KHACH HANG", "LAM VIEC VOI SAN PHAM", "LAM VIEC VOI HOA DON", "THOAT" };
                        int selectedoption = XuLyBanPhim1(menuoptions);
                        if (selectedoption == 3)
                            break;
                        if (selectedoption == 0)
                        {
                            while (1)
                            {
                                system("cls");
                                for (int i = 0; i <= 6; i += 2)
                                {
                                    Khung(40, 2 + i, 75, 4 + i, 250);
                                }
                                vector<string> menuoption = { "THEM KHACH HANG", "XUAT THONG TIN KHACH HANG", "TIM THONG TIN KHACH HANG", "THOAT" };
                                int k = XuLyBanPhim1(menuoption);
                                if (k == 3)
                                    break;
                                LinkedList<Customer> List_Customer;
                                Customer Customer;
                                string ID;

                                switch (k)
                                {
                                case 0:
                                    system("cls");
                                    cout << "Enter the customer information you want to add " << endl;
                                    fflush(stdin);
                                    cin >> Customer;
                                    if (Customer.checkIDCustomer(Customer.GetID()))
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        List_Customer.AddLast(Customer);
                                        List_Customer.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Customer.txt");
                                    }
                                    break;

                                case 1:
                                    system("cls");
                                    Customer.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Customer.txt", List_Customer);
                                    List_Customer.Display();
                                    break;
                                case 2:
                                    system("cls");
                                    Customer.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Customer.txt", List_Customer);
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to find " << endl;
                                    getline(cin, ID);
                                    Customer.SetID(ID);
                                    List_Customer.Findinf(Customer);
                                    break;
                                default:
                                    break;
                                }
                                system("pause");
                            }
                        }
                        if (selectedoption == 2)
                        {
                            while (1)
                            {
                                system("cls");
                                for (int i = 0; i <= 10; i += 2)
                                {
                                    Khung(40, 2 + i, 75, 4 + i, 250);
                                }
                                vector<string> menuoption = { "THEM HOA DON", "XOA HOA DON", "SUA THONG TIN HOA DON", "XUAT THONG TIN HOA DON", "TIM THONG TIN HOA DON", "THOAT" };
                                int k = XuLyBanPhim1(menuoption);
                                if (k == 5)
                                    break;
                                Data<Bill> List_Bill;
                                LinkedList<Customer> List_Customer;
                                Bill bill;
                                string ID;

                                switch (k)
                                {
                                case 0:
                                    system("cls");
                                    bill = Bill();
                                    cout << "Enter the customer information you want to add " << endl;
                                    fflush(stdin);
                                    cin >> bill;
                                    // Revenue = bill.Revenue();
                                    List_Bill.Add(bill);
                                    List_Bill.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Bill.txt");
                                    if (bill.GetCustomer().checkIDCustomer(bill.GetCustomer().GetID()))
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        List_Customer.AddLast(bill.GetCustomer());
                                        List_Customer.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Customer.txt");
                                    }
                                    break;
                                    // List_Bill.Clear();
                                    //  Data<Bill> List_Bill;

                                case 1:
                                    system("cls");
                                    if (List_Bill.empty())

                                    {
                                        bill.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Bill.txt", List_Bill);
                                    }
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to delete " << endl;
                                    getline(cin, ID);
                                    bill.SetID(ID);
                                    List_Bill.DeleteData(bill);
                                    List_Bill.Data::ClearFile("D:\\C++\\PBL2-6\\output\\Bill.txt");
                                    List_Bill.WriteAllDataToFile("D:\\C++\\PBL2-6\\output\\Bill.txt");
                                    break;
                                    // Data<Bill> List_Bill;

                                case 2:
                                    system("cls");
                                    fflush(stdin);
                                    if (List_Bill.empty())
                                    {
                                        bill.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Bill.txt", List_Bill);
                                    }
                                    cout << "Enter the customer ID you want to edit " << endl;
                                    getline(cin, ID);
                                    bill.SetID(ID);
                                    List_Bill.UpdateBill(bill);
                                    List_Bill.ClearFile("D:\\C++\\PBL2-6\\output\\Bill.txt");
                                    List_Bill.WriteAllDataToFile("D:\\C++\\PBL2-6\\output\\Bill.txt");
                                    break;
                                case 3:
                                    system("cls");
                                    if (List_Bill.empty())

                                    {
                                        bill.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Bill.txt", List_Bill);
                                    }
                                    List_Bill.show();
                                    break;
                                case 4:
                                    system("cls");
                                    if (List_Bill.empty())

                                    {
                                        bill.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Bill.txt", List_Bill);
                                    }
                                    fflush(stdin);
                                    cout << "Enter the customer ID you want to find " << endl;
                                    getline(cin, ID);
                                    bill.SetID(ID);
                                    List_Bill.Find(bill);
                                    break;

                                default:
                                    break;
                                }
                                system("pause");
                            }
                        }
                        if (selectedoption == 1)
                        {
                            while (1)
                            {
                                system("cls");
                                for (int i = 0; i <= 4; i += 2)
                                {
                                    Khung(40, 2 + i, 70, 4 + i, 250);
                                }
                                vector<string> menuoption = { "SACH", "DUNG CU HOC TAP", "THOAT" };
                                int option = XuLyBanPhim1(menuoption);
                                if (option == 2)
                                    break;
                                if (option == 0)
                                {
                                    while (1)
                                    {
                                        system("cls");
                                        for (int i = 0; i <= 8; i += 2)
                                        {
                                            Khung(40, 2 + i, 75, 4 + i, 250);
                                        }
                                        vector<string> menuoption1 = { "THEM SACH", "SUA THONG TIN SACH", "XUAT THONG TIN SACH", "TIM THONG TIN SACH", "THOAT" };
                                        int k = XuLyBanPhim1(menuoption1);
                                        if (k == 4)
                                            break;
                                        LinkedList<Book> List_Book;
                                        Book Book;
                                        string ID;
                                        switch (k)
                                        {
                                        case 0:
                                            system("cls");

                                            cout << "Enter the customer information you want to add " << endl;
                                            fflush(stdin);
                                            cin >> Book;
                                            if (Book.checkIDBook(Book.GetID()))
                                            {
                                                Book.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Book.txt", List_Book);
                                                Book.UpdateOrAddBook(List_Book);
                                                // List_Book.Display();
                                                List_Book.ClearFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                                List_Book.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                            }
                                            else
                                            {
                                                List_Book.AddLast(Book);
                                                List_Book.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                            }
                                            break;

                                        case 1:
                                            system("cls");
                                            fflush(stdin);
                                            Book.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Book.txt", List_Book);
                                            cout << "Enter the customer ID you want to edit " << endl;
                                            getline(cin, ID);
                                            Book.SetID(ID);
                                            List_Book.UpdateBill(Book);
                                            List_Book.ClearFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                            List_Book.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Book.txt");
                                            break;
                                        case 2:
                                            system("cls");
                                            Book.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Book.txt", List_Book);
                                            List_Book.Display();
                                            break;

                                        case 3:
                                            system("cls");
                                            Book.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Book.txt", List_Book);
                                            fflush(stdin);
                                            cout << "Enter the customer ID you want to find " << endl;
                                            getline(cin, ID);
                                            Book.SetID(ID);
                                            List_Book.Findinf(Book);
                                            break;

                                        default:
                                            break;
                                        }
                                        system("pause");
                                    }
                                }
                                if (option == 1)
                                {
                                    while (1)
                                    {
                                        system("cls");
                                        for (int i = 0; i <= 8; i += 2)
                                        {
                                            Khung(40, 2 + i, 75, 4 + i, 250);
                                        }
                                        vector<string> menuoption1 = { "THEM DUNG CU", "SUA THONG TIN DUNG CU", "XUAT THONG TIN DUNG CU", "TIM THONG TIN DUNG CU", "THOAT" };
                                        int k = XuLyBanPhim1(menuoption1);
                                        if (k == 4)
                                            break;
                                        LinkedList<Equipment> List_Equipment;
                                        Equipment Equipment;
                                        string ID;
                                        switch (k)
                                        {
                                        case 0:
                                            system("cls");
                                            cout << "Enter the customer information you want to add " << endl;
                                            fflush(stdin);
                                            cin >> Equipment;
                                            if (Equipment.checkIDEquipment(Equipment.GetID()))
                                            {
                                                Equipment.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Equipment.txt", List_Equipment);
                                                Equipment.UpdateOrAddEquipment(List_Equipment);
                                                // List_Book.Display();
                                                List_Equipment.ClearFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
                                                List_Equipment.WriteALLDataToFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
                                            }
                                            else
                                            {
                                                List_Equipment.AddLast(Equipment);
                                                List_Equipment.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
                                            }
                                            break;

                                        case 1:
                                            system("cls");
                                            Equipment.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Equipment.txt", List_Equipment);
                                            cout << "Enter the customer information you want to add " << endl;
                                            fflush(stdin);
                                            cin >> Equipment;
                                            List_Equipment.AddLast(Equipment);
                                            List_Equipment.WriteDataToFile("D:\\C++\\PBL2-6\\output\\Equipment.txt");
                                            break;
                                        case 2:
                                            system("cls");
                                            Equipment.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Equipment.txt", List_Equipment);
                                            List_Equipment.Display();
                                            break;

                                        case 3:
                                            system("cls");
                                            Equipment.ReadDataFromFile("D:\\C++\\PBL2-6\\output\\Equipment.txt", List_Equipment);
                                            fflush(stdin);
                                            cout << "Enter the customer ID you want to find " << endl;
                                            getline(cin, ID);
                                            Equipment.SetID(ID);
                                            List_Equipment.Findinf(Equipment);
                                            break;

                                        default:
                                            break;
                                        }
                                        system("pause");
                                    }
                                }
                            }
                        }
                    }

                    system("pause");
                }
                if (e == 1) // ĐĂNG KÍ
                {
                    string username;
                    string password;
                    while (1)
                    {
                        cout << "Ten dang nhap:";
                        cin >> username;
                        char ch;
                        if (m.Check(username))
                            cout << "Tai khoan da ton tai! Moi nhap lai." << endl;
                        else
                        {
                            cout << "Mat khau:";
                            while (1)
                            {
                                ch = _getch();
                                if (ch == 13)
                                    break;

                                else if (ch == 8)
                                {
                                    if (!password.empty())
                                    {
                                        password.pop_back();
                                        cout << "\b \b";
                                    }
                                }
                                else
                                {
                                    password.push_back(ch);
                                    cout << "*";
                                }
                            }
                            cout << endl;
                            m.AddUser(username, password);
                            cout << "Dang ki thanh cong!" << endl;
                            m.SaveToFile("Employee.txt");
                            system("pause");
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}



