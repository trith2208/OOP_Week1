#include <iostream>
using namespace std;

struct SoThuc
{
    double a, b;
};

void Nhap(SoThuc &Tinh){
    cout << "Nhap vao 2 so thuc: ";
    cin >> Tinh.a >> Tinh.b;
}

void Tong2SoThuc(SoThuc Tinh){
    double sum = Tinh.a + Tinh.b;
    cout << "Tong 2 so thuc la: " << sum << endl;
}

void Hieu2SoThuc(SoThuc Tinh){
    double minus = Tinh.a - Tinh.b;
    cout << "Hieu cua so thuc a voi so thuc b la: " << minus << endl;
}

void Tich2SoThuc(SoThuc Tinh){
    double multi = Tinh.a * Tinh.b;
    cout << "Tich cua 2 so thuc la: " << multi << endl;
}

void Thuong2SoThuc(SoThuc Tinh){
    double divide = Tinh.a /Tinh.b;
    cout << "Thuong cua so thuc a voi so thuc b la: " << divide << endl;
}

int main()
{
    SoThuc Tinh;
    Nhap(Tinh);
    Tong2SoThuc(Tinh);
    Hieu2SoThuc(Tinh);
    Tich2SoThuc(Tinh);
    Thuong2SoThuc(Tinh);
}