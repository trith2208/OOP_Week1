#include <iostream>
using namespace std;

struct Date
{
    int days_to_add;
    int day, month, year;
};

void nhap(Date &a){
    cout << "Nhap ngay/thang/nam hien tai (cach nhau 1 dau space): " << endl;
    cin >> a.day >> a.month >> a.year;
    cout << "Nhap so ngay can cong them: ";
    cin >> a.days_to_add;
}

bool CheckLeapYear(int n){
    if ((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0)) return true;
    else return false;
}

void Print_date(Date a){
    cout << "Ngay can tim: " << a.day << "/" << a.month << "/" << a.year << endl;
}

//Tìm ngày tối đa của tháng đó
int FindMaxDay_Month(int month, int year){
    switch (month)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
        break;
    case 4: case 6: case 9: case 11:
        return 30;
        break;
    case 2:
        if (CheckLeapYear(year)){
            return 29;
        }
        else return 28;
        break;
    }
}

void XuLiNgayDuong(Date &a){
    a.day = a.day - FindMaxDay_Month(a.month, a.year);
    a.month++;
    if (a.month > 12){
        a.month = 1;
        a.year += 1;
    }
}

void Processing(Date &a){
    //Tìm ngày còn lại để qua năm mới
    int Day_left_inYear = FindMaxDay_Month(a.month, a.year) - a.day;
    for (int i = a.month + 1; i <= 12; i++){
        Day_left_inYear += FindMaxDay_Month(i, a.year);
    }
    //Nếu ngày cần thêm nhỏ hoặc bằng ngày còn lại (ko thể qua năm mới)
    //==> xử lí và in ra
    if (a.days_to_add <= Day_left_inYear){
        a.day += a.days_to_add;
        while (a.day > FindMaxDay_Month(a.month, a.year)){
            XuLiNgayDuong(a);
        }
        Print_date(a);
        return;
    }
    //Chuẩn hóa về ngày 1/1
    else{
        a.days_to_add -= (Day_left_inYear + 1); //Cộng thêm 1 để sang năm mới
        a.day = 1;
        a.month = 1;
        a.year += 1;
    }

    bool check = true;
    //Xử lí với đơn vị (năm)
    while (check){
        int temp = CheckLeapYear(a.year) ? 366 : 365;
        if (a.days_to_add >= temp){
            a.days_to_add -= temp;
            a.year += 1;
        }
        else check = false;
    }
    a.day += a.days_to_add;
    //Trong khi a.day vẫn lớn hơn ngày tối đa trong tháng
    while (a.day > FindMaxDay_Month(a.month, a.year)){
        XuLiNgayDuong(a);
    }
    Print_date(a);
}


int main()
{
    Date a;
    nhap(a);
    Processing(a);
}
