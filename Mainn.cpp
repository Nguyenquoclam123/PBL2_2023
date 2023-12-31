
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
	system("cls");
	ManageUI m;
	vector<string> menuOptions2 = {"ADMIN", "EMPLOYEE"};
	int selectedOption2 = XuLyBanPhim2(menuOptions2);
	if (selectedOption2 == 1) // CHỦ CỬA HÀNG
	{
		ToMau(1, 1, "CHU CUA HANG", 240);
		vector<string> menuOptions = {"DANG NHAP", "DANG KI TAI KHOAN"};
		int e = XuLyBanPhim2(menuOptions);
		m.ReadFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Adminlogin.txt");
		if (e == 1) // ĐĂNG NHẬP
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
						exit(0);
					}
				}
			}
			catch (string &e)
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
				for (int i = 0; i <= 8; i += 2)
				{
					Khung(40, 2 + i, 70, 4 + i, 250);
				}
				vector<string> menuoptions = {"LAM VIEC VOI KHACH HANG", "LAM VIEC VOI SAN PHAM", "LAM VIEC VOI NHAN VIEN", "LAM VIEC VOI HOA DON", "THOAT"};
				int selectedoption = XuLyBanPhim1(menuoptions);
				if (selectedoption == 4)
					exit(0);
				system("cls");
				if (selectedoption == 0)
				{
					for (int i = 0; i <= 8; i += 2)
					{
						Khung(40, 2 + i, 75, 4 + i, 250);
					}
					vector<string> menuoption = {"THEM KHACH HANG", "XOA KHACH HANG", "SUA THONG TIN KHACH HANG", "XUAT THONG TIN KHACH HANG", "TIM THONG TIN KHACH HANG"};
					int k = XuLyBanPhim1(menuoption);
					// if();
					LinkedList<Customer> List_Customer;
					Customer Customer;
					string ID;

					switch (k)
					{
					case 0:
						cout << "Enter the customer information you want to add " << endl;
						cin.ignore();
						cin >> Customer;
						List_Customer.AddLast(Customer);
						List_Customer.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt");
						break;

					case 1:
						Customer.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt", List_Customer);
						cin.ignore();
						cout << "Enter the customer ID you want to delete " << endl;
						getline(cin, ID);
						Customer.SetID(ID);
						List_Customer.DeleteDataFromFile(Customer);
						List_Customer.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt");
						List_Customer.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt");
						break;
					case 2:
						cin.ignore();
						cout << "Enter the customer ID you want to edit " << endl;
						getline(cin, ID);
						Customer.SetID(ID);
						List_Customer.UpdateBill(Customer);
						List_Customer.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt");
						List_Customer.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt");
						break;
					case 3:
						Customer.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt", List_Customer);
						List_Customer.Display();
						break;

					case 4:
						Customer.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt", List_Customer);
						cin.ignore();
						cout << "Enter the customer ID you want to find " << endl;
						getline(cin, ID);
						Customer.SetID(ID);
						List_Customer.Findinf(Customer);
						break;

					default:
						break;
					}
				}
				if (selectedoption == 3)
				{
					for (int i = 0; i <= 8; i += 2)
					{
						Khung(40, 2 + i, 75, 4 + i, 250);
					}
					vector<string> menuoption = {"THEM HOA DON", "XOA HOA DON", "SUA THONG TIN HOA DON", "XUAT THONG TIN HOA DON", "TIM THONG TIN HOA DON"};
					int k = XuLyBanPhim1(menuoption);
					// if();
					Data<Bill> List_Bill;
					LinkedList<Customer> List_Customer;
					Bill bill;
					string ID;

					switch (k)
					{
					case 0:
						bill = Bill();
						cout << "Enter the customer information you want to add " << endl;
						cin.ignore();
						cin >> bill;
						// Revenue = bill.Revenue();
						List_Bill.Add(bill);
						List_Bill.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt");
						List_Customer.AddLast(bill.GetCustomer());
						List_Customer.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt");
						break;
						// List_Bill.Clear();
						//  Data<Bill> List_Bill;

					case 1:
						if (List_Bill.empty())

						{
							bill.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt", List_Bill);
						}
						cin.ignore();
						cout << "Enter the customer ID you want to delete " << endl;
						getline(cin, ID);
						bill.SetID(ID);
						List_Bill.DeleteData(bill);
						List_Bill.Data::ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt");
						List_Bill.WriteAllDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt");
						break;
						// Data<Bill> List_Bill;

					case 2:
						cin.ignore();
						cout << "Enter the customer ID you want to edit " << endl;
						getline(cin, ID);
						bill.SetID(ID);
						List_Bill.UpdateBill(bill);
						List_Bill.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt");
						List_Bill.WriteAllDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt");
						break;

						// Data<Bill> List_Bill;

					case 3:
						if (List_Bill.empty())

						{
							bill.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt", List_Bill);
						}
						List_Bill.show();

						break;
						// Data<Bill> List_Bill;

					case 4:
						if (List_Bill.empty())

						{
							bill.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt", List_Bill);
						}
						cin.ignore();
						cout << "Enter the customer ID you want to find " << endl;
						getline(cin, ID);
						bill.SetID(ID);
						List_Bill.Find(bill);
						break;
						// Data<Bill> List_Bill;

					// case 6:
					// cout << "Enter Room ID: ";
					// cin >> ID;
					// customer::change_user_name(ID);
					// break;
					default:
						break;
					}
				}
				if (selectedoption == 2)
				{
					for (int i = 0; i <= 8; i += 2)
					{
						Khung(40, 2 + i, 75, 4 + i, 250);
					}
					vector<string> menuoption = {"THEM NHAN VIEN", "XOA NHAN VIEN", "SUA THONG TIN NHAN VIEN", "XUAT THONG TIN NHAN VIEN", "TIM THONG TIN NHAN VIEN"};
					int k = XuLyBanPhim1(menuoption);
					// if();
					LinkedList<Employee> List_Employee;
					Employee Employee;
					string ID;

					switch (k)
					{
					case 0:
						cout << "Enter the customer information you want to add " << endl;
						cin.ignore();
						cin >> Employee;
						List_Employee.AddLast(Employee);
						List_Employee.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Employee.txt");
						break;

					case 1:
						Employee.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Employee.txt", List_Employee);
						cin.ignore();
						cout << "Enter the customer ID you want to delete " << endl;
						getline(cin, ID);
						Employee.SetID(ID);
						List_Employee.DeleteDataFromFile(Employee);
						List_Employee.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Employee.txt");
						List_Employee.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Employee.txt");
						break;
					case 2:
						cin.ignore();
						cout << "Enter the customer ID you want to edit " << endl;
						getline(cin, ID);
						Employee.SetID(ID);
						List_Employee.UpdateBill(Employee);
						List_Employee.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Employee.txt");
						List_Employee.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Employee.txt");
						break;

					case 3:
						Employee.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Employee.txt", List_Employee);
						List_Employee.Display();
						break;
					case 4:
						Employee.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Employee.txt", List_Employee);
						cin.ignore();
						cout << "Enter the customer ID you want to find " << endl;
						getline(cin, ID);
						Employee.SetID(ID);
						List_Employee.Findinf(Employee);
						break;
					// case 6:
					// cout << "Enter Room ID: ";
					// cin >> ID;
					// customer::change_user_name(ID);
					// break;
					default:
						break;
					}
				}
				if (selectedoption == 1)
				{
					for (int i = 0; i <= 2; i += 2)
					{
						Khung(40, 2 + i, 70, 4 + i, 250);
					}
					vector<string> menuoption = {"SACH", "DUNG CU HOC TAP"};
					int option = XuLyBanPhim1(menuoption);
					if (option == 0)
					{
						system("cls");
						for (int i = 0; i <= 8; i += 2)
						{
							Khung(40, 2 + i, 75, 4 + i, 250);
						}
						vector<string> menuoption1 = {"THEM SACH", "XOA SACH", "SUA THONG TIN SACH", "XUAT THONG TIN SACH", "TIM THONG TIN SACH"};
						int k = XuLyBanPhim1(menuoption1);
						// if();
						LinkedList<Book> List_Book;
						Book Book;
						string ID;
						switch (k)
						{
						case 0:
							cout << "Enter the customer information you want to add " << endl;
							cin.ignore();
							cin >> Book;
							List_Book.AddLast(Book);
							List_Book.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt");
							break;

						case 1:
							Book.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt", List_Book);
							cin.ignore();
							cout << "Enter the customer ID you want to delete " << endl;
							getline(cin, ID);
							Book.SetID(ID);
							List_Book.DeleteDataFromFile(Book);
							List_Book.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt");
							List_Book.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt");
							break;
						case 2:
							cin.ignore();
							cout << "Enter the customer ID you want to edit " << endl;
							getline(cin, ID);
							Book.SetID(ID);
							List_Book.UpdateBill(Book);
							List_Book.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt");
							List_Book.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt");
							break;

						case 3:
							Book.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt", List_Book);
							List_Book.Display();
							break;
						case 4:
							Book.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt", List_Book);
							cin.ignore();
							cout << "Enter the customer ID you want to find " << endl;
							getline(cin, ID);
							Book.SetID(ID);
							List_Book.Findinf(Book);
							break;
						// case 6:
						// cout << "Enter Room ID: ";
						// cin >> ID;
						// customer::change_user_name(ID);
						// break;
						default:
							break;
						}
					}
				// }
				if (option == 1)
				{
					system("cls");
					for (int i = 0; i <= 8; i += 2)
					{
						Khung(40, 2 + i, 75, 4 + i, 250);
					}
					vector<string> menuoption1 = {"THEM DUNG CU", "XOA DUNG CU", "SUA THONG TIN DUNG CU", "XUAT THONG TIN DUNG CU", "TIM THONG TIN DUNG CU"};
					int k = XuLyBanPhim1(menuoption1);
					// if();
					LinkedList<Equipment> List_Equipment;
					Equipment Equipment;
					string ID;

					switch (k)
					{
					case 0:
						cout << "Enter the customer information you want to add " << endl;
						cin.ignore();
						cin >> Equipment;
						List_Equipment.AddLast(Equipment);
						List_Equipment.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt");
						break;

					case 1:
						Equipment.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt", List_Equipment);
						cin.ignore();
						cout << "Enter the customer ID you want to delete " << endl;
						getline(cin, ID);
						Equipment.SetID(ID);
						List_Equipment.DeleteDataFromFile(Equipment);
						List_Equipment.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt");
						List_Equipment.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt");
						break;
					case 2:
						cin.ignore();
						cout << "Enter the customer ID you want to edit " << endl;
						getline(cin, ID);
						Equipment.SetID(ID);
						List_Equipment.UpdateBill(Equipment);
						List_Equipment.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt");
						List_Equipment.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt");
						break;

					case 3:
						Equipment.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt", List_Equipment);
						List_Equipment.Display();
						break;
					case 4:
						Equipment.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt", List_Equipment);
						cin.ignore();
						cout << "Enter the customer ID you want to find " << endl;
						getline(cin, ID);
						Equipment.SetID(ID);
						List_Equipment.Findinf(Equipment);
						break;
					// case 6:
					// cout << "Enter Room ID: ";
					// cin >> ID;
					// customer::change_user_name(ID);
					// break;
					default:
						break;
					}
				}
			}
			getchar();
		}
	}
	if (e == 0) // ĐĂNG KÍ
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
				m.SaveToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Adminlogin.txt");
				system("pause");
				break;
			}
		}
	}
}
if (selectedOption2 == 0) // NHÂN VIÊN
{
	ToMau(1, 1, "NHAN VIEN", 240);
	vector<string> menuOptions = {"DANG NHAP", "DANG KI TAI KHOAN"};
	int e = XuLyBanPhim2(menuOptions);
	m.ReadFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Employeelogin.txt");
	if (e == 1) // ĐĂNG NHẬP
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
		catch (string &e)
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
			for (int i = 0; i <= 4; i += 2)
			{
				Khung(40, 2 + i, 70, 4 + i, 250);
			}
			vector<string> menuoptions = {"LAM VIEC VOI KHACH HANG", "LAM VIEC VOI SAN PHAM", "LAM VIEC VOI HOA DON"};
			int selectedoption = XuLyBanPhim1(menuoptions);
			system("cls");
			if (selectedoption == 0)
			{
				for (int i = 0; i <= 4; i += 2)
				{
					Khung(40, 2 + i, 75, 4 + i, 250);
				}
				vector<string> menuoption = {"THEM KHACH HANG", "XUAT THONG TIN KHACH HANG", "TIM THONG TIN KHACH HANG"};
				int k = XuLyBanPhim1(menuoption);
				// if();
				LinkedList<Customer> List_Customer;
				Customer Customer;
				string ID;

				switch (k)
				{
				case 0:
					cout << "Enter the customer information you want to add " << endl;
					cin.ignore();
					cin >> Customer;
					List_Customer.AddLast(Customer);
					List_Customer.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt");
					break;

				case 1:
					Customer.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt", List_Customer);
					List_Customer.Display();
					break;
				case 2:
					Customer.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt", List_Customer);
					cin.ignore();
					cout << "Enter the customer ID you want to find " << endl;
					getline(cin, ID);
					Customer.SetID(ID);
					List_Customer.Findinf(Customer);
					break;
					// case 3:
					// 	Customer.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt", List_Customer);
					// 	cin.ignore();
					// 	cout << "Enter the customer ID you want to delete " << endl;
					// 	getline(cin, ID);
					// 	Customer.SetID(ID);
					// 	List_Customer.DeleteDataFromFile(Customer);
					// 	List_Customer.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt");
					// 	List_Customer.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt");
					// 	break;

					// case 4:
					// 	cin.ignore();
					// 	cout << "Enter the customer ID you want to edit " << endl;
					// 	getline(cin, ID);
					// 	Customer.SetID(ID);
					// 	List_Customer.UpdateBill(Customer);
					// 	List_Customer.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt");
					// 	List_Customer.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Customer.txt");
					// 	break;

				default:
					break;
				}
			}
			if (selectedoption == 2)
			{
				for (int i = 0; i <= 8; i += 2)
				{
					Khung(40, 2 + i, 75, 4 + i, 250);
				}
				vector<string> menuoption = {"THEM HOA DON", "XOA HOA DON", "SUA THONG TIN HOA DON", "XUAT THONG TIN HOA DON", "TIM THONG TIN HOA DON"};
				int k = XuLyBanPhim1(menuoption);
				// if();
				Data<Bill> List_Bill;
				LinkedList<Customer> List_Customer;
				Bill bill;
				string ID;

				switch (k)
				{
				case 0:
					bill = Bill();
					cout << "Enter the customer information you want to add " << endl;
					cin.ignore();
					cin >> bill;
					// Revenue = bill.Revenue();
					List_Bill.Add(bill);
					List_Bill.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt");
					List_Customer.AddLast(bill.GetCustomer());
					List_Customer.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Customer.txt");
					break;
					// List_Bill.Clear();
					//  Data<Bill> List_Bill;

				case 1:
					if (List_Bill.empty())

					{
						bill.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt", List_Bill);
					}
					cin.ignore();
					cout << "Enter the customer ID you want to delete " << endl;
					getline(cin, ID);
					bill.SetID(ID);
					List_Bill.DeleteData(bill);
					List_Bill.Data::ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt");
					List_Bill.WriteAllDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt");
					break;
					// Data<Bill> List_Bill;

				case 2:
					cin.ignore();
					cout << "Enter the customer ID you want to edit " << endl;
					getline(cin, ID);
					bill.SetID(ID);
					List_Bill.UpdateBill(bill);
					List_Bill.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt");
					List_Bill.WriteAllDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt");
					break;

					// Data<Bill> List_Bill;

				case 3:
					if (List_Bill.empty())

					{
						bill.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt", List_Bill);
					}
					List_Bill.show();

					break;
					// Data<Bill> List_Bill;

				case 4:
					if (List_Bill.empty())

					{
						bill.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Bill.txt", List_Bill);
					}
					cin.ignore();
					cout << "Enter the customer ID you want to find " << endl;
					getline(cin, ID);
					bill.SetID(ID);
					List_Bill.Find(bill);
					break;
					// Data<Bill> List_Bill;

				// case 6:
				// cout << "Enter Room ID: ";
				// cin >> ID;
				// customer::change_user_name(ID);
				// break;
				default:
					break;
				}
			}
			if (selectedoption == 1)
			{
				for (int i = 0; i <= 2; i += 2)
				{
					Khung(40, 2 + i, 70, 4 + i, 250);
				}
				vector<string> menuoption = {"SACH", "DUNG CU HOC TAP"};
				int option = XuLyBanPhim1(menuoption);
				if (option == 0)
				{
					system("cls");
					for (int i = 0; i <= 6; i += 2)
					{
						Khung(40, 2 + i, 75, 4 + i, 250);
					}
					vector<string> menuoption1 = {"THEM SACH", "SUA THONG TIN SACH", "XUAT THONG TIN SACH", "TIM THONG TIN SACH"};
					int k = XuLyBanPhim1(menuoption1);
					// if();
					LinkedList<Book> List_Book;
					Book Book;
					string ID;
					switch (k)
					{
					case 0:
						cout << "Enter the customer information you want to add " << endl;
						cin.ignore();
						cin >> Book;
						List_Book.AddLast(Book);
						List_Book.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt");
						break;

					case 1:
						cin.ignore();
						cout << "Enter the customer ID you want to edit " << endl;
						getline(cin, ID);
						Book.SetID(ID);
						List_Book.UpdateBill(Book);
						List_Book.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt");
						List_Book.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt");
						break;
					case 2:
						Book.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt", List_Book);
						List_Book.Display();
						break;

					case 3:
						Book.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Book.txt", List_Book);
						cin.ignore();
						cout << "Enter the customer ID you want to find " << endl;
						getline(cin, ID);
						Book.SetID(ID);
						List_Book.Findinf(Book);
						break;
					// case 4:

					// case 6:
					// cout << "Enter Room ID: ";
					// cin >> ID;
					// customer::change_user_name(ID);
					// break;
					default:
						break;
					}
				}
				if (option == 1)
				{
					system("cls");
					for (int i = 0; i <= 6; i += 2)
					{
						Khung(40, 2 + i, 75, 4 + i, 250);
					}
					vector<string> menuoption1 = {"THEM DUNG CU", "SUA THONG TIN DUNG CU", "XUAT THONG TIN DUNG CU", "TIM THONG TIN DUNG CU"};
					int k = XuLyBanPhim1(menuoption1);
					// if();
					LinkedList<Equipment> List_Equipment;
					Equipment Equipment;
					string ID;
					switch (k)
					{
					case 0:
						cout << "Enter the customer information you want to add " << endl;
						cin.ignore();
						cin >> Equipment;
						List_Equipment.AddLast(Equipment);
						List_Equipment.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt");
						break;

					case 1:
						cout << "Enter the customer information you want to add " << endl;
						cin.ignore();
						cin >> Equipment;
						List_Equipment.AddLast(Equipment);
						List_Equipment.WriteDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt");
						break;
					case 2:
						Equipment.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt", List_Equipment);
						List_Equipment.Display();
						break;

					case 3:
						Equipment.ReadDataFromFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Equipment.txt", List_Equipment);
						cin.ignore();
						cout << "Enter the customer ID you want to find " << endl;
						getline(cin, ID);
						Equipment.SetID(ID);
						List_Equipment.Findinf(Equipment);
						break;
					// case 4:
					// 	cin.ignore();
					// 	cout << "Enter the customer ID you want to edit " << endl;
					// 	getline(cin, ID);
					// 	Equipment.SetID(ID);
					// 	List_Equipment.UpdateBill(Equipment);
					// 	List_Equipment.ClearFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt");
					// 	List_Equipment.WriteALLDataToFile("C:\\Users\\Admin\\Desktop\\PBL2-4\\output\\Equipment.txt");
					// 	break;
					// case 6:
					// cout << "Enter Room ID: ";
					// cin >> ID;
					// customer::change_user_name(ID);
					// break;
					default:
						break;
					}
				}
				getchar();
			}
		}
		if (e == 0) // ĐĂNG KÍ
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
					m.SaveToFile("C:\\Users\\Admin\\Desktop\\PBL2-6\\output\\Employeelogin.txt");
					system("pause");
					break;
				}
			}
		}
	}
	return 0;
}
}
