#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct DATHUC
{
    //Somu, heso
    map<int, double> heso;
};

DATHUC* Nhap(){
    int n;
    cin >> n;
    DATHUC* dt = new DATHUC();
    for (int i = 0; i < n; i++){
        cout << "Don thuc " << i+1 << ": ";
        int somu;
        double hs;
        cin >> hs >> somu;

        if (hs != 0){
            dt->heso[somu] = hs;
        }
    }
    return dt;
}

void Xuat(DATHUC A){
    //Check đa thức rỗng
    if (A.heso.empty()){
        cout << 0;
        return;
    }
    //Chuyển đổi qua vector
    vector<pair<double, int>> res;
    for (auto it = A.heso.rbegin(); it != A.heso.rend(); it++){
        res.push_back({(*it).second, (*it).first});
    }
    int ok = 1;
    for (int i = 0; i < res.size(); i++){
        if (ok){
            //Nếu hệ số là -1 thì chỉ in ra dấu -
            if (res[i].first == -1){
                cout << "-";
            }
            //Nếu số hệ số khác 1 thì in ra
            else if (res[i].first != 1){
                cout << res[i].first;
            }
            //In ra x theo hệ số mũ
            if (res[i].second > 1){
                cout << "x^" << res[i].second;
            }
            else if (res[i].second == 1){
                cout << "x";
            }
            ok = 0;
        }
        else{
            //In ra dấu đơn thức
            if (res[i].first < 0){
                cout << " - ";
            }
            else cout << " + ";
            //In ra đơn thức tiếp theo
            if (abs(res[i].first) != 1){
                cout << abs(res[i].first); //In ra phần nguyên vì dấu đã được in
            }
            else if (abs(res[i].first) == 1 && res[i].second == 0){
                cout << 1;
            }
            //In ra x theo hệ số mũ
            if (res[i].second > 1){
                cout << "x^" << res[i].second;
            }
            else if (res[i].second == 1){
                cout << "x";
            }
        }
    }
}

DATHUC Tong2DaThuc(DATHUC *A, DATHUC *B){
    //Somu, heso
    DATHUC Tong;
    for (auto x : A->heso){
        Tong.heso[x.first] = x.second;
    }
    for (auto y : B->heso){
        Tong.heso[y.first] += y.second;
        //Loai bo he so la 0
        if (Tong.heso[y.first] == 0){
            Tong.heso.erase(y.first);
        }
    }
    return Tong;
}

DATHUC Hieu2DaThuc(DATHUC *A, DATHUC *B){
    DATHUC Hieu;
    for (auto x : A->heso){
        Hieu.heso[x.first] = x.second;
    }
    for (auto y : B->heso){
        Hieu.heso[y.first] -= y.second;
        //Loai bo he so bang 0
        if (Hieu.heso[y.first] == 0){
            Hieu.heso.erase(y.first);
        }
    }
    return Hieu;
}


DATHUC Tich2DaThuc(DATHUC *A, DATHUC *B){
    DATHUC Tich;
    for (auto x : A->heso){
        for (auto y : B->heso){
            //cout << "x.first + y.first: " << x.first + y.first << " " << "x.first * y.first: " << x.first * y.first;
            Tich.heso[x.first + y.first] += x.second * y.second;
        }
        //cout << endl;
    }
    //Loai bo he so bang 0
    for (auto k : Tich.heso){
        if (k.second == 0){
            Tich.heso.erase(k.first);
        }
    }
    return Tich;
}

int main() {
    DATHUC *A, *B;
    cout << "Don thuc co dang: heso somu (nhap cach nhau 1 dau space)" << endl;
    cout << "Nhap so luong don thuc A: ";
    A = Nhap();
    cout << "Nhap so luong don thuc B: ";
    B = Nhap();
    cout << "Da thuc A: "; Xuat(*A);
    cout << "\nDa thuc B: "; Xuat(*B);
    cout << endl;

    cout << "\nA + B = "; Xuat(Tong2DaThuc(A, B));
    cout << endl;

    cout << "\nA - B = "; Xuat(Hieu2DaThuc(A, B));
    cout << endl;
    
    cout << "\nA * B = "; Xuat(Tich2DaThuc(A, B));
    return 0;
}
