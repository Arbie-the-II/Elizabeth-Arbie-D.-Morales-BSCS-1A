#include <iostream>
#include <cstring>
#include <limits>
#include <windows.h> 
#include <conio.h>
using namespace std;

struct Student{
    int id;
    string firstname;
    string lastname;
    string course;
    double gpa;
};

void addStudent(Student*& p, int& size){
    system("cls");
    do{
        int newID;
        cout<<"Enter Student ID: ";
        cin>>newID;

        int search = -1;
        for(int i=0; i<size; i++){
            if(p[i].id == newID){
                search = i;
                break;
            }
        }

        cout<< endl;
        if(search == -1){
           Student* students = new Student[size + 1];
           for(int i=0; i<size; i++){
                students[i] = p[i];
           }

           students[size].id = newID;
           cout<<"Firstname: ";
           cin>>students[size].firstname;
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
           cout<<"Lastname: ";
           cin>>students[size].lastname;
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
           cout<<"Enter Course: ";
           cin>>students[size].course;
           cin.ignore(numeric_limits<streamsize>::max(), '\n');
           cout<<"Enter GPA: ";
           cin>>students[size].gpa;

           delete[]p;
           p = students;
           size++;
           cout<<"Student added successfully.."<<endl;
           return;
        }else{
            do{
            cout<<"Student with ID "<<newID<<" already exists.\n";
            cout<<"Would you like to add a student [Y/N]?\n";
            char opt;
            cin>>opt;

            switch(tolower(opt)){
                case 'y':
                break;

                case 'n':
                return;
                break;

                default:
                if(cin.fail() || cin.peek() != '\n'){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"Invalid input. Please enter valid option.\n";
                    getch();
                    continue;
                }
            }
        }while(true);
    }
}while(true);
}

void bubbleSort(Student* p, int size, int choice){
    for(int i=0; i<size -1; i++){
        for(int j=0; j<size - i - 1; j++){
            int swap = 0;
            if(choice == 1){
                if (p[j].lastname > p[j+1].lastname){
                    swap=1;
                }
            }
                else if(choice == 2){
                    if (p[j].gpa > p[j+1].gpa){
                        swap=1;
                    }
                }
                if (swap == 1){
                    Student temp = p[j];
                    p[j]= p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }

void viewStudents(Student* p, int size){
    system("cls");
    if(size == 0){
        cout<<"No students to display." <<endl;
        return;
    }

    do{
    cout<<"[1] Alphabetically\n";
    cout<<"[2] GPA\n";
    int opt;
    cin>>opt;

    switch(opt){
        case 1:
        bubbleSort(p, size, opt);
        for(int i=0; i<size; i++){
            cout<<"===================================\n";
            cout<<"ID: "<<p[i].id<<endl;
            cout<<"Lastname: "<<p[i].lastname<<endl;
            cout<<"Firstname: "<<p[i].firstname<<endl;
            cout<<"Course: "<<p[i].course<<endl;
            cout<<"GPA: "<<p[i].gpa<<endl;
            cout<<"===================================\n";
        }
        return;
        break;

        case 2:
        bubbleSort(p, size, opt);
        for(int i=0; i<size; i++){
            cout<<"===================================\n";
            cout<<"ID: "<<p[i].id<<endl;
            cout<<"Lastname: "<<p[i].lastname<<endl;
            cout<<"Firstname: "<<p[i].firstname<<endl;
            cout<<"Course: "<<p[i].course<<endl;
            cout<<"GPA: "<<p[i].gpa<<endl;
            cout<<"===================================\n";
        }
        return;
        break;

        default:
        if(cin.fail() || cin.peek() != '\n'){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Invalid input. Please enter valid option.\n";
            getch();
            continue;
        }
    }
    }while(true);
}
    void editStudent(Student* p, int size){
        system("cls");
        if(size == 0){
            cout<<"No records yet";
            return;
        }
        else{
            for(int i=0; i<size; i++){
                cout<<"===================================\n";
                cout<<"ID: "<<p[i].id<<endl;
                cout<<"Lastname: "<<p[i].lastname<<endl;
                cout<<"Firstname: "<<p[i].firstname<<endl;
                cout<<"Course: "<<p[i].course<<endl;
                cout<<"GPA: "<<p[i].gpa<<endl;
                cout<<"===================================\n";
            }
        }
        int editP;
        cout<<"Enter the Student ID to edit: ";
        cin>>editP;
    
        for(int i=0; i<size; i++){
    
            if(p[i].id == editP){
                cout<<"\n";
                cout<<"Enter new Firstname: ";
                cin>>p[i].firstname;
                cout<<"Enter new Lastname: ";
                cin>>p[i].lastname;
                cout<<"Enter new Course: ";
                cin>>p[i].course;
                cout<<"Enter new GPA: ";
                cin>>p[i].gpa;
                cout<<"Student information updated..";
                return;
            }
        }
        cout<<"Student with ID "<<editP<<" not found. Press enter to continue."<<endl;
        return;
    }
    
    void deleteStudent(Student*& p, int& size){
        system("cls");
        if(size == 0){
            cout<<"No records yet";
            return;
        }
        else{
            for(int i=0; i<size; i++){
                cout<<"===================================\n";
                cout<<"ID: "<<p[i].id<<endl;
                cout<<"Lastname: "<<p[i].lastname<<endl;
                cout<<"Firstname: "<<p[i].firstname<<endl;
                cout<<"Course: "<<p[i].course<<endl;
                cout<<"GPA: "<<p[i].gpa<<endl;
                cout<<"===================================\n";
            }
        }
        int deleteP;
        cout<<"Enter the Student ID to delete: ";
        cin>>deleteP;
    
        int search = -1;
        for(int i=0; i<size; i++){
            if(p[i].id == deleteP){
                search= i;
                break;
            }
        }
    
        if(search == -1){
            cout<<"Student with ID "<<deleteP<<" not found."<<endl;
            return;
        }
    
        char opt;
        do{
            cout<<"Are sure you want to delete this data?[Y/N]?";
            cin>>opt;
    
            switch (tolower(opt)){
            case 'y':
                {
                    Student* temp = new Student[size - 1];
                    for(int j=0; j<search; j++){
                        temp[j] = p[j];
                    }
                    for(int j=search+1; j<size; j++){
                        temp[j-1] = p[j];
                    }
                    delete[]p;
                    p = temp;
                    size--;
                    cout<<" Student deleted successfully.."<<endl;
                    return;
                }
            case 'n':
                return;
                break;
    
            default:
                if(cin.fail() || cin.peek() != '\n'){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"Invalid input. Please enter valid option.\n";
                    getch();
                    continue;
                }
            }
        }while(tolower(opt) != 'y' || tolower(opt) != 'n');
        return;
    }

int main() {
    Student* students = nullptr; 
    int size = 0;
    int opt;

    do {
        cout << "\n\t--Menu--\n";
        cout << "[1] Add Student\n";
        cout << "[2] Edit Student\n";
        cout << "[3] Delete Student\n";
        cout << "[4] View Student\n";
        cout << "[5] Exit Program\n";
        cout << "Enter your choice: ";
        cin >> opt;

        switch (opt) {
            case 1:
                addStudent(students, size);
                break;
            case 2:
                editStudent(students, size);
                break;
            case 3:
                deleteStudent(students, size);
                break;
            case 4:
                viewStudents(students, size); 
                break;
            case 5:
                cout << "Exiting Program.\n";
                break;
            default:
            if(cin.fail() || cin.peek() != '\n'){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout<<"Invalid choice. Please try again.\n";
                getch();
                continue;
            }
        }
    } while (opt != 5);

    delete[]students; 
    return 0;
}
