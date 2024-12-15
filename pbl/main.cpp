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
#include <algorithm>
#include <functional>
#include <unordered_map>

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
    string login;
    
public:
    vector<Abituryent> abiturientlar;
    
    void setRole(const string& userRole) {
        role = userRole;
    }
    
    void setLogin(const string & userLogin) {
        login = userLogin;
    }
    
    string getRole() {
        return role;
    }
    
    string getLogin() {
        ifstream file("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/File.txt");
        
        if (!file.is_open()) {
            cout << "Fayl ochishda xatolik!" << endl;
            return "";
        }
        
        string line;
        string log;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            
            while (getline(ss, token, ',')) {
                log = token;
            }
            
            trim(log);
        }
        
        login = log;
        
        file.close();
        return login;
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
        cout << string(170, '-') << endl;
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
    
    string trim(const string& str) {
        size_t first = str.find_first_not_of(" \t\n\r");
        size_t last = str.find_last_not_of(" \t\n\r");
        return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
    }

    string toLower(const string& str) {
        string lower = str;
        std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        return lower;
    }

    void clearAbiturientlar() {
        abiturientlar.clear();
    }
    
    void createAbiturient() {
        abiturientlar.clear();
        ofstream file("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/File.txt", ios::app);
        loadAbituriyentsFromFile("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/File.txt");
    
        if (role != "admin" && role != "abiturient") {
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
        
        newAbituriyent.login = this->login;

        abiturientlar.push_back(newAbituriyent);
        cout << "\nAbiturient muvaffaqiyatli qo'shildi!" << endl;
        
        if (file.is_open()) {
            file << newAbituriyent.id << ", "
                 << newAbituriyent.ism << ", "
                 << newAbituriyent.familiya << ", "
                 << newAbituriyent.midd_name << ", "
                 << newAbituriyent.address << ", "
                 << newAbituriyent.phone_number << ", "
                 << (newAbituriyent.jinsi == 1 ? "erkak" : "ayol") << ", "
                 << newAbituriyent.fakultet << ", "
                 << newAbituriyent.lesson_language << ", "
                 << (newAbituriyent.lang_certification.empty() ? "Yo'q" : newAbituriyent.lang_certification) << ", "
                 << (newAbituriyent.lang_certification.empty() ? "N/A" : newAbituriyent.lang_lavel) << ", "
                 << newAbituriyent.login << endl;
            file.close();
        } else {
            cout << "Fayl ochilmadi!" << endl;
        }
    }
    
    void loadAbituriyentsFromFile(const string& filename) {
        ifstream file(filename);

        if (!file.is_open()) {
            cout << "Fayl ochilmadi!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Abituryent abiturient;

            string jinsi;
            string lang_cert_empty_check;

            getline(ss, line, ',');
            abiturient.id = stoi(line);

            getline(ss, abiturient.ism, ',');
            getline(ss, abiturient.familiya, ',');
            getline(ss, abiturient.midd_name, ',');
            getline(ss, abiturient.address, ',');
            getline(ss, abiturient.phone_number, ',');
            getline(ss, jinsi, ',');
            abiturient.jinsi = (jinsi == " erkak" ? 1 : 0);

            getline(ss, abiturient.fakultet, ',');
            getline(ss, abiturient.lesson_language, ',');

            getline(ss, lang_cert_empty_check, ',');
            abiturient.lang_certification = (lang_cert_empty_check == "Yo'q" ? "" : lang_cert_empty_check);

            if (!abiturient.lang_certification.empty()) {
                getline(ss, abiturient.lang_lavel, ',');
            } else {
                abiturient.lang_lavel = "N/A";
            }
            
            getline(ss, abiturient.login, ',');
            abiturient.role = "abiturient";
            
            abiturientlar.push_back(abiturient);
        }

        file.close();
    }

    
    void abiturientlarniKorish() {
        abiturientlar.clear();
        loadAbituriyentsFromFile("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/File.txt");
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
                 << setw(10) << (abiturient.jinsi == 1 ? "erkak" : "ayol")
                 << setw(15) << abiturient.fakultet
                 << setw(25) << abiturient.address
                 << setw(15) << abiturient.phone_number
                 << setw(20) << abiturient.lesson_language
                 << setw(20) << abiturient.lang_certification
                 << setw(15) << abiturient.lang_lavel
                 << endl;
        }
    }
    
    void abiturientByLogin(const string & username) {
        abiturientlar.clear();
        loadAbituriyentsFromFile("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/File.txt");

        bool topildi = false;
        for (const auto& abiturient : abiturientlar) {
            if (trim(abiturient.login) == trim(username)) {
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
                cout << "Login: " << abiturient.login << endl;
                topildi = true;
                break;
            }
        }

        if (!topildi) {
            cout << "Bunday login topilmadi." << endl;
        }
    }

    
    void abiturientIzlash() {
        abiturientlar.clear();
        loadAbituriyentsFromFile("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/File.txt");
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
        abiturientlar.clear();
        loadAbituriyentsFromFile("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/File.txt");
        string name;
        cout << "Ism kiriting: ";
        cin.ignore();
        getline(cin, name);

        name = toLower(trim(name));
        
        bool topildi = false;
        
        cout << "\n";
        Table();
        
        for(int i = 0; i < abiturientlar.size(); i++) {
            string storedName = toLower(trim(abiturientlar[i].ism));
            if(storedName == name) {
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
    
    void filterBySurname() {
        abiturientlar.clear();
        loadAbituriyentsFromFile("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/File.txt");
        string surname;
        cout << "Familiya kiriting: ";
        cin.ignore();
        getline(cin, surname);

        surname = toLower(trim(surname));
        
        bool topildi = false;
        
        cout << "\n";
        Table();
        
        for(int i = 0; i < abiturientlar.size(); i++) {
            string storedSurname = toLower(trim(abiturientlar[i].familiya));
            if(storedSurname == surname) {
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
            cout << "Bunday familiyali abiturient topilmadi." << endl;
        }
    }
    
    void filterByFakultet() {
        abiturientlar.clear();
        loadAbituriyentsFromFile("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/File.txt");
        string fakultet;
        cout << "Fakultet kiriting: ";
        cin.ignore();
        getline(cin, fakultet);

        fakultet = toLower(trim(fakultet));
        
        bool topildi = false;
        
        cout << "\n";
        Table();
        
        for(int i = 0; i < abiturientlar.size(); i++) {
            string storedFakultet = toLower(trim(abiturientlar[i].fakultet));
            if(storedFakultet == fakultet) {
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
            cout << "Bu fakultetda abiturientlar mavjud emas!" << endl;
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
                case 2:
                    filterBySurname();
                    break;
                case 3:
                    filterByFakultet();
                    break;
                default:
                    cout << "Noto'g'ri tanlov, qaytadan urinib ko'ring." << endl;
            }
        } while(select != 4);
    }
};

string hashPassword(const string& password) {
    hash<string> hasher;
    size_t hashValue = hasher(password);

    stringstream ss;
    ss << hex << hashValue;
    return ss.str();
}

unordered_map<string, string> loadUsers(const string& filename) {
    unordered_map<string, string> users;
    Abituryent abi;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open file: " << filename << endl;
        return users;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string username, passwordHash;

        if (getline(ss, username, ',') && getline(ss, passwordHash)) {
            users[abi.trim(username)] = abi.trim(passwordHash);
            abi.setLogin(username);
            abi.setRole("abiturient");
        } else {
            cerr << "Error: Invalid line in users.txt: " << line << endl;
        }
    }

    file.close();
    return users;
}

bool authAbiturient(Abituryent & abi) {
    ofstream file("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/users.txt", ios::app);
    unordered_map<string, string> users = loadUsers("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/users.txt");
    
    abi.clearAbiturientlar();

    string login, password;
    
    cout << "login: "; cin >> login;
    
    if (users.find(login) != users.end()) {
        cout << "Bunday login allaqachon mavjud. Iltimos boshqa login kiriting.\n" << endl;
        return false;
    }
    
    cout << "password: "; cin >> password;
    
    if (file.is_open()) {
        file << login << ", "<< hashPassword(password) << endl;
        file.close();
    } else {
        cout << "Fayl ochilmadi!" << endl;
    }
    abi.setRole("abiturient");
    abi.setLogin(login);
    
    cout << "\nMuvofaqqiyatli ro'yhatdan o'tdingiz! \n" << endl;
    
    abi.createAbiturient();
    
    abi.abiturientByLogin(login);
    return true;
}

bool signIn(const unordered_map<string, string>& users) {
    Abituryent abi;
    abi.clearAbiturientlar();
    
    string username, password;

    cout << "login: ";
    cin >> username;
    cout << "password: ";
    cin >> password;

    string enteredHash = hashPassword(password);

    auto it = users.find(username);
    if (it != users.end()) {
        if (abi.trim(it->second) == abi.trim(enteredHash)) {
            abi.setLogin(abi.trim(username));
            abi.setRole("abiturient");
            cout << "Muvofaqqiyatli kirildi. Xush kelibsiz, " << username << "!\n" << endl;
            abi.abiturientByLogin(username);
            return true;
        } else {
            cout << "Password hash does not match!" << endl;
        }
    } else {
        cout << "Username not found!" << endl;
    }

    cout << "Noto'g'ri login yoki password!" << endl;
    return false;
}

bool login(Abituryent& abi) {
    string username, password;

    const string adminUsername = "admin";
    const string adminPasswordHash = "8ecb24ae920dabb0"; // admin

    const string employeeUsername = "employee";
    const string employeePasswordHash = "369b4f7e3e6ae43b"; // employee

    cout << "username: ";
    cin >> username;
    cout << "password: ";
    cin >> password;

    string passwordHash = hashPassword(password);
    
    if (username == adminUsername && passwordHash == adminPasswordHash) {
        abi.setRole("admin");
        cout << "\nAdmin sifatida tizimga kirdingiz." << endl;
        return true;
    } else if (username == employeeUsername && passwordHash == employeePasswordHash) {
        abi.setRole("employee");
        cout << "\nXodim sifatida tizimga kirdingiz." << endl;
        return true;
    } else {
        cout << "\nNoto'g'ri username yoki parol." << endl;
        return false;
    }
}

void menyu() {
    unordered_map<string, string> users = loadUsers("/Users/saloxiddinsayfuddinov/Documents/c++/PBL/pbl/pbl/users.txt");
    Abituryent abi;
    
    while (true) {
        int role;
        cout << "\n====== Abiturientlarni ro'yxatga olish tizimi ======" << endl;
        cout << "1. Admin sifatida kirish" << endl;
        cout << "2. Xodim sifatida kirish" << endl;
        cout << "3. Abiturient sifatida kirish" << endl;
        cout << "4. Abiturient sifatida ro'yhatdan o'tish" << endl;
        cout << "5. Chiqish" << endl;
        cout << "Tanlovingizni kiriting: ";
        
        cin >> role;

        switch (role) {
            case 1:
            case 2:
                if (!login(abi)) {
                    continue;
                }
                break;
            case 3:
                signIn(users);
                break;
            case 4:
                authAbiturient(abi);
                break;
            case 5:
                cout << "Dasturdan chiqildi." << endl;
                return;
            default:
                cout << "Noto'g'ri tanlov, iltimos qaytadan urinib ko'ring." << endl;
                continue;
        }

        if (abi.getRole() == "admin" || abi.getRole() == "employee") {
            int tanlov;
            do {
                cout << "\n====== Admin/Xodim menyusi ======" << endl;
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
                        cout << "Login menyusiga qaytilmoqda..." << endl;
                        break;
                    default:
                        cout << "Noto'g'ri tanlov, qaytadan urinib ko'ring." << endl;
                }
            } while (tanlov != 5);
        }
    }
}


int main() {
    menyu();
    return 0;
}
