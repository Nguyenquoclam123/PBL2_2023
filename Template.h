#pragma once
#ifndef TEMPLATE_H
#define TEMPLATE_H
#include <iostream>
#include <sstream>
#include<fstream>
//#include<stdlib.h>
//#include<string> 


using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(const T &data) : data(data), next(NULL) {}
    ~Node();
};
template<typename T>
Node<T>::~Node()
{}

template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList() : head(NULL) {}
    ~LinkedList()
    {
        while (head != NULL)
        {
            Node<T> *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    LinkedList<T> CreateLinkedList();
    Node<T> *CreateNode(const T &);
    void Display();
    void AddLast(const T &);
    void Findinf(const T &);
    void UpdateBill(const T &);
    void WriteDataToFile(const string&);
    void WriteDataToFilee(const string&);
    void WriteALLDataToFile(const string&);
    void ClearFile(const string& );
    void DeleteDataFromFile(const T&);
    Node<T>* GetHead() const;
    void Clear();
    void UpdateProductList(LinkedList<T>& , const T& );
 
};

template <typename T>
Node<T> *LinkedList<T>::CreateNode(const T &data)
{
    Node<T> *tmp = new Node<T>(data);
    // cout << tmp->data;
    return tmp;
}

// template <typename T>
// void LinkedList<T>::Display()
// {
//     Node<T> *tmp = head;
//     while (tmp != NULL)
//     {
//         cout << tmp->data;
//         tmp = tmp->next;
//     }
// }
template <typename T>
void LinkedList<T>::Display()
{
    Node<T> *tmp = head;
    while (tmp != NULL)
    {
        tmp->data.show();
        tmp = tmp->next;
    }
}
template <typename T>
LinkedList<T> LinkedList<T>::CreateLinkedList() {
        return LinkedList<T>(); // Trả về một đối tượng LinkedList rỗng
    }

template <typename T>
void LinkedList<T>::AddLast(const T &data)
{
    Node<T> *tmp = CreateNode(data);
    // cout << tmp->data;
    if (head == NULL)
    {
        // cout <<"yes"<< endl;
        head = tmp;
    }
    else
    {
        Node<T> *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = tmp;
    }
    // cout << tmp->data;
}

template <typename T>
void LinkedList<T>::Findinf(const T &t)
{
     Node<T>* temp = head;

    while (temp != nullptr) {
        if (temp->data == t) {
            cout <<" Thong tin ban muon tim la : " << endl;
             temp->data.show();  // Phần tử được tìm thấy
            return;
        }
        temp = temp->next;
    }

    cout << "Khong tim thay thong tin" << endl; // Không tìm thấy phần tử
}


// Trong lớp LinkedList
template <typename T>
void LinkedList<T>::UpdateBill(const T &t) {
    Node<T>* temp = head;

    while (temp != nullptr) {
        if (temp->data == t) {  // Sử dụng toán tử == để so sánh
            // Hỏi người dùng nhập thông tin mới
            cout << "Nhap thong tin moi : " << endl;
            T newInfor;
            cin >> newInfor;  // Yêu cầu người dùng nhập thông tin mới

            // Thực hiện cập nhật thông tin
            temp->data = newInfor;
           // cin >> temp->data;
            cout << "Cap nhat thanh cong!" << endl;
            return; // Dừng khi cập nhật xong
        }
        temp = temp->next;
    }

    cout << "Khong tim thay ma , khong the cap nhat thong tin" << endl;
}



// template <typename T>
// void LinkedList<T>::ReadDataFromFileCustomer(const string& file) {
//       ifstream inputFile(file, std::ios::in);
//     if (!inputFile.is_open()) {
//         cerr << "Khong the mo file de doc" << endl;
//         return;
//     }

//     string ID;
//     string Name ;
//     string Gender ;
//     string Phone;
//     string Address ;
//     float Totalvalue ; 
//     int Points ;

//     // Xóa danh sách hiện tại
//     while (head != nullptr) {
//         Node<T>* temp = head;
//         head = head->next;
//         delete temp;
//     }

   
//     string line;
// while (getline(inputFile, line)) {
//     istringstream iss(line);
//     string token;

//     // Đọc billID
//    if (getline(iss, token, ' ')) {
//         ID = token; // Chuyển từ string sang int
//     }

//     // Đọc dateBill
//     if (getline(iss, token, ' ')) {
//         Name = token;
//     }

//     // Đọc nameCashier
//     if (getline(iss, token, ' ')) {
//         Gender = token;
//     }

//     // Đọc paymentMethods
//     if (getline(iss, token, ' ')) {
//         Phone = token;
//     }

//     // Đọc priceBill
//     if (getline(iss, token, ' ')) {
//         Address = token;
//     }

//     // Đọc CustomerID
//     if (getline(iss, token, ' ')) {
//         Totalvalue = stof(token); // Chuyển từ string sang int
//     }

//     // Đọc NameCus
//     if (getline(iss, token, ' ')) {
//     Points = stoi(token);
//     }


//     // Tiếp tục tương tự cho các thành phần khác

//     Customer p;
//     p.SetID(ID);
//     p.SetName(Name);
//     p.SetGender(Gender);
//     p.SetPhone(Phone);
//     p.SetAddress(Address);
//     p.SetTotalvalue(Totalvalue);
//     p.SetPoints(Points);

//     this->AddLast(p);
// }
//  inputFile.close();
// }




template <typename T>
void LinkedList<T>::WriteDataToFile(const string& file) {
    ofstream outputFile(file,std::ios::app);
    if (!outputFile.is_open()) {
        cerr << "Khong the mo file de ghi" << endl;
        return;
    }
    if (head == nullptr) {
        cerr << "Danh sach lien ket rong, khong co du lieu de ghi" << endl;
        return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    outputFile << temp->data;
    outputFile.close();
}

template <typename T>
void LinkedList<T>::WriteDataToFilee(const string& file) {
    ofstream outputFile(file,std::ios::app);
    if (!outputFile.is_open()) {
        cerr << "Khong the mo file de ghi" << endl;
        return;
    }
    if (head == nullptr) {
        cerr << "Danh sach lien ket rong, khong co du lieu de ghi" << endl;
        return;
    }
    Node<T>* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    outputFile << temp->data << endl;
    outputFile.close();
}

template <typename T>
void LinkedList<T>::WriteALLDataToFile(const string& file) {
    ofstream outputFile(file, std::ios::out);
    if (!outputFile.is_open()) {
        cerr << "Khong the mo file de ghi" << endl;
        return;
    }
    if (head == nullptr) {
        cerr << "Danh sach lien ket rong, khong co du lieu de ghi" << endl;
        return;
    }
    Node<T>* temp = head;
    while (temp != nullptr) {
        outputFile << temp->data;
        temp = temp->next;
        // if (temp != nullptr) {
        //     outputFile << std::endl;  // Xuống dòng sau mỗi phần tử
        // }
    }
    outputFile.close();
}

template <typename T>
void LinkedList<T>::Clear()
{
     while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
}

template <typename T>
void LinkedList<T>::ClearFile(const string& filename) {
    ofstream outputFile(filename, std::ios::trunc); // Mở file để ghi lại (ios::trunc sẽ xóa hết dữ liệu)
    if (!outputFile.is_open()) {
        std::cerr << "Khong the mo file de ghi." << std::endl;
        return;
    }

    // Đóng file ngay sau khi mở để đảm bảo dữ liệu đã được xóa
    outputFile.close();
   // std::cout << "Xoa du lieu thanh cong.\n";
}

template <typename T>
void LinkedList<T>::DeleteDataFromFile(const T& value) {
    // Nếu danh sách rỗng, không có gì để xóa
    if (head == nullptr) {
        cout << "Danh sach lien ket rong. Khong the xoa." << endl;
        return;
    }

    // Nếu phần tử cần xóa ở đầu danh sách
    if (head->data == value) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
      //  cout << "Da xoa phan tu co gia tri: " << value << endl;
        return;
    }

    // Tìm phần tử cần xóa
    Node<T>* current = head;
    Node<T>* previous = nullptr;

    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    // Nếu phần tử không tồn tại trong danh sách
    if (current == nullptr) {
        cout << "Khong tim thay phan tu co gia tri: " << value << ". Khong the xoa." << endl;
        return;
    }

    // Xóa phần tử
    previous->next = current->next;
    delete current;
   // cout << "Da xoa phan tu co gia tri: " << value << endl;
}

template <typename T>
Node<T>* LinkedList<T>::GetHead() const
{
    return this->head;
}


template <typename T>
void LinkedList<T>::UpdateProductList(LinkedList<T>& productList, const T& product)
 {
    Node<T>* tempProduct = productList.GetHead();

    while (tempProduct != nullptr) {
        if (tempProduct->data.GetID() == product.GetID()) {
            tempProduct->data = product;
        }
        tempProduct = tempProduct->next;
    }
}
// template <typename T>
// void LinkedList<T>::ReadDataFromFileAdmin(const string& file) {
//       ifstream inputFile(file, std::ios::in);
//     if (!inputFile.is_open()) {
//         cerr << "Khong the mo file de doc" << endl;
//         return;
//     }

//     string Name ;
//     string Gmail ;
//     string UserName;
//     string PassWord;

//     // Xóa danh sách hiện tại
//     while (head != nullptr) {
//         Node<T>* temp = head;
//         head = head->next;
//         delete temp;
//     }

   
//     string line;
// while (getline(inputFile, line)) {
//     istringstream iss(line);
//     string token;

//     // Đọc dateBill
//     if (getline(iss, token, ' ')) {
//         Name = token;
//     }

//     // Đọc nameCashier
//     if (getline(iss, token, ' ')) {
//         Gmail = token;
//     }

//     // Đọc paymentMethods
//     if (getline(iss, token, ' ')) {
//         UserName = token;
//     }

//     // Đọc priceBill
//     if (getline(iss, token, ' ')) {
//         PassWord= token;
//     }


//     // Tiếp tục tương tự cho các thành phần khác

//     Admin p;
//     p.SetName(Name);
//     p.SetGmail(Gmail);
//     p.SetUserName(UserName);
//     p.SetPassWord(PassWord);

//     this->AddLast(p);
// }
//  inputFile.close();
// }

// template <typename T>
// void LinkedList<T>::ReadDataFromFileEmloyee(const string& file) {
//       ifstream inputFile(file, std::ios::in);
//     if (!inputFile.is_open()) {
//         cerr << "Khong the mo file de doc" << endl;
//         return;
//     }

//     string ID;
//     string Name ;
//     string Gender ;
//     string Phone;
//     string Address ;
//     int Sarary ;
//     float Revenue ;
//     string UserName;
//     string PassWord;

//     // Xóa danh sách hiện tại
//     while (head != nullptr) {
//         Node<T>* temp = head;
//         head = head->next;
//         delete temp;
//     }

   
//     string line;
//     while (getline(inputFile, line)) {
//         istringstream iss(line);
//         string token;

//         // Đọc billID
//     if (getline(iss, token, ' ')) {
//             ID = token; // Chuyển từ string sang int
//         }

//         // Đọc dateBill
//         if (getline(iss, token, ' ')) {
//             Name = token;
//         }

//         // Đọc nameCashier
//         if (getline(iss, token, ' ')) {
//             Gender = token;
//         }

//         // Đọc paymentMethods
//         if (getline(iss, token, ' ')) {
//             Phone = token;
//         }

//         // Đọc priceBill
//         if (getline(iss, token, ' ')) {
//             Address = token;
//         }

//         // Đọc CustomerID
//         if (getline(iss, token, ' ')) {
//             Sarary = stoi(token); // Chuyển từ string sang int
//         }

//         // Đọc NameCus
//         if (getline(iss, token, ' ')) {
//         Revenue = stof(token);
//         }

//         // Đọc PhoneCus
//         if (getline(iss, token, ' ')) {
//             UserName = token;
//         }

//         // Đọc GenderCus
//         if (getline(iss, token, ' ')) {
//             PassWord = token;
//         }


//     // Tiếp tục tương tự cho các thành phần khác

//    Employee p;
//    p.SetID(ID);
//    p.SetName(Name);
//    p.SetGender(Gender);
//    p.SetPhone(Phone);
//    p.SetAddress(Address);
//    p.SetSarary(Sarary);
//    p.SetRevenur(Revenue);
//    p.SetUserName(UserName);
//    p.SetPassWord(PassWord);

//     this->AddLast(p);
// }
//  inputFile.close();
// }

// template <typename T>
// void LinkedList<T>::ReadDataFromFileEquipment(const string& file) {
//       ifstream inputFile(file, std::ios::in);
//     if (!inputFile.is_open()) {
//         cerr << "Khong the mo file de doc" << endl;
//         return;
//     }

//    string ID ;
//     string Name ;
//     int Stock  ;
//     float Price ;
//     string Type ;
//     int Quantity;
//     string place_production  ;
//     string Size ;

//     // Xóa danh sách hiện tại
//     while (head != nullptr) {
//         Node<T>* temp = head;
//         head = head->next;
//         delete temp;
//     }

   
//     string line;
// while (getline(inputFile, line)) {
//     istringstream iss(line);
//     string token;

//     // Đọc billID
//    if (getline(iss, token, ' ')) {
//         ID = token; // Chuyển từ string sang int
//     }

//     // Đọc dateBill
//     if (getline(iss, token, ' ')) {
//         Name = token;
//     }

//     // Đọc nameCashier
//     if (getline(iss, token, ' ')) {
//         Stock = stoi(token);
//     }

//     // Đọc paymentMethods
//     if (getline(iss, token, ' ')) {
//         Price = stoi(token);
//     }

//     // Đọc priceBill
//     if (getline(iss, token, ' ')) {
//         Type = token;
//     }

//     // Đọc CustomerID
//     if (getline(iss, token, ' ')) {
//         Quantity = stoi(token); // Chuyển từ string sang int
//     }

//     // Đọc NameCus
//     if (getline(iss, token, ' ')) {
//      place_production = token;
//     }

//     if (getline(iss, token, ' ')) {
//      Size = token;
//     }


//     // Tiếp tục tương tự cho các thành phần khác

//     Equipment p;
//     p.SetID(ID);
//     p.SetName(Name);
//     p.Setplace_production(place_production);
//     p.SetPrice(Price);
//     p.SetQuantity(Quantity);
//     p.SetSize(Size);
//     p.SetStock(Stock);
//     p.SetType(Type);

//     this->AddLast(p);
// }
//  inputFile.close();
// }

// template <typename T>
// void LinkedList<T>::ReadDataFromFileBook(const string& file) {
//       ifstream inputFile(file, std::ios::in);
//     if (!inputFile.is_open()) {
//         cerr << "Khong the mo file de doc" << endl;
//         return;
//     }

//     string ID ;
//     string Name ;
//     int Stock  ;
//     float Price ;
//     string Type ;
//     int Quantity;
//     string Author ;
//     string Publisher ;
//     string Language ;

//     // Xóa danh sách hiện tại
//     while (head != nullptr) {
//         Node<T>* temp = head;
//         head = head->next;
//         delete temp;
//     }

   
//      string line;
// while (getline(inputFile, line)) {
//     istringstream iss(line);
//     string token;

//     // Đọc billID
//    if (getline(iss, token, ' ')) {
//         ID = token; // Chuyển từ string sang int
//     }

//     // Đọc dateBill
//     if (getline(iss, token, ' ')) {
//         Name = token;
//     }

//     // Đọc nameCashier
//     if (getline(iss, token, ' ')) {
//         Stock = stoi(token);
//     }

//     // Đọc paymentMethods
//     if (getline(iss, token, ' ')) {
//         Price = stof(token);
//     }

//     // Đọc priceBill
//     if (getline(iss, token, ' ')) {
//         Type = token;
//     }

//     // Đọc CustomerID
//     if (getline(iss, token, ' ')) {
//         Quantity = stof(token); // Chuyển từ string sang int
//     }

//     // Đọc NameCus
//     if (getline(iss, token, ' ')) {
//      Author = token;
//     }

//     if (getline(iss, token, ' ')) {
//      Publisher = token;
//     }

//     if (getline(iss, token, ' ')) {
//      Language = token;
//     }



//     // Tiếp tục tương tự cho các thành phần khác

//     Book p;
//     p.SetAuthor(Author);
//     p.SetID(ID);
//     p.SetLanguage(Language);
//     p.SetName(Name);
//     p.SetPrice(Price);
//     p.SetPublisher(Publisher);
//     p.SetQuantity(Quantity);
//     p.SetStock(Stock);
//     p.SetType(Type);

//     this->AddLast(p);
// }
//  inputFile.close();
// }

// template <typename T>
// void LinkedList<T>::ReadDataFromFileBill(const string& file) {
//       ifstream inputFile(file, std::ios::in);
//     if (!inputFile.is_open()) {
//         cerr << "Khong the mo file de doc" << endl;
//         return;
//     }

//     string ID ;
//     float Price ;
//     string Date ;
//     string Payment_methods ;

//     // Xóa danh sách hiện tại
//     while (head != nullptr) {
//         Node<T>* temp = head;
//         head = head->next;
//         delete temp;
//     }

   
//    string line;
// while (getline(inputFile, line)) {
//     istringstream iss(line);
//     string token;

//     // Đọc billID
//    if (getline(iss, token, ' ')) {
//         ID = token; // Chuyển từ string sang int
//     }

//     // Đọc dateBill
//     if (getline(iss, token, ' ')) {
//         Price = stof(token);
//     }

//     // Đọc nameCashier
//     if (getline(iss, token, ' ')) {
//         Date = token;
//     }

//     // Đọc paymentMethods
//     if (getline(iss, token, ' ')) {
//         Payment_methods = token;
//     }


//     // Tiếp tục tương tự cho các thành phần khác

//    Bill p;
//    p.SetID(ID);
//    p.SetDate(Date);
//    p.SetPrice(Price);
//    p.SetPayment_methods(Payment_methods);

//    this->AddLast(p);
// }
//  inputFile.close();
// }

#endif
