#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <vector>
#include <cstdlib>
#include "Manage.h"
using namespace std;

// Hàm thay ð?i kích c? c?a khung cmd v?i tham s? truy?n vào là chi?u cao, chi?u r?ng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Hàm d?ch chuy?n con tr? ð?n t?a ð? x, y.
void gotoxy(int x, int y) {
	HANDLE hConsoleOutput;
	COORD CursorPosition;

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CursorPosition.X = x;
	CursorPosition.Y = y;

	SetConsoleCursorPosition(hConsoleOutput, CursorPosition);
}

// Hàm xóa màn h?nh.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void XoaManHinh2()
{
	gotoxy(1,1);
	for(int i=1; i<=24; i++)
		{
			for(int j=1; j<=90; j++)
				cout<<" ";
			gotoxy(1,i);
		}
}

// Hàm l?y Key t? bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => b?t s? ki?n phím Esc */ 

// Hàm t? vi?t
void ToMau(int x, int y, string a, int color) // x, y là t?a ð? con tr? c?n nh?y ð?n ð? vi?t, a là chu?i c?n truy?n vào, color là màu truy?n vào.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
}

void Khung(int x0, int y0, int x, int y, int c)
// làm khung hình ch? nh?t t?a d? d?u (x0,y0), t?a d? cu?i (x,y) v?i màu c 
{
	textcolor(c);
	gotoxy(x0,y0);
	for(int i=x0; i<=x; i++)
		printf("%c",196);
		//cout<<'196';
	gotoxy(x0,y);
	for(int i=x0; i<=x; i++)
		printf("%c",196);
		//cout<<'196';
	for(int i=y0+1; i<=y-1; i++)
	{
		gotoxy(x0,i);
		printf("%c",179);
		//cout<<'179';
	}
	for(int i=y0+1; i<=y-1; i++)
	{
		gotoxy(x,i);
		printf("%c",179);
		//cout<<'179';
	}
	gotoxy(x0,y0);
	printf("%c",218);
	gotoxy(x0,y);
	printf("%c",192);
	gotoxy(x,y);
	printf("%c",217);
	gotoxy(x,y0);
	printf("%c",191);
	textcolor(7);
}

void KhungDSLK(int x, int y)
{
	//Khung(3,5,8,7,14);
	Khung(x,y,x+6,y+2,14);
  	//gotoxy(9,6);
	textcolor(14);
	gotoxy(x+7,y+1);
	printf("%c",45);
	printf("%c",45);
	printf("%c",26);
} 

void XoaKhungDSLK(int x, int y)
{
	for(int i=y; i<=y+2; i++)
		{
			gotoxy(x,i);
			cout<<"          ";
		}
}

void KhungMaTran(int M)
{
	textcolor(14);
	gotoxy(4,3);
	for(int i=1; i<=M+2; i++)
		{
			gotoxy(4,2+i);
			printf("%c",179);
			gotoxy(15+6*(M-1),2+i);
			printf("%c",179);
		}
	for(int i=2; i<=M+1; i++)
		{
			gotoxy(7+6*(M-1),2+i);
			printf("%c",179);
		}
	gotoxy(4,3);
	printf("%c",218);//goc tren trai
	gotoxy(4,M+4);
	printf("%c",192);//goc duoi trai
	gotoxy(15+6*(M-1),M+4);
	printf("%c",217);//goc duoi phai
	gotoxy(15+6*(M-1),3);
	printf("%c",191);//goc tren phai
	textcolor(7);
}

void Menu(int x,int y)
{
	gotoxy(x, y);
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 4)
		{
			for (int j = 0; j < 31; j++)
			{
				if (j == 0 || j == 30)
				{
					gotoxy(x + j, y+i);
					cout << "+";
				}
				else
				{
					gotoxy(x+j, y);
					cout << "-";
				}
			}
			cout << endl;
			if (i == 4)
			{
				gotoxy(x, y + i);
				for (int j = 1; j < 30; j++)
				{
					gotoxy(x + j, y);
					cout << "-";
				}	
			}
		}
		else
		{
			for (int j = 0; j < 31; j++)
			{
				if (j == 0 || j == 30)
				{
					gotoxy(x+j, y + i);
					cout << "|";
				}
				else
				{
					gotoxy(x+j, y );
					cout << " ";
				}
			}
			cout << endl;
		}
	}
}

void KhungMenu(int x, int y)
{
	Menu(x, y);
	ToMau(x + 10, y + 2, "MENU", 250);
	Menu(x , y + 5);
	ToMau(x + 4, y + 7, "LAM VIEC VOI HOA DON", 250);
	Menu(x, y+10);
	ToMau(x + 3, y + 12, "LAM VIEC VOI KHACH HANG", 250);
	Menu(x, y + 15);
	ToMau(x + 4, y + 17, "LAM VIEC VOI NHAN VIEN", 250);
	Menu(x, y+20);
	ToMau(x + 4, y + 22, "LAM VIEC VOI SAN PHAM", 250);	
}

bool TrongKhung(int mouseX, int mouseY, int x0, int y0, int x, int y) {
	return (mouseX >= x0 && mouseX <= x && mouseY >= y0 && mouseY <= y);
}

//2 hàm này để vẽ MENU
void VeLaiMenu1(int x, int y, const vector<string>& menuOptions, int selectedOption) 
{
	ToMau(50, 1, "===MENU===", 240);
	for (int i = 0; i < menuOptions.size(); i++) {
		gotoxy(x, y + 2*i+1);
		textcolor((i == selectedOption) ? 12 : 240); // Màu 12 là màu đỏ
		cout << menuOptions[i] << endl;
	}
}

int XuLyBanPhim1(const vector<string>& menuOptions) {
	int selectedOption = 0;

	VeLaiMenu1(45, 2, menuOptions, selectedOption);

	while (true) {
		char key = _getch(); // Đọc một ký tự từ bàn phím mà không hiển thị nó trên màn hình

		switch (key) {
		case 72: // Nút mũi tên lên
			selectedOption = (selectedOption - 1 + menuOptions.size()) % menuOptions.size();
			VeLaiMenu1(45, 2, menuOptions, selectedOption);
			break;
		case 80: // Nút mũi tên xuống
			selectedOption = (selectedOption + 1) % menuOptions.size();
			VeLaiMenu1(45, 2, menuOptions, selectedOption);
			break;
		case 13: // Nút Enter
			textcolor(7);
			return selectedOption;
		default:
			break;
		}
	}
}

// 2 hàm này để vẽ ra giao diện UI
void VeLaiMenu2(int x, int y, const vector<string>& menuOptions, int selectedOption)
{
	for (int i = 0; i < menuOptions.size(); i++) {
		gotoxy(x, y + i);
		textcolor((i == selectedOption) ? 240 : 12); // Màu 12 là màu đỏ
		cout << menuOptions[i] << endl;
	}
}

int XuLyBanPhim2(const vector<string>& menuOptions) {
	int selectedOption = 0;

	VeLaiMenu2(50, 2, menuOptions, selectedOption);

	while (true) {
		char key = _getch(); // Đọc một ký tự từ bàn phím mà không hiển thị nó trên màn hình

		switch (key) {
		case 72: // Nút mũi tên lên
			selectedOption = (selectedOption - 1 + menuOptions.size()) % menuOptions.size();
			VeLaiMenu2(50, 2, menuOptions, selectedOption);
			break;
		case 80: // Nút mũi tên xuống
			selectedOption = (selectedOption + 1) % menuOptions.size();
			VeLaiMenu2(50, 2, menuOptions, selectedOption);
			break;
		case 13: // Nút Enter
			textcolor(7);
			return selectedOption;
		default:
			break;
		}
	}
}

void updateLoadingBar(int percentage) {
	// L?y handle c?a c?a s? console
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// L?y kích thu?c c?a s? console
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	// Tính toán s? lu?ng ký t? c?n in d? t?o thanh tr?ng thái
	int barWidth = consoleWidth - 10; // Gi? s? thanh tr?ng thái chi?m 10 ký t?
	int progress = (int)((percentage / 100.0) * barWidth);
	int remaining = barWidth - progress;

	// Di chuy?n con tr? d?n v? trí b?t d?u thanh tr?ng thái
	COORD cursorPos;
	cursorPos.X = 5;
	cursorPos.Y = csbi.srWindow.Top + 1; // V? trí thanh tr?ng thái ? dòng th? hai
	SetConsoleCursorPosition(hConsole, cursorPos);

	// In ra thanh tr?ng thái
	std::cout << "[";
	for (int i = 0; i < progress; i += 5) {
		std::cout << "=";
	}
	for (int i = 0; i < remaining; i += 5) {
		std::cout << " ";
	}
	std::cout << "] " << percentage << "%";

	// Di chuy?n con tr? d?n cu?i c?a s? console
	cursorPos.X = 0;
	cursorPos.Y = csbi.srWindow.Bottom;
	SetConsoleCursorPosition(hConsole, cursorPos);
}
void Loading()
{
	for (int i = 0; i <= 100; i +=4)
	{
		textcolor(i);
		updateLoadingBar(i);
		Sleep(80); // Delay d? th?y rõ s? thay d?i
	}
	textcolor(7);
}

//void UI()
//{
//	ManageUI m;
//	vector<string> menuOptions2 = { "ADMIN","EMPLOYEE" };
//	XuLyBanPhim2(menuOptions2);
//	int selectedOption2 = XuLyBanPhim2(menuOptions2);
//	if (selectedOption2 == 1) // chủ cửa hàng
//	{
//		ToMau(1, 1, "CHU CUA HANG", 240);
//		vector<string> menuOptions = { "DANG NHAP","DANG KI TAI KHOAN" };
//		XuLyBanPhim2(menuOptions);
//		int e = XuLyBanPhim2(menuOptions);
//		m.ReadFromFile("Admin.txt");
//		if (e == 1) // đăng nhập
//		{
//			system("cls");
//			string username;
//			string password;
//			char ch;
//			cout << "Ten dang nhap:"; cin >> username;
//			cout << "Mat khau     :";
//			while (1) // hàm xử lý mật khẩu(bảo mật)
//			{
//				ch = _getch();
//				if (ch == 13) break;
//
//				else if (ch == 8)
//				{
//					if (!password.empty())
//					{
//						password.pop_back();
//						cout << "\b \b";
//					}
//				}
//				else
//				{
//					password.push_back(ch);
//					cout << "*";
//				}
//			}
//			cout << endl;
//			try
//			{
//				int i = 1;
//				while (1)
//				{
//					if (!m.LogIn(username, password))
//					{
//						cout << "Dang nhap that bai! Hay dang nhap lai." << endl;
//						cout << "Ten dang nhap:"; cin >> username;
//						cout << "Mat khau:";
//						while (1)
//						{
//							ch = _getch();
//							if (ch == 13) break;
//
//							else if (ch == 8)
//							{
//								if (!password.empty())
//								{
//									password.pop_back();
//									cout << "\b \b";
//								}
//							}
//							else
//							{
//								password.push_back(ch);
//								cout << "*";
//							}
//						}
//						cout << endl;
//						i++;
//					}
//					else
//					{
//						throw string("Dang nhap thanh cong.");
//						break;
//					}
//					if (i >= 5)
//					{
//						cout << "Ban da dang nhap sai qua nhieu lan!" << endl;
//						system("pause");
//						break;
//					}
//				}
//			}
//			catch (string& e)
//			{
//				cout << e << endl;
//				system("pause");
//			}
//		}
//		if (e == 0) //đăng kí
//		{
//			string username;
//			string password;
//			while (1)
//			{
//				cout << "Ten dang nhap:"; cin >> username;
//				char ch;
//				if (m.Check(username)) cout << "Tai khoan da ton tai! Moi nhap lai." << endl;
//				else
//				{
//					cout << "Mat khau:";
//					while (1)
//					{
//						ch = _getch();
//						if (ch == 13) break;
//
//						else if (ch == 8)
//						{
//							if (!password.empty())
//							{
//								password.pop_back();
//								cout << "\b \b";
//							}
//						}
//						else
//						{
//							password.push_back(ch);
//							cout << "*";
//						}
//					}
//					cout << endl;
//					m.AddUser(username, password);
//					cout << "Dang ki thanh cong!" << endl;
//					m.SaveToFile("Employee.txt");
//					system("pause");
//					break;
//				}
//			}
//		}
//	}
//	if (selectedOption2 == 0) // nhân viên
//	{
//		ToMau(1, 1, "NHAN VIEN", 240);
//		vector<string> menuOptions = { "DANG NHAP","DANG KI TAI KHOAN" };
//		XuLyBanPhim2(menuOptions);
//		int e = XuLyBanPhim2(menuOptions);
//		m.ReadFromFile("Employee.txt");
//		if (e == 1) //đăng nhập
//		{
//			string username;
//			string password;
//			char ch;
//			cout << "Ten dang nhap:"; cin >> username;
//			cout << "Mat khau     :";
//			while (1)
//			{
//				ch = _getch();
//				if (ch == 13) break;
//
//				else if (ch == 8)
//				{
//					if (!password.empty())
//					{
//						password.pop_back();
//						cout << "\b \b";
//					}
//				}
//				else
//				{
//					password.push_back(ch);
//					cout << "*";
//				}
//			}
//			cout << endl;
//			try
//			{
//				int i = 0;
//				while (1)
//				{
//					if (!m.LogIn(username, password))
//					{
//						cout << "Dang nhap that bai! Hay dang nhap lai." << endl;
//						cout << "Ten dang nhap:"; cin >> username;
//						cout << "Mat khau:";
//						while (1)
//						{
//							ch = _getch();
//							if (ch == 13) break;
//
//							else if (ch == 8)
//							{
//								if (!password.empty())
//								{
//									password.pop_back();
//									cout << "\b \b";
//								}
//							}
//							else
//							{
//								password.push_back(ch);
//								cout << "*";
//							}
//						}
//						cout << endl;
//						i++;
//					}
//					else
//					{
//						throw string("Dang nhap thanh cong.");
//						break;
//					}
//					if (i >= 5)
//					{
//						cout << "Ban da dang nhap sai qua nhieu lan!" << endl;
//						system("pause");
//						break;
//					}
//				}
//			}
//			catch (string& e)
//			{
//				cout << e << endl;
//			}
//		}
//		if (e == 0) //đăng kí
//		{
//			string username;
//			string password;
//			while (1)
//			{
//				cout << "Ten dang nhap:"; cin >> username;
//				char ch;
//				if (m.Check(username)) cout << "Tai khoan da ton tai! Moi nhap lai." << endl;
//				else
//				{
//					cout << "Mat khau:";
//					while (1)
//					{
//						ch = _getch();
//						if (ch == 13) break;
//
//						else if (ch == 8)
//						{
//							if (!password.empty())
//							{
//								password.pop_back();
//								cout << "\b \b";
//							}
//						}
//						else
//						{
//							password.push_back(ch);
//							cout << "*";
//						}
//					}
//					cout << endl;
//					m.AddUser(username, password);
//					cout << "Dang ki thanh cong!" << endl;
//					m.SaveToFile("Employee.txt");
//					system("pause");
//					break;
//				}
//			}
//		}
//	}
//}

void setConsoleBackgroundColor(int backgroundColor) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);

	// Xóa các thông số màu nền hiện tại và giữ lại các thông số màu văn bản
	backgroundColor = backgroundColor << 4; // Dịch trái 4 bit để chuyển sang thông số màu nền
	consoleInfo.wAttributes = consoleInfo.wAttributes & 0xFFF0; // Xóa thông số màu nền hiện tại
	consoleInfo.wAttributes = consoleInfo.wAttributes | backgroundColor; // Gán thông số màu nền mới

	// Thiết lập lại thông số màu sắc của màn hình console
	SetConsoleTextAttribute(hConsole, consoleInfo.wAttributes);
}

void XoaManHinh3()
{
#ifdef _WIN32
	system("cls"); // Nếu bạn đang sử dụng hệ điều hành Windows
#else
	// Đối với các hệ điều hành khác như Linux, MacOS, bạn có thể sử dụng "clear" hoặc "reset"
	system("clear");
	// hoặc
	// system("reset");
#endif
}