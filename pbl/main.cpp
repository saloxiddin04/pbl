//
//  main.cpp
//  pbl
//
//  Created by Saloxiddin Sayfuddinov on 07/11/24.
//

#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Abituryent {
private:
    int id;
    string ism;
    string familiya;
    string fakultet;
    double ball;
    string role;
    
public:
    vector<Abituryent> abiturientlar;
    
    void setRole(const string& userRole) {
        role = userRole;
    }
    
    void Table() {
        cout<<left<<setw(5)<<"ID"
            <<setw(15)<<"Ism"
            <<setw(15)<<"Familiya"
            <<setw(15)<<"Fakultet"
            <<setw(15)<<"Ball"<<endl;
            cout << "------------------------------------------------------------" << endl;
    }
    
    void createAbiturient() {
        
        if (role != "admin") {
            cout << "\nSizda abiturient qo'shish huquqi yo'q." << endl;
            return;
        }
        Abituryent newAbituriyent;
        cout << "Abiturientning ID raqamini kiriting: ";
        cin >> newAbituriyent.id;
        cin.ignore();
        
        for (const auto& abiturient : abiturientlar) {
            if (abiturient.id == newAbituriyent.id) {
                cout << "\nBu ID raqam allaqachon mavjud. Iltimos, boshqa ID kiriting."<<endl;
                return;
            }
        }
        
        cout << "Ism kiriting: ";
        getline(cin, newAbituriyent.ism);

        cout << "Familiya kiriting: ";
        getline(cin, newAbituriyent.familiya);

        cout << "Fakultet kiriting: ";
        getline(cin, newAbituriyent.fakultet);

        cout << "Ballni kiriting: ";
        cin >> newAbituriyent.ball;

        abiturientlar.push_back(newAbituriyent);
        cout << "\nAbiturient muvaffaqiyatli qo'shildi!" << endl;
    }
    
    void abiturientlarniKorish() {
        if (abiturientlar.empty()) {
            cout << "Hozircha ro'yxatda abiturientlar yo'q." << endl;
            return;
        }
        
        cout << "\n";
        Table();

        for (const auto& abiturient : abiturientlar) {
            cout<<left<<setw(5)<<abiturient.id
                <<setw(15)<<abiturient.ism
                <<setw(15)<<abiturient.familiya
                <<setw(15)<<abiturient.fakultet
                <<setw(15)<<abiturient.ball<<endl;
        }
    }
    
    void abiturientIzlash() {
        int id;
        cout << "Qidirilayotgan abiturientning ID raqamini kiriting: ";
        cin >> id;

        bool topildi = false;
        for (const auto& abiturient : abiturientlar) {
            if (abiturient.id == id) {
                cout << "ID: " << abiturient.id << endl;
                cout << "Ism: " << abiturient.ism << endl;
                cout << "Familiya: " << abiturient.familiya << endl;
                cout << "Fakultet: " << abiturient.fakultet << endl;
                cout << "Ball: " << abiturient.ball << endl;
                topildi = true;
                break;
            }
        }

        if (!topildi) {
            cout << "Bunday ID raqamli abiturient topilmadi." << endl;
        }
    }
    
    void filterByName() {
        Abituryent abiturient;
        string name;
        cout<<"Ism kiriting: "; cin>>name;
        bool topildi = false;

        cout<<left<<setw(5)<<"ID"
            <<setw(15)<<"Ism"
            <<setw(15)<<"Familiya"
            <<setw(15)<<"Fakultet"
            <<setw(15)<<"Ball"<<endl;
            cout << "------------------------------------------------------------" << endl;

        for(int i = 0; i < abiturientlar.size(); i++) {
            if(abiturientlar[i].ism == name) {
                cout<<left<<setw(5)<<abiturientlar[i].id
                    <<setw(15)<<abiturientlar[i].ism
                    <<setw(15)<<abiturientlar[i].familiya
                    <<setw(15)<<abiturientlar[i].fakultet
                    <<setw(15)<<abiturientlar[i].ball<<endl;
                topildi = true;
            }
        }

        if (!topildi) {
            cout << "Bunday ismli abiturient topilmadi." << endl;
        }
    }

    void abiturientFilter() {
        int select;
        do {
            cout << "\n====== Abiturientlarni filter qilish ======" << endl;
            cout << "1. Ism bo'yicha" << endl;
            cout << "2. Familiya bo'yicha" << endl;
            cout << "3. Fakultet bo'yicha" << endl;
            cout << "4. Menyuga chiqish" << endl;
            cout << "Tanlovingizni kiriting: ";
            cin >> select;

            switch(select) {
                case 1:
                    filterByName();
                    break;
                default:
                    cout << "Noto'g'ri tanlov, qaytadan urinib ko'ring." << endl;
            }
        } while(select != 4);
    }
};

bool login(Abituryent & abi) {
    string username, password;
    const string adminUsername = "admin";
    const string adminPassword = "admin";
    
    const string teacherUsername = "teacher";
    const string teacherPassword = "teacher";
    
    cout << "username: "; cin >> username;
    cout << "password: "; cin >> password;
    
    if (username == adminUsername && password == adminPassword) {
        abi.setRole("admin");
        cout << "\nAdmin sifatida tizimga kirdingiz." << endl;
        return true;
    } else if (username == teacherUsername && password == teacherPassword) {
        abi.setRole("teacher");
        cout << "\nO'qituvchi sifatida tizimga kirdingiz." << endl;
        return true;
    } else {
        cout << "\nNoto'g'ri username yoki parol." << endl;
        return false;
    }
};

void menyu() {
    Abituryent abi;
    
    if (!login(abi)) {
        return;
    }
    
    int tanlov;
    do {
        cout << "\n====== Abiturientlarni ro'yxatga olish tizimi ======" << endl;
        cout << "1. Abiturient qo'shish" << endl;
        cout << "2. Abiturientlarni ko'rish" << endl;
        cout << "3. Abiturient izlash" << endl;
        cout << "4. Abiturient filterlash" << endl;
        cout << "5. Chiqish" << endl;
        cout << "Tanlovingizni kiriting: ";
        cin >> tanlov;
        switch (tanlov) {
            case 1:
                abi.createAbiturient();
                break;
            case 2:
                abi.abiturientlarniKorish();
                break;
            case 3:
                abi.abiturientIzlash();
                break;
            case 4:
                abi.abiturientFilter();
                break;
            case 5:
                cout << "Tizimdan chiqildi." << endl;
                break;
            default:
                cout << "Noto'g'ri tanlov, qaytadan urinib ko'ring." << endl;
        }
    } while (tanlov != 5);
}

int main() {
    menyu();
    return 0;
}
