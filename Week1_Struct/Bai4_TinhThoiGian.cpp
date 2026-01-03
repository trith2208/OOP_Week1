#include <iostream>
using namespace std;

struct Time
{
    int second, minute, hour;
};

void Nhap(Time &t, Time &t_add){
    cout << "Nhap vao gio hien tai (gio phut giay): ";
    cin >> t.hour >> t.minute >> t.second;
    cout << "Nhap thoi gian can them vao (gio phut giay): ";
    cin >> t_add.hour >> t_add.minute >> t_add.second;
}

Time time_after(Time t, Time t_add){
    Time t_after;
    //Xu li giay
    int time_temp = 0;
    t_after.second = t.second + t_add.second;
    if (t_after.second >= 60){
        t_after.second %= 60;
        //Neu >=60s cong them 1p
        time_temp++;
    }
    //Xu li phut
    t_after.minute = t.minute + t_add.minute + time_temp;
    if (t_after.minute >= 60){
        time_temp = 0;
        t_after.minute %= 60;
        //Neu >= 60p cong them 1h
        time_temp++;
    }
    //Xu li gio
    t_after.hour = t.hour + t_add.hour + time_temp;
    if (t_after.hour >= 24){
        t_after.hour %= 24;
    }
    return t_after;
}

void Print(Time t){
    if (t.hour < 10){
        cout << "0" << t.hour << ":";
    }
    else cout << t.hour << ":";

    if (t.minute < 10){
        cout << "0" << t.minute << ":";
    }
    else cout << t.minute << ":";
    
    if (t.second < 10){
        cout << "0" << t.second;
    }
    else cout << t.second;
    cout << endl;
}


int main()
{
    Time t;
    Time t_add;
    Nhap(t, t_add);
    cout << "Thoi gian hien tai: "; Print(t);
    cout << "Thoi gian can cong them: "; Print(t_add);
    Time result = time_after(t, t_add);
    cout << "Thoi gian sau khi cong: "; Print(result);
}
