// #pragma once

// // #ifndef HELLO_WORLD_H
// // #define HELLO_WORLD_H
// #pragma once
// #include <bits/stdc++.h>
// #include <fstream>

// using namespace std;

// class Person;
// class Customer;
// class Employee;
// class Product;
// class Purchase;
// class Bill;

// using namespace std;

// //------------------------------------------------------------DATA--------------------------------------------------------------------------

// #include <bits/stdc++.h>
// using namespace std;


// template <typename T>
// class Data
// {
// private:
// 	int Size;
// 	int capacity;
// 	T* array;
// 	void expand(int newCapacity);

// public:
// 	Data(int initCapacity = 100);
// 	~Data();
// 	int size()const;
// 	bool empty();
// 	void Add(const T& newElement);
// 	void insert(const int& pos, const T& newElement);
// 	void erase(int& pos);
// 	T& operator[](const int& index)const;
// 	Data& operator=(const Data& X);
//     void show() const;
//     // Tìm kiếm một phần tử trong mảng
//     int find(const T& element) const;

//     // Xóa một phần tử khỏi mảng
//     void remove(const T& element);

//     // Cập nhật (update) một phần tử trong mảng
//     void UpdateBill(const T& t);
//     // Ghi toàn bộ dữ liệu vào file
//     void WriteAllDataToFile(const std::string& file) const;

//     // Xóa toàn bộ dữ liệu trong file
//     void Clear() ;
//     void ClearFile(const std::string& filename);
// };

// template <typename T>
// Data<T>::Data(int initCapacity)
// {
// 	Size = 0;
// 	capacity = initCapacity;
// 	array = new T[capacity];
// }

// template <typename T>
// void Data<T>::expand(int newCapacity)
// {
// 	if (Size <<= newCapacity)
// 		return;

// 	T* temp = array;
// 	array = new T[newCapacity];
// 	for (int i = 0; i < Size; i++)
// 		array[i] = temp[i];
// 	capacity = newCapacity;
// 	delete[] temp;
// }

// template <typename T>
// Data<T>::~Data()
// {
// 	delete[] array;
// }

// template <typename T>
// int Data<T>::size() const
// {
// 	return Size;
// }

// template <typename T>
// bool Data<T>::empty()
// {
// 	return (Size == 0);
// }

// template <typename T>
// void Data<T>::Add(const T& newElement)
// {
// 	if (Size == capacity)
// 		expand(2 * Size);

// 	array[Size] = newElement;
// 	++Size;
// }

// template <typename T>
// void Data<T>::insert(const int& pos, const T& newElement)
// {
// 	if (Size == capacity)
// 		expand(2 * Size);

// 	for (int i = Size; i > pos; i--)
// 	{
// 		array[i] = array[i - 1];
// 	}

// 	array[pos] = array[newElement];
// 	++Size;
// }

// template <typename T>
// void Data<T>::erase(int& pos)
// {
// 	for (int i = pos; i < Size - 1; i++)
// 	{
// 		array[i] = array[i + 1];
// 	}
// 	--Size;
// }

// template <typename T>
// T& Data<T>::operator[](const int& index) const
// {
// 	return array[index];
// }

// template <typename T>
// Data<T>& Data<T>::operator=(const Data<T>& X)
// {
// 	// delele[] <T>array;
// 	Size = X.Size;
// 	capacity = X.capacity;
// 	// array = new[X.capacity];
// 	for (int i = 0; i < Size; i++)
// 		array[i] = X.array[i];
// 	return *this;
// }

// template <typename T>
// void Data<T>::show() const
// {
//     // if (empty())
//     // {
//     //     cout << "Data is empty." << endl;
//     //     return;
//     // }

//     for (int i = 0; i < Size; ++i)
//     {
//         cout << array[i];

//         // Nếu không phải phần tử cuối cùng, in ra dấu phẩy và khoảng trắng
//         // if (i < Size - 1)
//         // {
//         //     cout << ", ";
//         // }
//     }

//     cout << endl;
// }

// template <typename T>
// int Data<T>::find(const T& element) const
// {
//     for (int i = 0; i < Size; ++i)
//     {
//         if (array[i] == element)
//         {
//             return i; // Trả về chỉ số của phần tử nếu tìm thấy
//         }
//     }
//     return -1; // Trả về -1 nếu không tìm thấy
// }

// template <typename T>
// void Data<T>::remove(const T& element)
// {
//     int index = find(element);
//     if (index != -1)
//     {
//         erase(index); // Nếu tìm thấy, xóa phần tử
//     }
// }

// template <typename T>
// void Data<T>::UpdateBill(const T& t)
// {
//     // Tìm phần tử cần cập nhật
//     int index = -1;
//     for (int i = 0; i < Size; ++i) {
//         if (array[i] == t) {
//             index = i;
//             break;
//         }
//     }

//     // Nếu phần tử không tồn tại trong danh sách
//     if (index == -1) {
//         cout << "Khong tim thay ma, khong the cap nhat thong tin" << endl;
//         return;
//     }

//     // Hỏi người dùng nhập thông tin mới
//     cout << "Nhap thong tin moi : " << endl;
//     T newInfor;
//     cin >> newInfor;  // Yêu cầu người dùng nhập thông tin mới

//     // Thực hiện cập nhật thông tin
//     array[index] = newInfor;
//     cout << "Cap nhat thanh cong!" << endl;
// }

// template <typename T>
// void Data<T>::WriteAllDataToFile(const std::string& file) const
// {
//     std::ofstream outputFile(file, std::ios::out);

//     if (outputFile.is_open())
//     {
//         for (int i = 0; i < Size; ++i)
//         {
//             outputFile << array[i] << std::endl;
//         }

//         outputFile.close();
//     }
//     else
//     {
//         std::cerr << "Cannot open file to write" << std::endl;
//     }
// }

// template <typename T>
// void Data<T>::Clear()
// {
//     delete[] array;
//     Size = 0;
//     capacity = 0;
// }

// template <typename T>
// void Data<T>::ClearFile(const std::string& filename)
// {
//     std::ofstream outputFile(filename, std::ios::trunc); // Mở file để ghi lại (ios::trunc sẽ xóa hết dữ liệu)
//     if (!outputFile.is_open())
//     {
//         std::cerr << "Khong the mo file de ghi." << std::endl;
//         return;
//     }

//     // Đóng file ngay sau khi mở để đảm bảo dữ liệu đã được xóa
//     outputFile.close();
//     // std::cout << "Xoa du lieu thanh cong.\n";
// }

#pragma once

// #ifndef HELLO_WORLD_H
// #define HELLO_WORLD_H
#pragma once
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

class Person;
class Customer;
class Employee;
class Product;
class Bill;
class Purchase;

using namespace std;

//------------------------------------------------------------DATA--------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;


template <typename T>
class Data
{
private:
	int Size;
	int capacity;
	T* array;
	void expand(int newCapacity);

public:
	Data(int initCapacity = 100);
	~Data();
	int size()const;
	bool empty();
    void DeleteData(const T& value);
	void Add(const T& newElement);
	void insert(const int& pos, const T& newElement);
	void erase(int& pos);
	T& operator[](const int& index)const;
	Data& operator=(const Data& X);
    void show() const;
    void WriteDataToFile(const string& file) const;
    void WriteAllDataToFile(const std::string& file) const;
    void Clearr();
    void ClearFile(const std::string& filename) const;
    void Find(const T& t) const ;
    void UpdateBill(const T& t);

};

template <typename T>
Data<T>::Data(int initCapacity)
{
	Size = 0;
	capacity = initCapacity;
	array = new T[capacity];
}

template <typename T>
void Data<T>::expand(int newCapacity)
{
	if (Size <<= newCapacity)
		return;

	T* temp = array;
	array = new T[newCapacity];
	for (int i = 0; i < Size; i++)
		array[i] = temp[i];
	capacity = newCapacity;
	delete[] temp;
}

template <typename T>
Data<T>::~Data()
{
	delete[] array;
}

template <typename T>
int Data<T>::size()const
{
	return Size;
}

template <typename T>
bool Data<T>::empty()
{
	return (Size == 0);
}

template <typename T>
void Data<T>::DeleteData(const T& value)
 {
    // Nếu mảng rỗng, không có gì để xóa
    if (Size == 0) {
        cout << "Mang rong. Khong the xoa." << endl;
        return;
    }

    // Tìm phần tử cần xóa
    int indexToDelete = -1;
    for (int i = 0; i < Size; ++i) {
        if (array[i] == value) {
            indexToDelete = i;
            break;
        }
    }

    // Nếu phần tử không tồn tại trong mảng
    if (indexToDelete == -1) {
        cout << "Khong tim thay phan tu co gia tri: " << value << ". Khong the xoa." << endl;
        return;
    }

    // Dịch chuyển phần tử cuối cùng lên nếu phần tử cần xóa không phải là cuối cùng
    if (indexToDelete < Size - 1) {
        array[indexToDelete] = array[Size - 1];
    }

    // Giảm kích thước mảng
    --Size;
    // cout << "Da xoa phan tu co gia tri: " << value << endl;
}


template <typename T>
void Data<T>::Add(const T& newElement)
{
	if (Size == capacity)
		expand(2 * Size);

	array[Size] = newElement;
	++Size;
}

template <typename T>
void Data<T>::insert(const int& pos, const T& newElement)
{
	if (Size == capacity)
		expand(2 * Size);

	for (int i = Size; i > pos; i--)
	{
		array[i] = array[i - 1];
	}

	array[pos] = array[newElement];
	++Size;
}

template <typename T>
void Data<T>::erase(int& pos)
{
	for (int i = pos; i < Size - 1; i++)
	{
		array[i] = array[i + 1];
	}
	--Size;
}

template <typename T>
T& Data<T>::operator[](const int& index)const
{
	return array[index];
}

template <typename T>
Data<T>& Data<T>::operator=(const Data<T>& X)
{
	// delele[] <T>array;
	Size = X.Size;
	capacity = X.capacity;
	// array = new[X.capacity];
	for (int i = 0; i < Size; i++)
		array[i] = X.array[i];
	return *this;
}

template <typename T>
void Data<T>::show() const
{
    // if (empty())
    // {
    //     cout << "Data is empty." << endl;
    //     return;
    // }

    for (int i = 0; i < Size; ++i)
    {
        // cout << array[i];
        array[i].show();

        // Nếu không phải phần tử cuối cùng, in ra dấu phẩy và khoảng trắng
        // if (i < Size - 1)
        // {
        //     cout << ", ";
        // }
    }

    cout << endl;
}

template <typename T>
void Data<T>::WriteDataToFile(const string& file) const {
    ofstream outputFile(file, std::ios::app);

    if (!outputFile.is_open()) {
        cerr << "Khong the mo file de ghi" << endl;
        return;
    }

    // for (int i = 0; i < Size; ++i) {
    //     outputFile << array[i] << endl;
    // }
     outputFile << array[Size -1] << endl;
    outputFile.close();
}



template <typename T>
void Data<T>::WriteAllDataToFile(const std::string& file) const
{
    std::ofstream outputFile(file, std::ios::out);

    if (outputFile.is_open())
    {
        for (int i = 0; i < Size; ++i)
        {
            outputFile << array[i] << std::endl;
        }

        outputFile.close();
    }
    else
    {
        std::cerr << "Cannot open file to write" << std::endl;
    }
}

template <typename T>
void Data<T>::Clearr()
 {
    if (array != nullptr) {
        delete[] array;
        array = nullptr;
    }
    Size = 0;
    capacity = 0;
}


template <typename T>
void Data<T>::ClearFile(const std::string& filename) const
{
    std::ofstream outputFile(filename, std::ios::trunc); // Mở tệp để ghi lại (ios::trunc sẽ xóa hết dữ liệu)
    if (!outputFile.is_open())
    {
        std::cerr << "Khong the mo file de ghi." << std::endl;
        return;
    }

    // Đóng tệp ngay sau khi mở để đảm bảo rằng dữ liệu đã được xóa
    outputFile.close();
    // std::cout << "Xoa du lieu thanh cong.\n";
}



template <typename T>
void Data<T>::Find(const T& t) const 
{
    for (int i = 0; i < Size; ++i) {
        if (array[i] == t) {
            // cout << "Thong tin ban muon tim la: " << array[i] << endl; // Phần tử được tìm thấy
            cout << "Thong tin ban muon tim la: " <<  endl; 
            array[i].show();// Phần tử được tìm thấy
            return;
        }
    }

    cout << "Khong tim thay thong tin" << endl; // Không tìm thấy phần tử
}


template <typename T>
void Data<T>::UpdateBill(const T& t)
{
    // Tìm phần tử cần cập nhật
    int index = -1;
    for (int i = 0; i < Size; ++i) {
        if (array[i] == t) {
            index = i;
            break;
        }
    }

    // Nếu phần tử không tồn tại trong danh sách
    if (index == -1) {
        cout << "Khong tim thay ma, khong the cap nhat thong tin" << endl;
        return;
    }

    // Hỏi người dùng nhập thông tin mới
    cout << "Nhap thong tin moi : " << endl;
    T newInfor;
    cin >> newInfor;  // Yêu cầu người dùng nhập thông tin mới

    // Thực hiện cập nhật thông tin
    array[index] = newInfor;
    cout << "Cap nhat thanh cong!" << endl;
}