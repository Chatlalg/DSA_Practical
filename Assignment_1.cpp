/*
Consider a student database of SEIT class (at least 15 records). Database contains 
different. Fields of every student like Roll No, Name and SGPA.(array of structure)  
    a. Design a roll call list, arrange list of students according to roll numbers in ascending 
    order (Use Bubble Sort) 
    b. Arrange list of students alphabetically. (Use Insertion sort)  
    c. Arrange list of students to find out first ten toppers from a class. (Use Quick sort) 
    d. Search students according to SGPA. If more than one student having same SGPA, then print list of all students having same SGPA.  
    e. Search a particular student according to name using binary search without 
    recursion.  
(All the student records having the presence of search key should be displayed) 
(Note: Implement either Bubble sort or Insertion Sort.) 
1. Any 2 sorting and 1 searching algorithm 
Minimum requirement : Reading, displaying data, one sorting algorithm, oral 
questions MUST be answered 
*/

#include <bits/stdc++.h>
#define SIZE 15
using namespace std;

struct Student{
    int rollNo;
    string name;
    float sgpa;
};

class StudentDatabase{
    Student db[SIZE] = {
    {15, "Alan", 9.2},
    {14, "Bella", 8.5},
    {13, "Charlie", 7.8},
    {12, "Diana", 9.0},
    {11, "Edward", 8.3},
    {10, "Fiona", 9.1},
    {1, "George", 7.9},
    {2, "Hannah", 8.4},
    {3, "Ian", 7.5},
    {7, "Julia", 8.7},
    {8, "Kevin", 9.0},
    {9, "Lila", 8.2},
    {10, "Mike", 7.8},
    {4, "Nina", 8.6},
    {5, "Oscar", 9.3}
};
public:

    void display(int n){
        for (int i = 0; i < n; i++) {
            cout << "Roll No: " << db[i].rollNo 
                << ", Name: " << db[i].name 
                << ", SGPA: " << db[i].sgpa << endl;
         }   
    }

    void bubbleSort(){
        for (int i = SIZE - 1; i >= 0; i--) {
            bool flag = true;
            for (int j = 0; j <= i-1 ; j++){
                if(db[j].rollNo > db[j+1].rollNo){
                    swap(db[j],db[j+1]);
                    flag = false;
                }
            }
            if(flag) break;
        }
    }

    void insertionSort(){
        for(int i = 1; i < SIZE ; i++){
            int j = i-1;
            Student temp = db[i];
            while(j>=0){
                if(temp.name.compare(db[j].name)>0)
                    break;
                db[j+1] = db[j];
                j--;
            }
            db[j+1] = temp;
        }   
    }

    int partition(int low, int high){
        int pivot = low;
        int i = low;
        int j = high;

        while(i<j){
            while(db[i].sgpa >= db[pivot].sgpa && i < high){
                i++;
            }
            while(db[j].sgpa < db[pivot].sgpa && j > low){
                j--;
            }
            if(i < j){
                swap(db[i],db[j]);
            }
        }
        swap(db[j],db[pivot]);
        return j;
    }

    void quickSort(int low, int high){
        if(low < high){
            int p = partition(low, high);
            quickSort(low, p-1);
            quickSort(p+1, high);
        }
    }

    void linearSearch(float sgpa){
        bool found = false;
        for (int i = 0; i < SIZE; i++) {
            if (db[i].sgpa == sgpa) {
                cout << "Roll No: " << db[i].rollNo 
                    << ", Name: " << db[i].name 
                    << ", SGPA: " << db[i].sgpa << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No student found with SGPA: " << sgpa << endl;
        }
    }

    void binarySearch(string name){
        int low = 0, high = SIZE - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (db[mid].name == name) {
                    cout << "Roll No: " << db[mid].rollNo 
                        << ", Name: " << db[mid].name 
                        << ", SGPA: " << db[mid].sgpa << endl;
                    return;
                }
                if (db[mid].name < name) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            cout << "Student with name " << name << " not found." << endl;
    }
};

int main(){
    cout<<"1. Display data\n2. Sort according to roll numbers\n3. Sort alphabetically.\n4. First ten toppers\n5. Search using SGPA\n6. Search using name\n7. Exit "<<endl;
    int choice;
    StudentDatabase database;
    while(true){
        cout<<"Your Choice: ";
        cin>>choice;
        if(choice < 1 || choice > 7){
            cout<<"Invalid Input! Try again!"<<endl;
        }else{
            float sgpa;
            string name;
            switch(choice){
                case 1: 
                        database.display(SIZE);
                        break;
                case 2: 
                        database.bubbleSort();
                        break;
                case 3: 
                        database.insertionSort();
                        break;
                case 4: 
                        database.quickSort(0,SIZE-1);
                        database.display(10);
                        break;
                case 5: 
                        cout<<"Enter SGPA: ";
                        cin>>sgpa;
                        database.linearSearch(sgpa);
                        break;
                case 6: 
                        cout<<"Enter name: ";
                        cin>>name;
                        database.binarySearch(name);
                        break;
                case 7: cout<<"Terminating ..."<<endl;
                        return 0;
            }
        }
    }
    return 0;
};