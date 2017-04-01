//Program 1
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>
using namespace std;

class Database {
    int id;
    string nama;
    int gajiPokok;
    int tunjangan;
    int bonus;
    int denda;
public :
    void setID(int i){ id = i; }
    void setField(string n, int gp, int tnj, int bns, int dnd){
        nama = n;
        gajiPokok = gp;
        tunjangan = tnj;
        bonus = bns;
        denda = dnd;
    }
    int getID(){ return id; }
    string getNama(){ return nama; }
    int getGajiPokok(){ return gajiPokok; }
    int getTunjangan(){ return tunjangan; }
    int getBonus(){ return bonus; }
    int getDenda(){ return denda; }
};
int n = 128;
Database db[128];

bool cek_op1(int data, int val){ return data<val; }
bool cek_op2(int data, int val){ return data>val; }
bool cek_op3(int data, int val){ return data<=val; }
bool cek_op4(int data, int val){ return data>=val; }
bool cek_op5(int data, int val){ return data==val; }
bool cek_op6(int data, int val){ return data!=val; }

bool cekOperator(string op, int data, int val){
    if(op=="<"){ return cek_op1(data,val);
    } else if(op==">"){ return cek_op2(data,val);
    } else if(op=="<="){ return cek_op3(data,val);
    } else if(op==">="){ return cek_op4(data,val);
    } else if(op=="==" || op=="="){ return cek_op5(data,val);
    } else if(op=="!="){ return cek_op6(data,val); }
}

void initDatabase(){
    for (int i=0 ; i<n ; i++){ db[i].setID(i); }
    db[101].setField("Paijo", 2000, 1000, 500, 200);
    db[102].setField("Lala", 1750, 900, 500, 200);
    db[103].setField("Lulu", 2150, 1000, 300, 375);
    db[104].setField("Sabar", 1500, 750, 600, 200);
    db[105].setField("Sule", 2500, 850, 500, 300);
}

int strToint(string str){
    return atoi(str.c_str());
}

void get(){
    int found = 0;
    for(int i = 0 ; i<n ; i++){
        if(db[i].getNama()!=""){
            cout << "ID         : " << db[i].getID() << endl;
            cout << "Nama       : " << db[i].getNama() << endl;
            cout << "Gaji Pokok : " << db[i].getGajiPokok() << endl;
            cout << "Tunjangan  : " << db[i].getTunjangan() << endl;
            cout << "Bonus      : " << db[i].getBonus() << endl;
            cout << "Denda      : " << db[i].getDenda() << endl << endl;
            found++;
        }
    }
    cout << "  " << found << " dari "<< n <<" data yang sudah terisi ditampilkan." << endl;
    cout << "  Data kosong : " << n-found << " (tanpa nama)" << endl;
    cout << "  Jumlah data : " << n << " (indeks " << 0 << " - " << n-1 << ")";
}

void get(int id){
    if (id<n){
        cout << "\nID         : " << db[id].getID() << endl;
        cout << "Nama       : " << db[id].getNama() << endl;
        cout << "Gaji Pokok : " << db[id].getGajiPokok() << endl;
        cout << "Tunjangan  : " << db[id].getTunjangan() << endl;
        cout << "Bonus      : " << db[id].getBonus() << endl;
        cout << "Denda      : " << db[id].getDenda() << endl;
    } else {
        cout << "  Jumlah data hanya ada " << n << " (indeks " << 0 << " - " << n-1 << ").";
    }
}

void get(string columnName, string str_val){
    int found = 0;
    int int_val = 0;
    if(columnName=="nama"){
        for(int i=0 ; i<n ; i++){
            if((db[i].getNama())==str_val){
                get(db[i].getID());
                found++;
            }
        }
    } else {
        int_val = strToint(str_val);
        if(columnName=="gajipokok"){
            for(int i=0 ; i<n ; i++){
                if(db[i].getGajiPokok()==int_val){
                    get(db[i].getID());
                    found++;
                }
            }
        } else if(columnName=="tunjangan"){
            for(int i=0 ; i<n ; i++){
                if(db[i].getTunjangan()==int_val){
                    get(db[i].getID());
                    found++;
                }
            }
        } else if(columnName=="bonus"){
            for(int i=0 ; i<n ; i++){
                if(db[i].getBonus()==int_val){
                    get(db[i].getID());
                    found++;
                }
            }
        } else if(columnName=="denda"){
            for(int i=0 ; i<n ; i++){
                if(db[i].getDenda()==int_val){
                    get(db[i].getID());
                    found++;
                }
            }
        } else {
            cout << "\n  Field dengan nama \"" << columnName << "\" tidak ditemukan.";
        }
    }

    if(found!=0){
        cout << "\n  Pencarian \"" << columnName << " : " << str_val << "\" selesai.";
        cout << "\n  Didapatkan " << found << " hasil.";
    } else {
        cout << "\n  Didapatkan " << found << " hasil.";
    }
}

void get(string columnName, string op, int val){
    int found = 0;
    if(columnName=="gajipokok"){
        for(int i=0 ; i<n ; i++){
            if(cekOperator(op, db[i].getGajiPokok(), val)==true){
                if(db[i].getNama()!=""){
                    get(db[i].getID());
                    found++;
                }
            }
        }
    } else if(columnName=="tunjangan"){
        for(int i=0 ; i<n ; i++){
            if(cekOperator(op, db[i].getTunjangan(), val)==true){
                if(db[i].getNama()!=""){
                    get(db[i].getID());
                    found++;
                }
            }
        }
    } else if(columnName=="bonus"){
        for(int i=0 ; i<n ; i++){
            if(cekOperator(op, db[i].getBonus(), val)==true){
                if(db[i].getNama()!=""){
                    get(db[i].getID());
                    found++;
                }
            }
        }
    } else if(columnName=="denda"){
        for(int i=0 ; i<n ; i++){
            if(cekOperator(op, db[i].getDenda(), val)==true){
                if(db[i].getNama()!=""){
                    get(db[i].getID());
                    found++;
                }
            }
        }
    } else {
        cout << "\n  Field dengan nama \"" << columnName << "\" tidak ditemukan.";
    }

    if(found!=0){
        cout << "\n  Pencarian \"" << columnName << " " << op << " " << val << "\" selesai." << endl;
        cout << "  Didapatkan " << found << " hasil.";
    } else {
        cout << "\n  Didapatkan " << found << " hasil.";
    }
}

string toLowCase(char a[64]){
    for(int i=0 ; i<strlen(a) ; i++){
        if(a[i]>=65 && a[i]<=90){
            a[i]=a[i]+32;
        }
    }
    return a;
}

int main(){
    int a, d, pil;
    char arr[64];
    string b, c;
    initDatabase();
    do {
        cout << "Program Database Pegawai" << endl;
        cout << "  1. get" << endl;
        cout << "  2. get(id)" << endl;
        cout << "  3. get(columnName, value)" << endl;
        cout << "  4. get(columnName, operator, value)" << endl;
        cout << "  5. bantuan" << endl;
        cout << "  6. (keluar)" << endl;
        cout << "Masukkan pilihan : ";
        cin >> pil;
        cout << endl;
        switch(pil){
            case 1 :
                get();
                getch();
                system("cls");
                break;
            case 2 :
                cout << "ID : ";
                cin >> a;
                get(a);
                getch();
                system("cls");
                break;
            case 3 :
                cout << "Nama field : ";
                cin >> arr;
                b = toLowCase(arr);
                cout << "Value data : ";
                cin >> c;
                get(b,c);
                getch();
                system("cls");
                break;
            case 4 :
                cout << "Nama field      : ";
                cin >> arr;
                b = toLowCase(arr);
                if(b=="nama"){
                    cout << "Operator relasi tidak dapat digunakan untuk columnName \"nama\"";
                } else {
                    cout << "Operator relasi : ";
                    cin >> c;
                    cout << "Value data      : ";
                    cin >> a;
                    if(c=="<" || c==">" || c=="<=" || c==">=" || c=="==" || c=="=" || c=="!="){
                        get(b,c,a);
                    } else {
                        cout << "Operator relasi salah !";
                    }
                }
                getch();
                system("cls");
                break;
            case 5 :
                cout << "Column Name / Field :" << endl;
                cout << " - nama" << endl;
                cout << " - gajiPokok" << endl;
                cout << " - tunjangan" << endl;
                cout << " - bonus" << endl;
                cout << " - denda" << endl;
                cout << "Operator relasi : < , > , <= , >= , == , !=" << endl;
                getch();
                system("cls");
                break;
            case 6 :
                cout << "Program dihentikan...";
                getch();
                break;
            default :
                cout << "Ada AQUA ?";
                getch();
                system("cls");
        }
    } while(pil!=6);
    return 0;
}
