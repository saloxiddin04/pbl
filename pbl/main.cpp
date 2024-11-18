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
    string midd_name;
    string fakultet;
    string phone_number;
    string address;
    string lesson_language;
    int jinsi;
    string lang_certification;
    string lang_lavel;
    string role;
    
public:
    vector<Abituryent> abiturientlar;
    
    void setRole(const string& userRole) {
        role = userRole;
    }
    
    void Table() {
        cout << left
             << setw(5) << "ID"
             << setw(15) << "Ism"
             << setw(15) << "Familiya"
             << setw(20) << "Otasi ismi"
             << setw(10) << "Jinsi"
             << setw(15) << "Fakultet"
             << setw(25) << "Manzil"
             << setw(15) << "Telefon"
             << setw(20) << "Dars Tili"
             << setw(20) << "Til Sert."
             << setw(15) << "Til Dar."
             << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    
    void createAbiturient() {
        
        if (role != "admin") {
            cout << "\nSizda abiturient qo'shish huquqi yo'q." << endl;
            return;
        }
        Abituryent newAbituriyent;
        newAbituriyent.id = abiturientlar.size() + 1;
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
        
        cout << "Otasini ismi kiriting: ";
        getline(cin, newAbituriyent.midd_name);
        
        if (newAbituriyent.midd_name.empty()) {
            newAbituriyent.midd_name = "xxx";
        }
        
        cout << "Yashash manzil kiriting: ";
        getline(cin, newAbituriyent.address);
        
        cout << "Telefon raqam kiriting(+998 99 999 99 99): ";
        getline(cin, newAbituriyent.phone_number);
        
        cout << "Jinsi kiriting(erkak: 1, ayol: 2): ";
        cin >> newAbituriyent.jinsi;
        cin.ignore();

        cout << "Fakultet kiriting: ";
        getline(cin, newAbituriyent.fakultet);
        
        cout << "Fakultet tili kiriting(uz, ru, en): ";
        getline(cin, newAbituriyent.lesson_language);
        
        cout << "Til sertifikati (sertifikat mavjud bo'lsa kiriting, aks holda bo'sh qoldiring): ";
            getline(cin, newAbituriyent.lang_certification);

            if (!newAbituriyent.lang_certification.empty()) {
                cout << "Til darajasini kiriting: ";
                getline(cin, newAbituriyent.lang_lavel);
            }

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
            cout << left
                 << setw(5) << abiturient.id
                 << setw(15) << abiturient.ism
                 << setw(15) << abiturient.familiya
                 << setw(20) << abiturient.midd_name
                 << setw(10) << (abiturient.jinsi == 1 ? "Erkak" : "Ayol")
                 << setw(15) << abiturient.fakultet
                 << setw(25) << abiturient.address
                 << setw(15) << abiturient.phone_number
                 << setw(20) << abiturient.lesson_language
                 << setw(20) << abiturient.lang_certification
                 << setw(15) << abiturient.lang_lavel
                 << endl;
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
                cout << "Otasi ismi: " << abiturient.midd_name << endl;
                cout << "Telefon raqam: " << abiturient.phone_number << endl;
                cout << "Yashash manzil: " << abiturient.address << endl;
                cout << "Jinsi: " << (abiturient.jinsi == 1 ? "Erkak" : "Ayol") << endl;
                cout << "Fakultet: " << abiturient.fakultet << endl;
                cout << "Dars tili: " << abiturient.lesson_language << endl;
                cout << "Til sertifikati: " << abiturient.lang_certification << endl;
                cout << "Til darajasi: " << abiturient.lang_lavel << endl;
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
        
        cout << "\n";
        Table();

        for (const auto& abiturient : abiturientlar) {
            if (abiturient.ism == name) {
                cout << left
                     << setw(5) << abiturient.id
                     << setw(15) << abiturient.ism
                     << setw(15) << abiturient.familiya
                     << setw(20) << abiturient.midd_name
                     << setw(10) << (abiturient.jinsi == 1 ? "Erkak" : "Ayol")
                     << setw(15) << abiturient.fakultet
                     << setw(25) << abiturient.address
                     << setw(15) << abiturient.phone_number
                     << setw(20) << abiturient.lesson_language
                     << setw(20) << abiturient.lang_certification
                     << setw(15) << abiturient.lang_lavel
                     << endl;
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
