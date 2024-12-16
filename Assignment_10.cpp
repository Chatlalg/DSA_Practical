#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct student {
    public:
    int rollno;
    string name;
    string division;
    string address;
};

class grey {
    fstream file;
    fstream tempfile;

    public: 
    student s;
    grey() {
        file.open("hi.txt", ios::out | ios::trunc);
        file << "Roll No\tName\tDivision\tAddress" << endl;
        file.close();
    }
    void insert();
    void display();
    string search(int roll_no);
    void deleteitem();
    void modify();
};

void grey::insert() {
    file.open("hi.txt", ios::out | ios::app);
    string a;

    cout << "Enter Roll No. to insert: ";    cin >> s.rollno; 
    cout << "Enter Name to insert: "; cin >> s.name;
    cout << "Enter Division to insert: "; cin >> s.division;
    cout << "Enter Address to insert: "; cin.ignore(); getline(cin, a); s.address = a;

    file << s.rollno << "\t" << s.name << "\t" << s.division << "\t" << s.address << endl;
    file.close();
}

void grey::display() {
    file.open("hi.txt", ios::in);
    string line;
    cout << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    cout << endl;
    file.close();
}

string grey::search(int roll_no) {
    file.open("hi.txt", ios::in);
    string line;

    while (getline(file, line)) {
        stringstream str(line);
        string temp;
        string arr[4];

        for (int i = 0; i < 4; i++) {
            str >> temp;
            arr[i] = temp;
        }
        if (arr[0] == to_string(roll_no)) {
            file.close();
            return line;
        }
    }
    file.close();
    return "No item found.";
}

void grey::modify() {
    int r;
    cout << "Enter the Roll No. of the item you want to modify: ";
    cin >> r;

    tempfile.open("tempdb.txt", ios::out | ios::trunc);
    file.open("hi.txt", ios::in);
    
    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream str(line);
        string rollno;
        str >> rollno;

        if (rollno == to_string(r)) {
            found = true;
            cout << "Record found: " << line << endl;
            cout << "Enter new details:\n";
            
            cout << "Enter new Roll No.: "; cin >> s.rollno;
            cout << "Enter new Name: "; cin >> s.name;
            cout << "Enter new Division: "; cin >> s.division;
            cout << "Enter new Address: "; cin.ignore(); getline(cin, s.address);

            tempfile << s.rollno << "\t" << s.name << "\t" << s.division << "\t" << s.address << endl;
        } else {
            tempfile << line << endl;
        }
    }

    file.close();
    tempfile.close();

    if (!found) {
        cout << "No record found with Roll No: " << r << endl;
        remove("tempdb.txt");
        return;
    }

    if (remove("hi.txt") != 0) {
        cout << "Error deleting original file!" << endl;
        return;
    }

    if (rename("tempdb.txt", "hi.txt") != 0) {
        cout << "Error renaming temporary file to original file name!" << endl;
        return;
    }

    cout << "Record modified successfully." << endl;
}

void grey::deleteitem() {
    int r;
    cout << "Enter the Roll No. of the item you want to delete: ";
    cin >> r;

    tempfile.open("tempdb.txt", ios::out | ios::trunc);
    file.open("hi.txt", ios::in);
    
    string line;
    bool found = false;
    while (getline(file, line)) {
        stringstream str(line);
        string rollno;
        str >> rollno;

        if (rollno != to_string(r)) {
            tempfile << line << endl;
        } else {
            found = true;
        }
    }

    file.close();
    tempfile.close();

    if (!found) {
        cout << "No record found with Roll No: " << r << endl;
        remove("tempdb.txt");
        return;
    }

    if (remove("hi.txt") != 0) {
        cout << "Error deleting original file!" << endl;
        return;
    }

    if (rename("tempdb.txt", "hi.txt") != 0) {
        cout << "Error renaming temporary file to original file name!" << endl;
        return;
    }

    cout << "Record deleted successfully." << endl;
}

int main() {
    grey stud;

    int choice;
    bool c = true;

    while (c) {
        cout << "Enter a CHOICE \n1. Insert \n2. Display \n3. Search \n4. Modify \n5. Delete\n6. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                stud.insert();
                cout << "-------------------------------------------------------------\n";
                break;
            case 2:
                stud.display();
                cout << "-------------------------------------------------------------\n";
                break;
            case 3:
                {
                    int k;
                    cout << "\nEnter Roll No. of the item to search: ";
                    cin >> k;
                    string line = stud.search(k);
                    cout << line << endl;
                    cout << "-------------------------------------------------------------\n";
                }
                break;
            case 4:
                stud.modify();
                cout << "-------------------------------------------------------------\n";
                break;
            case 5:
                stud.deleteitem();
                break;

            case 6:
                c = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
    return 0;
}

// #include <iostream>
// #include <fstream>
// #include <string>

// using namespace std;

// class Person {
// public:
//     int roll;
//     string name;

//     void input() {
//         cout << "Enter roll no: ";
//         cin >> roll;
//         cin.ignore();  
//         cout << "Enter name: ";
//         getline(cin, name);  
//     }

//     void display() {
//         cout << "Roll no: " << roll << endl;
//         cout << "Name: " << name << endl;
//     }
// };

// int main() {
//     ofstream outfile;
//     ifstream infile;

//     int numPersons;
//     cout << "Enter the number of persons: ";
//     cin >> numPersons;

//     outfile.open("info.bin", ios::binary);
//     if (!outfile) {
//         cerr << "Error opening output file." << endl;
//         return 1;
//     }

//     for (int i = 0; i < numPersons; i++) {
//         Person p;
//         p.input();
//        outfile.write((char*)&p , sizeof(p));

//     }

//     outfile.close();

//     infile.open("info.bin", ios::binary);
//     if (!infile.is_open()) {
//         cerr << "Error opening input file." << endl;
//         return 1;
//     }

//     cout << "Reading and displaying the contents of the file:" << endl;
// while(!infile.eof()) {
//       Person p;
//         infile.read((char* )&p ,sizeof(p));\
//         if(infile.eof())break;
//         p.display();
//     }

//     infile.close();

//     return 0;
// }