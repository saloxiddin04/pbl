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
#include <sstream>
#include <fstream>

using namespace std;

class Abituryent {
private:
    size_t id;
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
    
    string getRequiredInput(string props) {
        string input;
        cout << props;
        getline(cin, input);

        while (input.empty()) {
            cout << "Bu maydon majburiy! Iltimos, qiymat kiriting: ";
            getline(cin, input);
        }

        return input;
    }

    
    void createAbiturient() {
        
        ofstream file("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/File.txt", ios::app);
        
        if (role != "admin") {
            cout << "\nSizda abiturient qo'shish huquqi yo'q." << endl;
            return;
        }
        Abituryent newAbituriyent;
        newAbituriyent.id = abiturientlar.size() + 1;
        cin.ignore();
        
        newAbituriyent.ism = getRequiredInput("Ism kiriting: ");
        newAbituriyent.familiya = getRequiredInput("Familiya kiriting: ");

        cout << "Otasini ismi kiriting: ";
        getline(cin, newAbituriyent.midd_name);
        
        if (newAbituriyent.midd_name.empty()) {
            newAbituriyent.midd_name = "xxx";
        }
        
        newAbituriyent.address = getRequiredInput("Yashash manzil kiriting: ");
        
        newAbituriyent.phone_number = getRequiredInput("Telefon raqam kiriting(+998 99 999 99 99): ");
        
        cout << "Jinsi kiriting(erkak: 1, ayol: 2): ";
        cin >> newAbituriyent.jinsi;
        cin.ignore();
        
        newAbituriyent.fakultet = getRequiredInput("Fakultet kiriting: ");
        
        newAbituriyent.lesson_language = getRequiredInput("Fakultet tilini kiriting(uz, ru, en): ");
        
        cout << "Til sertifikati (sertifikat mavjud bo'lsa kiriting, aks holda bo'sh qoldiring): ";
        getline(cin, newAbituriyent.lang_certification);

        if (!newAbituriyent.lang_certification.empty()) {
            newAbituriyent.lang_lavel = getRequiredInput("Til darajasini kiriting(A1, B1, C1): ");
        }

        abiturientlar.push_back(newAbituriyent);
        cout << "\nAbiturient muvaffaqiyatli qo'shildi!" << endl;
        
        if (file.is_open()) {
            file << "ID: " << newAbituriyent.id << endl;
            file << "Ism: " << newAbituriyent.ism << endl;
            file << "Familiya: " << newAbituriyent.familiya << endl;
            file << "Otasining ismi: " << newAbituriyent.midd_name << endl;
            file << "Yashash manzil: " << newAbituriyent.address << endl;
            file << "Telefon raqam: " << newAbituriyent.phone_number << endl;
            file << "Jinsi: " << (newAbituriyent.jinsi == 1 ? "erkak" : "ayol") << endl;
            file << "Fakultet: " << newAbituriyent.fakultet << endl;
            file << "Fakultet tili: " << newAbituriyent.lesson_language << endl;
            file << "Til sertifikati: " << (newAbituriyent.lang_certification.empty() ? "Yo'q" : newAbituriyent.lang_certification) << endl;
            if (!newAbituriyent.lang_certification.empty()) {
                file << "Til darajasi: " << newAbituriyent.lang_lavel << endl;
            }
            file << "----------------------" << endl;

            file.close();
        } else {
            cout << "Fayl ochilmadi!" << endl;
        }
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
        
        for(int i = 0; i < abiturientlar.size(); i++) {
            if(abiturientlar[i].ism == name) {
                cout << left
                     << setw(5) << abiturientlar[i].id
                     << setw(15) << abiturientlar[i].ism
                     << setw(15) << abiturientlar[i].familiya
                     << setw(20) << abiturientlar[i].midd_name
                     << setw(10) << (abiturientlar[i].jinsi == 1 ? "Erkak" : "Ayol")
                     << setw(15) << abiturientlar[i].fakultet
                     << setw(25) << abiturientlar[i].address
                     << setw(15) << abiturientlar[i].phone_number
                     << setw(20) << abiturientlar[i].lesson_language
                     << setw(20) << abiturientlar[i].lang_certification
                     << setw(15) << abiturientlar[i].lang_lavel
                     << endl;
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
    
    const string employeeUsername = "employee";
    const string employeePassword = "employee";
    
    cout << "username: "; cin >> username;
    cout << "password: "; cin >> password;
    
    if (username == adminUsername && password == adminPassword) {
        abi.setRole("admin");
        cout << "\nAdmin sifatida tizimga kirdingiz." << endl;
        return true;
    } else if (username == employeeUsername && password == employeePassword) {
        abi.setRole("teacher");
        cout << "\nXodim sifatida tizimga kirdingiz." << endl;
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
